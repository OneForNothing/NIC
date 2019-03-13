#include "widget.h"
#include "ui_widget.h"
#include"tcpclientsocket.h"
#include "client.h"
#include<QTime>
#include<QDebug>
#include<QMessageBox>
#include<QtNetwork>
#include"filereceiver.h"
#include<QSound>
#include<QFont>
#include"log.h"
#include<QFileDialog>

QImage _image(":/image-3/注册背景.jpg");
//设置背景图片可适化
void Widget::resizeEvent(QResizeEvent *event)

{
    QWidget::resizeEvent(event);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image.scaled(event->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}

bool Widget::saveFile(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("保存文件"),
                             tr("无法保存文件 %1:\n %2").arg(filename).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<ui->plainTextEdit->toPlainText();
    return true;
}


Widget::Widget(int uid , QString username , QWidget *parent) :
    _uid(uid),
    _username(username),
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    logSysInit("qdebug.txt");

    niming=false;

    QFont font =ui->fontComboBox->currentFont();
    int value = ui->spinBox->value();
    font.setPointSize(value);
    ui->lineEdit->setFont(font);

    this->setWindowTitle("chatting");
    QIcon icon(":/image-3/主标志.png");
    this->setWindowIcon(icon);
    //设置背景图片
    QImage _image;
    _image.load(":/image-3/聊天背景.jpg");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(_image.scaled(size(), Qt::IgnoreAspectRatio,
                                                        Qt::SmoothTransformation)));
    setPalette(pal);
    ui->label->setText(_tousername);//设置聊天名称
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_SendPushButton_clicked()));
}

void Widget::settouid(int touid)
{
    _touid=touid;
}

int Widget::gettouid()
{
    return _touid;
}

void Widget::settouername(QString tousername)
{
    _tousername=tousername;
}

QString Widget::gettousername()
{
    return _tousername;
}

void Widget::settcpclientsocket(TcpClientSocket *tcpclientSocket)
{
    _tcpclientSocket=tcpclientSocket;
}

void Widget::gettouserinfo()//获取私聊对象的个人信息,写成函数可以根据需要调用
{

    QMap<QString, QString> msg;

    qDebug()<<"widget请求获得uid为"<<_touid<<"用户的个人信息";
    msg["requestuid"] = QString::number(_uid);
    msg["getuid"] = QString::number(_touid);

    _tcpclientSocket->sendMessage(msg,QString("Q"));//请求获得对方个人信息是Q型消息
}


Widget::~Widget()
{
    delete ui;
}

