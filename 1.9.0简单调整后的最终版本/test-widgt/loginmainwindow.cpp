#include "loginmainwindow.h"
#include "ui_loginmainwindow.h"
#include<QMessageBox>
#include"tcpclientsocket.h"
#include<QDebug>
#include"widget.h"
#include <QIcon>
#include<QApplication>
#include"registermainwindow.h"
#include"statusbarwidget.h"
#include<QPixmap>
#include"newmainwindow.h"
#include"log.h"


loginMainWindow::loginMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginMainWindow)
{
    ui->setupUi(this);
    logSysInit("qdebug.txt");
    this->setWindowTitle("login");
    QIcon icon(":/image-3/主标志.png");
    this->setWindowIcon(icon);

    ui->regButton->setFlat(true);
    ui->losePwdButton->setFlat(true);
    ui->pushButton->setFlat(true);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    QPixmap pix = QPixmap(":/image-3/ZITI.png");
    ui->label->setPixmap(pix);
}

loginMainWindow::~loginMainWindow()
{
    delete ui;
}

void loginMainWindow::deelMessage(QMap<QString, QString> msg, QString TypeOfMessage)
{
    if (msg["username"]== _username)//返回的是自己的给自己的消息再处理
    {
        if (TypeOfMessage == QString("B"))
        {
           if (msg["result"] == QString("true"))
           {
                int uid =msg["uid"].toInt();
                _uid = uid;
                qDebug()<<"服务器允许登录，登录的uid为："<< uid;

                //登录窗口使命结束，中断socket，待到聊天窗口初始化时会重新连接socket
                _tcpclientSocket->abort();


                this->close();

                //新建聊天窗口变量，并传输uid
                qDebug()<<"将当前的uid:"<<uid<<"uesername:"<<_username << "传给聊天窗口";
                //Widget* w= new Widget(uid,_username);
                //w->show();
                statusbarwidget* w = new statusbarwidget(uid, _username);
                w->show();
           }
           else
           {
             qDebug()<<"用户名或者密码错误";
             QMessageBox::warning(this,"提示","用户名或密码错误",QMessageBox::Ok);
           }
       }
       else
        {

        }
    }
    else{

    }


    _tcpclientSocket->abort();//登录窗口使命结束，中断socket，待到聊天窗口初始化时会重新连接socket
}

void loginMainWindow::on_losePwdButton_clicked()
{
    QMessageBox::warning(this,"提示","请联系管理员索取密码",QMessageBox::Ok);

}



void loginMainWindow::on_enterButton_clicked()
{
    //步骤一：连接服务器
    _tcpclientSocket = new TcpClientSocket(this);

    connect(_tcpclientSocket, SIGNAL(dealMessage(QMap<QString,QString>,QString)),
            this, SLOT(deelMessage(QMap<QString,QString>,QString)));

    //窗口打开的同时连接聊天服务器
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

    //步骤二：获取当前用户输入的账号密码，向服务器发送登录请求
    QMap<QString, QString> msg;//定义数据传输变量

    QString username = ui->lineEdit->text();
    _username = username;//username后面还需要使用，故作为数据成员保留
    QString password = ui->lineEdit_2->text();

    qDebug() << "当前用户输入的账号密码是：" << username << ";" << password;

    msg["username"] = username;
    msg["password"] = password;

    _tcpclientSocket->sendMessage(msg,QString("A"));//发送消息

    //步骤三：接收服务器的登录响应，根据响应结果做出决定：
    //      1.弹出提示"用户名或密码错误"
    //      2.新建一个widget变量，进入聊天界面

    //将登录界面的账号密码清空
    ui->lineEdit->setText(QString());
    ui->lineEdit_2->setText(QString());

}

void loginMainWindow::on_regButton_clicked()
{
    this->hide();
    registerMainWindow* w = new registerMainWindow(this);
    w->show();

}


//显示二维码
void loginMainWindow::on_pushButton_clicked()
{
    newmainwindow *window = new newmainwindow();
    window->show();
}
