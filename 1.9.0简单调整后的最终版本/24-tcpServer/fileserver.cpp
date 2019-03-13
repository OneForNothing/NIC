#include "fileserver.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>

fileserver::fileserver(Ui::MainWindow *parent) :
    ui(parent)
{
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));   
}

fileserver::~fileserver()
{
    delete ui;
}

void fileserver::start()
{
    if(!tcpServer.listen(QHostAddress(QString("223.3.116.168")),6666))//IP 端口于此
    {
        qDebug() << tcpServer.errorString();
        close();
        return;
    }
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    ui->serverProgressBar->reset();
}

void fileserver::stop()
{
    tcpServer.close();
}

void fileserver::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    //关闭服务器，不再进行监听
    //tcpServer.close();
}

void fileserver::updateServerProgress()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_0);

    //如果接收到的数据小于16字节，保存到来的文件头结构
    if(bytesReceived <= sizeof(qint64)*2)
    {
        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0))
        {
            //接收数据总大小信息和文件名大小信息
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }

        if((tcpServerConnection->bytesAvailable() >=fileNameSize) && (fileNameSize != 0))
        {
            //接收文件名，并建立文件
            in >> fileName;
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "server:open file error!";
                return;
            }
        }
        else
        {
            return;
        }
    }

    //如果接收的数据小于总数据，那么写入文件
    if(bytesReceived<totalBytes)
    {
        bytesReceived+=tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->serverProgressBar->setMaximum(totalBytes);
    ui->serverProgressBar->setValue(bytesReceived);

    //接收数据完成时
    if(bytesReceived == totalBytes)
    {
        tcpServerConnection->close();
        localFile->close();
        ui->startButton->setEnabled(true);
        totalBytes = 0;
        bytesReceived = 0;
        fileNameSize = 0;
        ui->serverProgressBar->reset();
        updateServerProgress();
    }
}

void fileserver::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->serverProgressBar->reset();
    ui->startButton->setEnabled(true);
}

