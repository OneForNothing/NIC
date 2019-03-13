#include "addgroup.h"
#include "ui_addgroup.h"
#include"log.h"

addgroup::addgroup(TcpClientSocket* tcpclientSocket , QWidget *parent) :
    _tcpclientSocket(tcpclientSocket),
    QDialog(parent),
    ui(new Ui::addgroup)
{
    ui->setupUi(this);
    logSysInit("qdebug.txt");
}

void addgroup::setfromuid(int fromuid)
{
    _fromuid = fromuid;
}

addgroup::~addgroup()
{
    delete ui;
}

void addgroup::on_pushButton_2_clicked()
{
    this->close();
}

void addgroup::on_pushButton_clicked()
{
    //字符处理+信息打包
    QString inviteuid = ui->lineEdit->text();
    int number=0;
    QMap<QString, QString> msg;
    while (!inviteuid.section(':',number,number).isEmpty())
    {
        QString str = QString("uid") + QString::number(number);
        msg[str] = inviteuid.section(':',number,number);
        qDebug()<<inviteuid.section(':',number,number);
        number++;
    }
    qDebug()<<"number:"<<number;

    msg["fromuid"] = QString::number(_fromuid);
    msg["number"] = QString::number(number);
    _tcpclientSocket->sendMessage(msg,QString("J"));
    this->close();

}
