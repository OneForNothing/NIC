#include "statusbarwidget.h"
#include "ui_statusbarwidget.h"
#include"personlist.h"
#include"personlistbuddy.h"
#include<QPixmap>
#include<QListWidget>
#include<QSize>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QSpacerItem>
#include<QSizePolicy>
#include"tcpclientsocket.h"
#include"widget.h"
#include<QTime>
#include<QMessageBox>
#include<QDebug>
#include<QIcon>
#include<QPixmap>
#include"addgroup.h"
#include"mainwindow.h"
#include"weather.h"
#include"log.h"
#include<QTime>


statusbarwidget::statusbarwidget(int uid , QString username ,QString wi, QWidget *parent) :
    _uid(uid),
    _username(username),
    QWidget(parent),
    weatherIcon (wi),
    ui(new Ui::statusbarwidget)
{
    ui->setupUi(this);
    logSysInit("qdebug.txt");
    this->setWindowTitle("chatting list");
    QIcon windowicon(":/image-3/主标志.png");
    this->setWindowIcon(windowicon);

    this->move(1000,100);


    ui->pushButton->setFlat(true);

    //初始化天气窗口
    wea = new MainWindow();

    //wea->show();


    //设置QListWidget部件
    QListWidget *qlw = new QListWidget(this);
    qlw->hide();
    //设置背景图片
    QImage _image;
    _image.load(":/image-3/好友列表背景.jpg");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                                                        Qt::SmoothTransformation)));
    setPalette(pal);

    personList *p = new personList(qlw);
    p->setuid(_uid);
    //布局
    QVBoxLayout* layout = new QVBoxLayout;
    QSpacerItem  *verticalSpacer = new QSpacerItem(0,100);
    layout->addItem(verticalSpacer);
    layout->addWidget(p,0,Qt::AlignLeft);
    this->setLayout(layout);
    qlw->move(0,100);
    p->initGroup();//初始化分组

    //初始化窗口存在状态
    for (int i=0; i<=99;i++)
    {
        widgetExist[i]=0;
    }
    chatwidgetnumber=0;
    groupchatexist = false;

    //连接服务器的处理
    _tcpclientSocket = new TcpClientSocket(this);

    connect(_tcpclientSocket, SIGNAL(dealMessage(QMap<QString,QString>,QString)),
            this, SLOT(dealMessage(QMap<QString,QString>,QString)));//来自tcpclientsocket的信号与处理函数的连接
    connect(p,SIGNAL(requestwidget(QString,int)),this,SLOT(creatwidget(QString,int)));
    connect(this,SIGNAL(addnewuser(QString,int)),p,SLOT(addonlinefriend(QString,int)));
    connect(this,SIGNAL(addBuddy(QString,int)),p,SLOT(addbuddy(QString,int)));
    connect(p,SIGNAL(requestnewgroup()),this,SLOT(addgroupchat()));
    connect(wea,SIGNAL(weatherreport()),this,SLOT(dealweatherreport()));

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
    qDebug()<<"_uid:"<<_uid<<"---_username:"<<_username;



    //该窗口初始化的时候需要向服务器请求获取当前在线的所有人
    QMap<QString, QString> sendMsg;
    sendMsg["uid"]=QString::number(_uid, 10);
    qDebug()<<"发送D型消息，请求当前在线的所有用户。请求来自uid:"<<sendMsg["uid"];
    _tcpclientSocket->sendMessage(sendMsg, QString("D"));



    //该窗口初始化的时候意味着有用户成功登录，因此以下进行新用户上线提醒
    QMap<QString, QString> msg;

    QTime time = QTime::currentTime();
    QString strTime = time.toString("HH:mm:ss");

    msg["message"] = _username + "(" + strTime + ")";
    msg["uid"] = QString::number(_uid, 10);//传输唯一的uid
    msg["fromuser"] = _username;
    qDebug()<<"c型消息的uid传输"<<msg["uid"];

    _tcpclientSocket->sendMessage(msg,QString("C"));//发送上线请求 
}

statusbarwidget::~statusbarwidget()
{
    delete ui;
}

