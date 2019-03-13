#include "addbuddy.h"
#include "ui_addbuddy.h"
#include <QDebug>
#include "tcpclientsocket.h"
#include"log.h"

Addbuddy::Addbuddy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addbuddy)
{
    ui->setupUi(this);
    logSysInit("qdebug.txt");
    this->setWindowTitle("添加好友");
    QIcon icon(":/image-3/主标志.png");
    this->setWindowIcon(icon);
}

Addbuddy::~Addbuddy()
{
    delete ui;
}

void Addbuddy::on_search_clicked()
{
    search();
}

void Addbuddy::on_quit_clicked()
{
    this->close();
}

void Addbuddy::search()
{ //步骤一：连接服务器
    _tcpclientSocket = new TcpClientSocket(this);

    QString strIp = "127.0.0.1";//服务器IP地址
    QString strPort = "8899";//端口统一为8899

    _tcpclientSocket->setServerIp(strIp);
    _tcpclientSocket->setServerPort(strPort);

    if(_tcpclientSocket->connectToServer())
    {
        qDebug()<<"服务器连接成功";
    }
    else
    {
        qDebug()<<"服务器连接失败";
    }
    //步骤二：获取要搜索的uid，向服务器发送搜索请求
    QMap<QString, QString> msg;//定义数据传输变量
    QString uid  = ui->uidsearch->text();
    qDebug()<<"当前用户输入的uid是："<<uid;
    msg["useruid"] = uid;
    msg["uid"] = QString::number(fromuid, 10);
    _tcpclientSocket->sendMessage(msg,QString("S"));//发送消息
    //_tcpclientSocket->abort();
    this->close();
}

void Addbuddy::setfromuid(int uid)
{
    fromuid = uid;
}