//显示操作
void Widget::displayMessage(QMap<QString, QString> msg,QString TypeOfMessage)
{
    ui->label->setText(_tousername);//设置聊天名称

    if (TypeOfMessage == QString("N"))
    {
        qDebug()<<"nnnnxingxiaoxi";
        QSound::play("../test-widgt/sound/8906.wav");
        QString str1 = msg["message"];
        QString str2 = ui->plainTextEdit->toPlainText();//textBrowser->placeholderText();
        QString str3 ="\n";
        QString str4 =str2 + str3;
        str4 = str4 + str1;
        ui->plainTextEdit->setPlainText(str4);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
    }

    if ( TypeOfMessage == QString("M"))
    {
        QString str1 = msg["message"];
        QString str2 = ui->plainTextEdit->toPlainText();//textBrowser->placeholderText();
        QString str3 ="\n";
        QString str4 =str2 + str3;
        str4 = str4 + str1;
        ui->plainTextEdit->setPlainText(str4);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
    }

    if (TypeOfMessage == QString("K"))
    {
        QSound::play("../test-widgt/sound/8906.wav");
        QString str1 = msg["message"];
        QString str2 = ui->plainTextEdit->toPlainText();//textBrowser->placeholderText();
        QString str3 ="\n";
        QString str4 =str2 + str3;
        str4 = str4 + str1;
        ui->plainTextEdit->setPlainText(str4);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
    }

    if (TypeOfMessage == QString("C"))//C型消息，上线消息提醒
    {
        QSound::play("../test-widgt/sound/6000.wav");
        QString str1 = msg["message"];
        QString str2 = ui->plainTextEdit->toPlainText();
        QString str3 ="\n[上线提醒]";
        QString str4 =str2 + str3;
        str4 = str4 + str1;
        ui->plainTextEdit->setPlainText(str4);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
    }

    if (TypeOfMessage == QString("Z"))//Z型消息，服务器运行状态查询结果
    {
        QString str1 = QString("服务器运行状态 ：正常\nCPU占用率 : %1%\n内存占用率 : %2%\n已用内存 : %3 MB\n总内存 : %4 MB")
                .arg(msg["cpup"]).arg(msg["memp"]).arg(msg["memu"]).arg(msg["mema"]);

        QString str2 = ui->plainTextEdit->toPlainText();
        QString str3 ="\n服务器运行状态查询结果：\n";
        QString str4 =str2 + str3;
        str4 = str4 + str1;
        ui->plainTextEdit->setPlainText(str4);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
    }

    if (TypeOfMessage == QString("Q"))//Q型消息，处理私聊对象的信息
    {
        QSound::play("../test-widgt/sound/8906.wav");
        qDebug()<<"聊天窗口接收到Q型消息";
        QString setname = QString("昵称:") + _tousername;
        QString setuid =  QString("uid:") + QString::number(_touid);
        QString setsex;
        QString setage = QString("年龄:") + msg["age"];
        QString setsign = msg["sign"];
        if (msg["sex"] == QString::number(1))
            setsex=QString("性别:男");
        else
            setsex=QString("性别:女");
        ui->label_3->setText(setname);
        ui->label_4->setText(setuid);
        ui->label_5->setText(setsex);
        ui->label_6->setText(setage);
        ui->plainTextEdit_2->setPlainText(setsign);
    }

    if (TypeOfMessage == QString("O"))//O型消息，提示是否接收文件，根据提示结果反馈结果
    {
        QSound::play("../test-widgt/sound/8906.wav");
        qDebug()<<"聊天窗口接收到O型消息";
        QString fromuid = msg["fromuid"];
        QString filename = msg["filename"];
        QString remind = QString("是否同意接收对方传输的文件:") + filename;
        QMessageBox message(QMessageBox::NoIcon, "文件传输", remind, QMessageBox::Yes | QMessageBox::No, NULL);
        if(message.exec() == QMessageBox::Yes)
        {
            QString localHostName = QHostInfo::localHostName();
            qDebug() <<"localHostName: "<<localHostName;
            QHostInfo info = QHostInfo::fromName(localHostName);
            qDebug() <<"IP Address: "<<info.addresses();
            QString IP;
            foreach(QHostAddress address,info.addresses())
            {
                 if(address.protocol() == QAbstractSocket::IPv4Protocol)
                 {
                     IP = address.toString();
                     qDebug() << IP;
                 }
            }
            //保留上面这一段输出是为了方便确认是客户端是否获取了正确的IP地址
            //单机测试的时候，由于有虚拟机等的IP地址，会导致找到多个IP地址，实际调试的时候务必确认这个IP是否正确
            QMap<QString, QString> sendMsg;

            sendMsg["result"] = QString("true");
            sendMsg["IP"] = IP;
            sendMsg["filename"] = filename;

            _tcpclientSocket->sendMessage(sendMsg,QString("P"));

           // IP = QString("127.0.0.1");//为了测试，此处将IP设为127.0.0.1，部署到局域网时应注释这一句话
            filereceiver *receiver = new filereceiver(IP);
            receiver->exec();
            delete receiver;
        }
        else
        {
            ui->lineEdit->setText(QString("我拒绝了您的文件传输请求"));
            on_SendPushButton_clicked();
            ui->lineEdit->setText(QString());
        }
    }


}