void statusbarwidget::dealMessage(QMap<QString, QString> msg, QString TypeOfMessage)
{
    if (TypeOfMessage == QString("C"))
    {
        qDebug()<<"好友列表接收到C型消息，即将转发消息给对应聊天窗口进行处理";
        if (widgetExist[99]== 0)
        {
            qDebug()<<"C型消息首次接收，即将初始化公共聊天室窗口";
            chatwidget[++chatwidgetnumber] = new Widget(_uid,_username);
            widgetExist[99] = chatwidgetnumber;
            chatwidget[chatwidgetnumber]->settouername(QString("公共聊天室"));
            chatwidget[chatwidgetnumber]->settouid(99);
            chatwidget[chatwidgetnumber]->settcpclientsocket(_tcpclientSocket);
            chatwidget[chatwidgetnumber]->show();
            chatwidget[chatwidgetnumber]->displayMessage(msg,TypeOfMessage);
        }
        else
        {
            chatwidget[widgetExist[99]]->displayMessage(msg,TypeOfMessage);
        }
        qDebug()<<"好友列表消息传输查证："<<msg["uid"]<<"-"<<msg["fromuser"];
        int uid =msg["uid"].toInt();
        QString username = msg["fromuser"];
        qDebug()<<"接收到新用户上线提醒，即将在“当前在线的用户”分组中以uid、username创建好友对象"<<uid<<"--"<<username;
        emit addnewuser(username,uid);

    }
    if (TypeOfMessage == QString("N"))
    {
        qDebug()<<"好友列表接收到N型消息，即将转发消息给对应聊天窗口进行处理";
        if (widgetExist[99]== 0)
        {
            qDebug()<<"N型消息首次接收，即将初始化公共聊天室窗口";
            chatwidget[++chatwidgetnumber] = new Widget(_uid,_username);
            widgetExist[99] = chatwidgetnumber;
            chatwidget[chatwidgetnumber]->settouername(QString("公共聊天室"));
            chatwidget[chatwidgetnumber]->settouid(99);
            chatwidget[chatwidgetnumber]->settcpclientsocket(_tcpclientSocket);
            chatwidget[chatwidgetnumber]->show();
            chatwidget[chatwidgetnumber]->displayMessage(msg,TypeOfMessage);
        }
        else
        {
            qDebug()<<"接收到N型消息，即将转发消息给对应聊天窗口进行处理";
            chatwidget[widgetExist[99]]->show();
            chatwidget[widgetExist[99]]->displayMessage(msg,TypeOfMessage);
        }

    }
    if (TypeOfMessage == QString("M"))
    {
        int fromuid = msg["fromuid"].toInt();
        QString fromuser = msg["fromuser"];
        qDebug()<<"好友列表接收到M型消息，即将转发消息给对应聊天窗口进行处理";
        if (widgetExist[fromuid]== 0)
        {
            qDebug()<<"M型消息,与uid为"<<fromuid<<"用户名为"<<fromuser<<"的用户首次通信，即将初始化聊天窗口";
            chatwidget[++chatwidgetnumber] = new Widget(_uid,_username);
            widgetExist[fromuid] = chatwidgetnumber;
            chatwidget[chatwidgetnumber]->settouername(fromuser);
            chatwidget[chatwidgetnumber]->settouid(fromuid);
            chatwidget[chatwidgetnumber]->settcpclientsocket(_tcpclientSocket);
            chatwidget[chatwidgetnumber]->show();
            chatwidget[chatwidgetnumber]->gettouserinfo();
            chatwidget[chatwidgetnumber]->displayMessage(msg,TypeOfMessage);
        }
        else
        {
            qDebug()<<"接收到M型消息，即将转发消息给对应聊天窗口进行处理";
            chatwidget[widgetExist[fromuid]]->show();
            chatwidget[widgetExist[fromuid]]->displayMessage(msg,TypeOfMessage);
        }

    }

    if (TypeOfMessage == QString("K"))
    {

        qDebug()<<"好友列表接收到K型消息，即将转发消息给对应聊天窗口进行处理";
        if (!groupchatexist)
        {
            qDebug()<<"K型消息,即将初始化聊天窗口";
            groupchatwidget = new Widget(_uid,_username);
            groupchatexist= true;
            groupchatwidget->settouername(QString("群聊"));
            groupchatwidget->settouid(100);
            groupchatwidget->settcpclientsocket(_tcpclientSocket);
            emit addnewuser(QString("群聊"),100);
            groupchatwidget->show();

            chatwidget[chatwidgetnumber]->displayMessage(msg,TypeOfMessage);
        }
        else
        {
            qDebug()<<"接收到K型消息，即将转发消息给对应聊天窗口进行处理";
            groupchatwidget->show();
            groupchatwidget->displayMessage(msg,TypeOfMessage);
        }

    }

    if (TypeOfMessage == QString("D"))
    {
        qDebug()<<"好友列表接收到D型消息，即将添加当前在线的用户";
        int number = msg["number"].toInt();
        qDebug()<<"D型消息中声明的在线人数："<<number;

        QString str1("user");
        QString str2("uid");

        for (int i=0; i<number ;i++)
        {
            QString struser = str1 + QString::number(i);
            QString struid  = str2 + QString::number(i);
            qDebug()<<"在线用户"<<(i+1)<<msg[struser]<<"-"<<msg[struid];
            emit addnewuser(msg[struser],msg[struid].toInt());
        }

    }
    if(TypeOfMessage == QString("S"))
    {
        qDebug()<<"好友列表接收到S型消息，即将添加好友";
        if(msg["theuid"].toInt() == -1)
        {
            QMessageBox::warning(this,"提示","没有找到该用户",QMessageBox::Ok);
        }
        else
        {
            QString thename = msg["thename"];
            int theuid = msg["theuid"].toInt();
            emit addBuddy(thename,theuid);
            qDebug()<<theuid<<";"<<thename;
        }

    }
    if(TypeOfMessage == QString("Z"))
    {
        qDebug()<<"好友列表接收到Z型消息，即将转发消息给对公共聊天窗口进行处理";
        if (widgetExist[99]== 0)
        {
            qDebug()<<"Z型消息接收，公共聊天窗口尚未初始化，即将初始化公共聊天室窗口";
            chatwidget[++chatwidgetnumber] = new Widget(_uid,_username);
            widgetExist[99] = chatwidgetnumber;
            chatwidget[chatwidgetnumber]->settouername(QString("公共聊天室"));
            chatwidget[chatwidgetnumber]->settouid(99);
            chatwidget[chatwidgetnumber]->settcpclientsocket(_tcpclientSocket);
            chatwidget[chatwidgetnumber]->show();
            chatwidget[chatwidgetnumber]->displayMessage(msg,TypeOfMessage);
        }
        else
        {
            qDebug()<<"接收到N型消息，即将转发消息给对应聊天窗口进行处理";
            chatwidget[widgetExist[99]]->show();
            chatwidget[widgetExist[99]]->displayMessage(msg,TypeOfMessage);
        }

    }

    if (TypeOfMessage == QString("Q"))
    {
        int fromuid = msg["getuid"].toInt();

        qDebug()<<"好友列表接收到Q型消息，即将转发消息给与"<<fromuid<<"聊天的窗口进行处理";
        chatwidget[widgetExist[fromuid]]->show();
        chatwidget[widgetExist[fromuid]]->displayMessage(msg,TypeOfMessage);
    }

    if (TypeOfMessage == QString("O"))
    {

        int fromuid = msg["fromuid"].toInt();
        QString fromuser = msg["fromuser"];

        qDebug()<<"好友列表接收到O型消息，即将询问是否接收文件";
        qDebug()<<"这条文件接收请求来自uid为"<<fromuid<<"的用户"<<fromuser<<",即将转发消息给对应的聊天窗口进行处理";
        if (widgetExist[fromuid]== 0)
        {
            qDebug()<<"Q型消息接收，公共聊天窗口尚未初始化，即将初始化公共聊天室窗口";
            chatwidget[++chatwidgetnumber] = new Widget(_uid,_username);
            widgetExist[fromuid] = chatwidgetnumber;
            chatwidget[chatwidgetnumber]->settouername(QString(fromuser));
            chatwidget[chatwidgetnumber]->settouid(fromuid);
            chatwidget[chatwidgetnumber]->settcpclientsocket(_tcpclientSocket);
            chatwidget[chatwidgetnumber]->show();
            chatwidget[chatwidgetnumber]->displayMessage(msg,TypeOfMessage);
        }
        else
        {
            qDebug()<<"接收到Q型消息，即将转发消息给对应聊天窗口进行处理";
            chatwidget[widgetExist[fromuid]]->show();
            chatwidget[widgetExist[fromuid]]->displayMessage(msg,TypeOfMessage);
        }
    }

}



