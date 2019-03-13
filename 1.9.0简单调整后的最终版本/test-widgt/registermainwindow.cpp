#include "registermainwindow.h"
#include "ui_registermainwindow.h"
#include<QMessageBox>
#include"tcpclientsocket.h"
#include<QDebug>
#include <QIcon>
#include<QApplication>
#include <QPixmap>
#include"loginmainwindow.h"
#include "pixmap.h"
#include"log.h"

registerMainWindow::registerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registerMainWindow)
{
    ui->setupUi(this);
    logSysInit("qdebug.txt");
    this->setWindowTitle("register");
    QIcon icon(":/image-3/主标志.png");
    this->setWindowIcon(icon);

    QPixmap pix(":/image-3/暂用头像.jpg");
    ui->pixLabel->setPixmap(PixmapToRound(pix,90));   //将头像设置成圆形



    ui->pushButton->setFlat(true);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);

    this->setWindowFlags(this->windowFlags()/*&~Qt::WindowMaximizeButtonHint*/&~Qt::WindowMinimizeButtonHint);
    setFixedSize(789, 587);
}

registerMainWindow::~registerMainWindow()
{
    delete ui;
}

void registerMainWindow::deelMessage(QMap<QString, QString> msg, QString TypeOfMessage)
{
    if (msg["username"]== _username)//返回的是自己的给自己的消息再处理
    {
        if (TypeOfMessage == QString("F"))
        {

           if (msg["result"] == QString("true"))
           {
                int uid =msg["uid"].toInt();
                qDebug()<<"服务器允许注册，注册的uid为："<< uid;

                //登录窗口使命结束，中断socket，待到聊天窗口初始化时会重新连接socket
                _tcpclientSocket->abort();
                this->close();

                //新建聊天窗口变量，并传输uid
                qDebug()<<"当前的uid:"<<uid<<"uesername:"<<_username;
                QMessageBox::warning(this,"提示","注册成功！",QMessageBox::Ok);
                loginMainWindow * w= new loginMainWindow;
                w->show();
            }
            else
            {
                QMessageBox::warning(this,"提示","注册失败,请尝试更换用户名再次进行注册",QMessageBox::Ok);
            }
        }
    }

    _tcpclientSocket->abort();//登录窗口使命结束，中断socket，待到聊天窗口初始化时会重新连接socket
}



void registerMainWindow::on_pushButton_clicked()
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
    _username = username;

    QString password1 = ui->lineEdit_2->text();
    QString password2 = ui->lineEdit_3->text();
    msg["username"] = username;
    if (password1 == password2)
    {
        msg["password"] = password1;
    }
    else
    {
        QMessageBox::warning(this,"提示","两次输入的密码不一致",QMessageBox::Ok);
        loginMainWindow * w= new loginMainWindow;
        this->close();
        w->show();
        return;
    }
    if (ui->radioButton->isChecked())
    {
        msg["sex"]="1";
    }
    else
    {
        msg["sex"]="0";
    }
    msg["age"]=ui->lineEdit_4->text();
    msg["sign"]=ui->textEdit->toPlainText();

    qDebug() << "当前用户注册的账号密码是：" << username << ";" << password1;
    qDebug() << "sex、age、sign：" << msg["sex"] << ";" << msg["age"]<< ";" <<msg["sign"];


    _tcpclientSocket->sendMessage(msg,QString("E"));//发送消息

    //步骤三：接收服务器的登录响应，根据响应结果做出决定：
    //      1.弹出提示"用户名或密码错误"
    //      2.新建一个widget变量，进入聊天界面

    //将注册界面的账号密码清空
    ui->lineEdit->setText(QString());
    ui->lineEdit_2->setText(QString());
    ui->lineEdit_3->setText(QString());


}