void Widget::on_pushButton_clicked()
{
    Client sendfile;
    sendfile.exec();

    qDebug()<<sendfile.getnameoffile();
    if(_touid !=100)
    {
        QMap<QString, QString> msg;

        msg["fromuid"] = QString::number(_uid);
        msg["fromuser"] = _username;
        msg["touid"] =QString::number(_touid);
        msg["nameoffile"] = sendfile.getnameoffile();

        _tcpclientSocket->sendMessage(msg,QString("O"));
    }
    else
    {

        QMap<QString, QString> msg;

        msg["fromuid"] = QString::number(_uid);
        msg["fromuser"] = _username;
        msg["nameoffile"] = sendfile.getnameoffile();

        _tcpclientSocket->sendMessage(msg,QString("L"));

    }



}

void Widget::on_SendPushButton_clicked()
{
    if (_touid == 99)
    {
        if(ui->lineEdit->text() == QString("SERVER"))
        {
            //要求获取服务器运行状态
            QMap<QString, QString> msg;
            msg["requestuid"] = QString::number(_uid);
            _tcpclientSocket->sendMessage(msg,QString("Z"));
            ui->lineEdit->setText(QString());
        }
        else
        {
            //此时为公共聊天室，且不要求获取服务器状态发送"N"型消息
            QMap<QString, QString> msg;

            QTime time = QTime::currentTime();
            QString strTime = time.toString("HH:mm:ss");

            qDebug()<<"The key of msg:"<<_username;
            if (niming)
            {
                msg["message"] = QString("匿名消息") + "(" + strTime + "):" + ui->lineEdit->text();
            }
            else
            {
                msg["message"] = _username + "(" + strTime + "):" + ui->lineEdit->text();
            }


            _tcpclientSocket->sendMessage(msg,QString("N"));
            ui->lineEdit->setText(QString());
        }
    }
    else
    {
        if (_touid == 100)
        {
            //为群聊模式
            QMap<QString, QString> msg;

            QTime time = QTime::currentTime();
            QString strTime = time.toString("HH:mm:ss");
            msg["message"] =_username +  "(" + strTime + "):" + ui->lineEdit->text();
            _tcpclientSocket->sendMessage(msg,QString("K"));
            ui->lineEdit->setText(QString());

        }
        else
        {
            //否则为私聊模式
            QMap<QString, QString> msg;

            QTime time = QTime::currentTime();
            QString strTime = time.toString("HH:mm:ss");
            msg["message"] =_username +  "(" + strTime + "):" + ui->lineEdit->text();
            msg["touid"] = QString::number(_touid);
            msg["fromuid"] = QString::number(_uid);
            msg["fromuser"] = _username;

            _tcpclientSocket->sendMessage(msg,QString("M"));
            QString str1 = _username + "(" + strTime + "):" + ui->lineEdit->text();
            QString str2 = ui->plainTextEdit->toPlainText();//textBrowser->placeholderText();
            QString str3 ="\n";
            QString str4 =str2 + str3;
            str4 = str4 + str1;
            ui->plainTextEdit->setPlainText(str4);
            ui->plainTextEdit->moveCursor(QTextCursor::End);
            ui->lineEdit->setText(QString());
        }

    }

}

void Widget::on_pushButton_2_clicked()
{
    if (niming)
    {
        niming=false;
//        ui->pu
        ui->pushButton_2->setText("匿名");
    }
    else
    {
        niming=true;
        ui->pushButton_2->setText("取消匿名");
    }
}

void Widget::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->lineEdit->setFont(f);
    ui->plainTextEdit->setFont(f);
}



void Widget::on_spinBox_valueChanged(const QString &arg1)
{
    QFont font;
    font.setPointSize(arg1.toInt());
    ui->lineEdit->setFont(font);
    ui->plainTextEdit->setFont(font);
}

void Widget::on_pushButton_4_clicked()
{
    if(ui->plainTextEdit->document()->isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),tr("聊天记录为空，无法保存！"),QMessageBox::Ok);
    }
    else
    {
        QString filename = QFileDialog::getSaveFileName(this,tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;All File(*.*)"));
        if(!filename.isEmpty())
            saveFile(filename);
    }
}