void statusbarwidget::creatwidget(QString username, int uid)
{
    if (uid==100)
    {
        if (!groupchatexist)
        {
            groupchatwidget = new Widget(_uid,_username);
            groupchatexist= true;
            groupchatwidget->settouername(QString("群聊"));
            groupchatwidget->settouid(100);
            groupchatwidget->settcpclientsocket(_tcpclientSocket);
            groupchatwidget->show();

        }
        else
        {
            groupchatwidget->show();
        }
    }
    else
    {
        if (widgetExist[uid]== 0)
        {
            qDebug()<<"即将初始化与用户："<<username<<"uid:"<<uid<<"的聊天窗口";
            chatwidget[++chatwidgetnumber] = new Widget(_uid,_username);
            qDebug()<<"当前存在的窗口数为"<<chatwidgetnumber;
            widgetExist[uid] = chatwidgetnumber;
            chatwidget[chatwidgetnumber]->settouername(username);
            chatwidget[chatwidgetnumber]->settouid(uid);
            chatwidget[chatwidgetnumber]->settcpclientsocket(_tcpclientSocket);
            chatwidget[chatwidgetnumber]->gettouserinfo();
            chatwidget[chatwidgetnumber]->show();
        }
        else
        {
            qDebug()<<"用户："<<username<<"uid:"<<uid<<"的窗口已经存在，即将将其显示";
            chatwidget[widgetExist[uid]]->show();
        }

    }



}



