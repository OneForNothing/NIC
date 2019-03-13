#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include"fileserver.h"
#include<QDebug>
#include<QTime>
#include<QApplication>
#include"database.h"
#include"showcpumemory.h"
#include"filesender.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _fileserver(ui)
{
    ui->setupUi(this);
    for(int i=0 ; i<10;i++)
    {
        groupchatuid[i]=0;
    }
}

void MainWindow::sleep(int time)
{
    QTime reachTime = QTime::currentTime().addMSecs(time);
    while (QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()//点击启动服务器按钮
{

    // 获取服务器对象
    Server* s = Common::getServerInstance();//利用单例化的类Common,获取目前唯一的服务器对象
    int port = ui->portLineEdit->text().toInt();

    s->start(port);//server类中提供的服务器启用函数
    _fileserver.start();//开启文件接收服务器

    // 界面处理，点启动以后启动键就不能使用，停止键可以使用
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}


// 停止
void MainWindow::on_stopButton_clicked()//点击停止服务器按钮
{
    // 获取服务器对象
    Server* s = Common::getServerInstance();//利用单例化的类Common,获取目前唯一的服务器对象
    s->stop();//server类中提供的服务器停用函数
    _fileserver.stop();//关闭文件接收服务器

    Database* db = Database::getInstance();
    db->outlineState();//关闭服务器的时候把所有用户的在线状态改为离线

    // 界面处理，点停止以后停止键就不能使用，启动键可以使用
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);

}


// 发送
void MainWindow::on_sendButton_clicked()//点击消息发送按钮
{
    // 获取服务器对象
    Server* s = Common::getServerInstance();//利用单例化的类Common,获取目前唯一的服务器对象

    // 获取socket
    QList<TcpClientSocket*> clients = s->getClients();//获取目前连接的socket

    foreach(TcpClientSocket* c, clients)//遍历目前所有的socket
    {
        QMap<QString, QString> msg;
        QTime time = QTime::currentTime();
        QString strTime = time.toString("HH:mm:ss");
        msg["server"] = "server(" + strTime + "):" + ui->sendLineEdit->text();//存储容器以“server”作为key对目前sendLineEdit数据进行存储

        // 发送
        c->sendMessage(msg,QString("I"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
    }

}

void MainWindow::resetFileSever()
{
    _fileserver.start();//开启文件接收服务器
}


void MainWindow::displayMessage(QMap<QString, QString> msg, QString TypeOfMessage)//服务器接收到的消息并进行响应均在此
{
    qDebug()<<"服务器即将对接收到的"<<TypeOfMessage<<"型消息进行响应";
    message = msg.keys().at(0) + ":" + msg.values().at(0);//利用存储容器获取信息进行展示
    qDebug()<<"Now key:"<<msg.keys().at(0)<<"\n存储内容为:"<<msg.values().at(0)<<"\n"<<message;

    // 显示
    ui->revLineEdit->setText(message);

    // 服务器广播回复
    // 获取服务器对象
    Server* s = Common::getServerInstance();//利用单例化的类Common,获取目前唯一的服务器对象

    // 获取socket
    QList<TcpClientSocket*> clients = s->getClients();//获取目前连接的socket,即获取存有当前连接的socket的表

    if (TypeOfMessage == QString("A"))//A型消息，进行登录响应
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";

        // 验证用户名密码， 并取得这个用户的个人信息
        Database* db = Database::getInstance();
        qDebug()<<"A型消息正在处理，即将以账号密码："<<msg["username"]<< "----"<<msg["password"]<<"进行登录查证";
        DBUser userinfo = db->getUserInfo(msg["username"], msg["password"]);//服务器是根据用户名和密码搜索该用户是否存在的
        QMap<QString, QString> sendMsg;

        // 验证失败，返回失败信息
        if (userinfo.uid == -1) {
            sendMsg["result"] = QString("result:false");
            QString str3("username:");
            QString str4 = msg["username"];
            sendMsg["username"] = str3 + str4;
            qDebug()<<"A型消息响应结果：验证失败";
        }
        else
        {
            sendMsg["result"] = QString("result:true");
            QString str1("uid:");
            QString str2 = QString::number(userinfo.uid,10);
            sendMsg["uid"] = str1 + str2;
            QString str3("username:");
            QString str4 = msg["username"];
            sendMsg["username"] = str3 + str4;
            qDebug()<<"A型消息响应结果：验证成功。\n服务器提供的uid为："<<sendMsg["uid"]<<"\n服务器提供的用户名为："<<sendMsg["username"];
        }

        // 通知其他客户端，有新用户上线**此流程有所变化，因此需要等待客户端发送群发上线的请求并传输uid
        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket，实际情况下只能发给特定的请求登录的用户，要处理一下
        {
            c->sendMessage(sendMsg,QString("B"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
        }

    }

    if (TypeOfMessage == QString("E"))//E型消息，进行注册响应
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";

        DBUser userinfo;
        Database* db = Database::getInstance();
        userinfo.name = msg["username"];
        userinfo.pwd = msg["password"];
        userinfo.uid = db->getMaxUid() + 1;
        userinfo.age=msg["age"].toInt();
        userinfo.sex=msg["sex"].toInt();
        userinfo.sign=msg["sign"];
        qDebug()<<"E型消息正在处理，即将将name、pwd、uid"<<userinfo.name<<"--"<<userinfo.pwd<<"--"<<userinfo.uid;
        qDebug() << "sex、age、sign：" << userinfo.sex << ";" << userinfo.age<< ";" <<userinfo.sign<<"插入数据库";

        // 插入到数据库
        db->insertIntoUser(userinfo);

        // 反馈注册成功消息
        QMap<QString, QString> sendMsg;
        sendMsg["result"] = QString("result:true");
        QString str3("username:");
        QString str4 = msg["username"];
        sendMsg["username"] = str3 + str4;
        QString str5("uid:");
        QString str6 = QString::number(userinfo.uid);
        sendMsg["uid"] = str5 + str6;

        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket，实际情况下只能发给特定的uid用户，要处理一下***BUG***
        {
            // 发送
            c->sendMessage(sendMsg,QString("F"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
        }
    }

    if (TypeOfMessage == QString("N"))//N型消息，进行消息群发
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket，实际情况下只能发给特定的uid用户，要处理一下**
        {
             QMap<QString, QString> sendMsg;
             sendMsg["message"] = QString("message:") + msg["message"];//存储容器以“reply”作为key对目前sendLineEdit数据进行存储

                // 发送
                c->sendMessage(sendMsg,QString("N"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
        }
    }

    if (TypeOfMessage == QString("C"))//C型消息，群发上线提醒
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        qDebug()<<"服务器端C型消息响应查证"<<msg["message"]<<"-"<<msg["uid"]<<"-"<<msg["fromuser"];

        Database* db = Database::getInstance();
        int userid =msg["uid"].toInt();
        db->onlineState(userid);
        qDebug()<<"已经在数据库中更新"<<userid<<"的在线状态";


        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket，实际情况下只能发给特定的uid用户，要处理一下**
        {
             QMap<QString, QString> sendMsg;
             sendMsg["message"]=QString("message:") + msg["message"];
             sendMsg["uid"]=QString("uid:") +msg["uid"];
             sendMsg["fromuser"]=QString("fromuser:") +msg["fromuser"];
             //sendMsg[msg.keys().at(0)] = message;//存储容器以“reply”作为key对目前sendLineEdit数据进行存储
             qDebug()<<"服务器端的uid"<<msg["uid"];
             // 发送
             c->sendMessage(sendMsg,QString("C"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
        }
    }

    if (TypeOfMessage == QString("M"))//M型消息，将消息发给特定的用户
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int touid = msg["touid"].toInt();
        qDebug()<<"这条私聊消息发给uid为："<<touid<<"的用户";
        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket，实际情况下只能发给特定的uid用户，要处理一下**
        {
             if (c->uid()== touid)
             {
                //仅发给特定的touid
                QMap<QString, QString> sendMsg;
                QString str1 = QString("fromuid:");
                sendMsg["fromuid"] = str1 + msg["fromuid"];
                QString str2 = QString("fromuser:");
                sendMsg["fromuser"] = str2 + msg["fromuser"];
                //****下面这一句可能会出问题
                sendMsg["message"] =QString("message:") + msg["message"];//存储容器以“reply”作为key对目前sendLineEdit数据进行存储
                // 发送
                c->sendMessage(sendMsg,QString("M"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
             }
        }

    }

    if (TypeOfMessage == QString("D"))//D型消息，群发上线提醒
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int touid = msg["uid"].toInt();

        QVector<DBUser> onlineusers;

        Database* db = Database::getInstance();
        db->queryUsersWithIsonline(onlineusers);

        foreach(DBUser d , onlineusers)
        {
            qDebug()<<d.uid<<d.name<<d.pwd;
        }


        int sizeofonlineusers = onlineusers.size();
        qDebug()<<"当前查询到的在线人数为"<<sizeofonlineusers;

        QString str1("user");
        QString str2("uid");
        QMap<QString, QString> sendMsg;
        sendMsg["number"]=QString("number:") + QString::number(sizeofonlineusers);
        for (int i=0; i<sizeofonlineusers ;i++)
        {
            QString struser = str1 + QString::number(i);
            QString struid  = str2 + QString::number(i);

            sendMsg[struser]=struser + QString(":") +  onlineusers[i].name;
            sendMsg[struid] =struid + QString(":") + QString::number(onlineusers[i].uid);
        }




        foreach(TcpClientSocket* c, clients)
        {
            if(touid == c->uid())
            {
                c->sendMessage(sendMsg,QString("D"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
            }
        }
    }

    if(TypeOfMessage == QString("S"))//S型消息，查找好友并将消息发给用户
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int touid = msg["uid"].toInt();
        Database* db = Database::getInstance();
        DBUser user = db->queryUsersWithID(msg["useruid"].toInt());
        qDebug()<<"这条好友添加消息发给uid为："<<touid<<"的用户";
        qDebug()<<"查询到的好友为"<<user.name<<":"<<msg["useruid"];
        QMap<QString, QString> sendMsg;
        sendMsg["theuid"] = QString("theuid:")+msg["useruid"];
        sendMsg["thename"] = QString("thename:")+user.name;
        foreach(TcpClientSocket* c,clients)
        {
            if(c->uid()== touid)
            {
                c->sendMessage(sendMsg,QString("S"));
            }
        }
    }

    if(TypeOfMessage == QString("Z"))//Z型消息，请求服务器运行状态
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int requestuid = msg["requestuid"].toInt();

        qDebug()<<"uid为："<<requestuid<<"的用户请求查询服务器运行状态";

        ShowCPUMemory *showCPUMemory = new ShowCPUMemory();

        sleep(2000);

        int cpup = showCPUMemory->getcpupercent();
        int memp = showCPUMemory->getmemorypercent();
        int memu = showCPUMemory->getmemoryuse();
        int mema = showCPUMemory->getmemoryall();
        qDebug()<<"服务器运行状态查询结果为cpup:内存P:内存U:内存A"
                <<cpup<<":"<<memp<<":"<<memu<<":"<<mema;

        QMap<QString, QString> sendMsg;
        sendMsg["cpup"] = QString("cpup:")+QString::number(cpup);
        sendMsg["memp"] = QString("memp:")+QString::number(memp);
        sendMsg["memu"] = QString("memu:")+QString::number(memu);
        sendMsg["mema"] = QString("mema:")+QString::number(mema);
        foreach(TcpClientSocket* c,clients)
        {
            if(c->uid()== requestuid)
            {
                c->sendMessage(sendMsg,QString("Z"));
            }
        }
    }

    if(TypeOfMessage == QString("Q"))//Q型消息，获取私聊对象的信息
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int touid = msg["requestuid"].toInt();
        Database* db = Database::getInstance();
        DBUser user = db->queryUsersWithID(msg["getuid"].toInt());

        qDebug()<<"这条Q型消息由uid为："<<touid<<"的用户发起";

        qDebug()<<"查询到的好友为"<<user.name<<":"<<user.uid;

        QMap<QString, QString> sendMsg;
        sendMsg["getuid"] = QString("getuid:") + QString::number(user.uid);
        sendMsg["age"] = QString("age:")+QString::number(user.age);
        sendMsg["sex"] = QString("sex:")+QString::number(user.sex);
        sendMsg["sign"] = QString("sign:") + user.sign;

        foreach(TcpClientSocket* c,clients)
        {
            if(c->uid()== touid)
            {
                c->sendMessage(sendMsg,QString("Q"));
            }
        }
    }

    if(TypeOfMessage == QString("O"))//O型消息，私聊文件传输请求
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int touid = msg["touid"].toInt();
        int fromuid = msg["fromuid"].toInt();
        QString fromuser = msg["fromuser"];
        QString filename = msg["nameoffile"];

        qDebug()<<"这条文件传输请求由uid为："<<fromuid<<"的用户"<<fromuser<<"发起";

        qDebug()<<"即将发送为uid为"<<touid<<"的用户"<<"\n文件名为:"<<filename;

        QMap<QString, QString> sendMsg;
        sendMsg["fromuid"] = QString("fromuid:") + QString::number(fromuid);
        sendMsg["fromuser"] = QString("fromuser:") + fromuser;
        sendMsg["filename"] = QString("filename:")+filename;

        if (touid != 99)
        {
            foreach(TcpClientSocket* c,clients)
            {
                if(c->uid()== touid)
                {
                    c->sendMessage(sendMsg,QString("O"));
                }
            }
        }
        else
        {
            foreach(TcpClientSocket* c,clients)
            {
                    c->sendMessage(sendMsg,QString("O"));
            }
        }

    }

    if(TypeOfMessage == QString("P"))//P型消息，私聊文件传输请求的反馈结果
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";

        QString IP = msg["IP"];
        QString filename = msg["filename"];

        qDebug()<<"IP为："<<IP<<"的用户已经同意接收名为:"<<filename<<"的文件";

        //IP = QString("127.0.0.1");//为了测试，此处将IP设为127.0.0.1，部署到局域网时应注释这一句话
        filesender *sender = new filesender(IP,filename);
        sender->exec();
        delete sender;


    }

    if(TypeOfMessage == QString("J"))//J型消息，存储群聊信息
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";

        groupchatnumber = msg["number"].toInt();

        for (int i=0;i<groupchatnumber;i++)
        {
            QString str = QString("uid") + QString::number(i);
            groupchatuid[i]=msg[str].toInt();
            qDebug()<<"groupchatuid["<<i<<"]="<<groupchatuid[i];
        }
        groupchatuid[groupchatnumber] = msg["fromuid"].toInt();
        qDebug()<<"groupchatuid["<<groupchatnumber<<"]="<<groupchatuid[groupchatnumber];
        groupchatnumber++;
    }

    if(TypeOfMessage == QString("K"))//K型消息，处理特定的群聊消息
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";

        QMap<QString, QString> sendMsg;
        sendMsg["message"] = QString("message:") + msg["message"];
        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket，实际情况下只能发给特定的uid用户，要处理一下**
        {
            for(int i= 0; i<groupchatnumber;i++)
            {
             if (c->uid()== groupchatuid[i])
             {
                // 发送
                c->sendMessage(sendMsg,QString("K"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
             }
            }
        }

    }

    if(TypeOfMessage == QString("L"))//L型消息，群聊文件传输请求
    {
        qDebug()<<"服务器进行"<<TypeOfMessage<<"型消息处理";
        int fromuid = msg["fromuid"].toInt();
        QString fromuser = msg["fromuser"];
        QString filename = msg["nameoffile"];

        qDebug()<<"这条群聊文件传输请求由uid为："<<fromuid<<"的用户"<<fromuser<<"发起";

        qDebug()<<"文件名为:"<<filename;

        QMap<QString, QString> sendMsg;
        sendMsg["fromuid"] = QString("fromuid:") + QString::number(fromuid);
        sendMsg["fromuser"] = QString("fromuser:") + fromuser;
        sendMsg["filename"] = QString("filename:")+filename;

        foreach(TcpClientSocket* c, clients)//遍历目前所有的socket
        {
            for(int i= 0; i<groupchatnumber;i++)
            {
             if (c->uid()== groupchatuid[i])
             {
                // 发送
                c->sendMessage(sendMsg,QString("O"));//利用TcpClientSocket类中提供的sendMessage函数发送消息
             }
            }
        }
    }
}




