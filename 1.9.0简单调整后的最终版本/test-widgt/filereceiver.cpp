#include "filereceiver.h"
#include "ui_filereceiver.h"
#include <QtNetwork>
#include <QDebug>
#include"log.h"

filereceiver::filereceiver(QString IP , QWidget *parent) :
    _IP(IP),
    QDialog(parent),
    ui(new Ui::filereceiver)
{
    logSysInit("qdebug.txt");
    qDebug()<<"文件接收器当前监听的IP为:"<<_IP;
    ui->setupUi(this);
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    start();
}

filereceiver::~filereceiver()
{
    delete ui;
}

void filereceiver::start()
{
    if(!tcpServer.listen(QHostAddress(_IP),6667))//服务器文件下发用6667端口
    {
        qDebug() << tcpServer.errorString();
        close();
        return;
    }
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    ui->label->setText(tr("监听"));
    ui->progressBar->reset();
}

void filereceiver::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    ui->label->setText(tr("接受连接"));
    //关闭服务器，不再进行监听
    tcpServer.close();

}

void filereceiver::updateServerProgress()
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
            ui->label->setText(tr("接收文件 %1...").arg(fileName));
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
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesReceived);

    //接收数据完成时
    if(bytesReceived == totalBytes)
    {
        tcpServerConnection->close();
        localFile->close();
        ui->label->setText(tr("接收文件 %1 成功！").arg(fileName));
        this->close();
    }

}

void filereceiver::displayError(QAbstractSocket::SocketError socketError)
{

    qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->progressBar->reset();
    ui->label->setText(tr("服务器就绪"));
}