QString statusbarwidget::getWeatherIcon() const
{
    return weatherIcon;
}

void statusbarwidget::setWeatherIcon(const QString &value)
{
    weatherIcon = value;
}

void statusbarwidget::sleep(int time)
{
    QTime reachTime = QTime::currentTime().addMSecs(time);
    while (QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

//显示具体天气

void statusbarwidget::on_pushButton_clicked()
{
    weatherwindow->show();

}

void statusbarwidget::addgroupchat()
{
    addgroup *chat = new addgroup(_tcpclientSocket);
    chat->setfromuid(_uid);
    chat->show();
}

void statusbarwidget::dealweatherreport()
{
    weatherwindow = new weather(wea);


    qDebug()<<"*"<<wea->today.city<<wea->today.wendu<<wea->today.shidu;
    qDebug()<<"*"<<wea->forecast[0].type<<wea->forecast[0].low<<wea->forecast[0].high;
    QPixmap pix =  QPixmap(tr(":/images/%1").arg(wea->forecast[0].type));
    ui->label->setPixmap(pix);

}



void statusbarwidget::on_pushButton_2_clicked()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int test = 0;
    QImage _image;
    test =qrand()%5;
    qDebug()<<test;
    switch(test)
    {
    case 0:
        _image.load(":/image-3/好友列表背景/背景图片1.jpg");
        break;
    case 1:
        _image.load(":/image-3/好友列表背景/背景图片2.jpg");
        break;
    case 2:
        _image.load(":/image-3/好友列表背景/背景图片33.jpg");
        break;
    case 3:
        _image.load(":/image-3/好友列表背景/背景图片44.jpg");
        break;
    case 4:
        _image.load(":/image-3/好友列表背景.jpg");
        break;
    default:break;
    }
        setAutoFillBackground(true);
        QPalette pal(palette());
        pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                                                            Qt::SmoothTransformation)));
        setPalette(pal);

}
