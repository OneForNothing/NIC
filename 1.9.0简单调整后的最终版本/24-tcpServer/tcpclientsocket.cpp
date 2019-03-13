#include "tcpclientsocket.h"
#include <QDataStream>
#include <QHostAddress>
#include "mainwindow.h"
#include<QDebug>


extern MainWindow *mw;

TcpClientSocket::TcpClientSocket( QObject *parent , int uid) :
    QTcpSocket(parent),
    _uid(uid)
{
    _blocksize = 0;

    connect(this, SIGNAL(readyRead()),
            this, SLOT(receiveMessage()));

    connect(this, SIGNAL(dealMessage(QMap<QString,QString>,QString)),
            mw, SLOT(displayMessage(QMap<QString,QString>,QString)));


}




QString TcpClientSocket::serverIp() const
{
    return _serverIp;
}

void TcpClientSocket::setServerIp(const QString &serverIp)
{
    _serverIp = serverIp;
}

int TcpClientSocket::uid() const
{
    return _uid;
}

void TcpClientSocket::setuid(const int uid)
{
    _uid = uid;
}
QString TcpClientSocket::serverPort() const
{
    return _serverPort;
}

void TcpClientSocket::setServerPort(const QString &serverPort)
{
    _serverPort = serverPort;
}



//连接到服务器
bool TcpClientSocket::connectToServer()
{
    bool ret = true;
    abort();  // 中断当前的所有连接

    ret = testConnect();

    if (!ret)
    {
        return ret;
    }

    // 连接到服务器，通过类中存储的数据成员：ip、端口来进行连接
    this->connectToHost(QHostAddress(_serverIp), _serverPort.toInt());
    return ret;
}


// 测试连接
bool TcpClientSocket::testConnect()
{
    // 断开当前socket与主机的连接
    this->disconnectFromHost();

    // 连接到服务器
    this->connectToHost(QHostAddress(_serverIp), _serverPort.toInt());

    bool ret = waitForConnected();//返回值为布尔值，表示连接是否成功

    // 断开连接
    disconnectFromHost();

    return ret;
}


// 发送消息
void TcpClientSocket::sendMessage(QMap<QString, QString> msg,QString TypeOfMessage)
{
   QByteArray array;   // 暂存待发送的数据

   QDataStream wStream(&array, QIODevice::WriteOnly);
   wStream.setVersion(QDataStream::Qt_5_2);

   // 发送数据长度
   wStream << (quint16)0;  // 数据长度暂时定为0，预留2字节空间

   // 发送数据类型
   wStream<<TypeOfMessage;

   // 发送数据体
   // "name:lily"
   foreach (QString key, msg.keys()) {
       QString tmpMsg = msg[key];//一个可以通过key唯一对应存储数据msg[key]的数据存储工具
       wStream << tmpMsg;//相流中逐一写入遍历到的内容
   }

   // 定位0的位置，写入实际数据体大小
   wStream.device()->seek(0);
   wStream << (quint16)(array.size() - sizeof(quint16));

   // 发送
   this->write(array);

   qDebug() << "发送完毕";
}


// 接收消息
QString TcpClientSocket::receiveMessage()
{
    // 利用tcpSocket创建字节流对象
    qDebug()<<"消息接受触发";
    QDataStream rStream(this);
    rStream.setVersion(QDataStream::Qt_5_2);

    // 接收数据

    // 读取数据长度
    if (_blocksize == 0)//如果处于未初始化状态，则对这个参数进行初始化
    {
        if (this->bytesAvailable() < (int)sizeof(_blocksize))
        {
            // 可读数据小于2字节,退出。
            return QString("a");
        }

        rStream >> _blocksize;//读取声明数据长度
        qDebug()<<"声明数据长度："<<_blocksize;
    }

    // 读数据体

    int initBytes = this->bytesAvailable();   // 当前接收的可读数据
    qDebug()<<"当前可接收数据长度："<<initBytes;

    // 判断消息体是否接收结束
    if (initBytes < _blocksize)
    {
        return QString("a");
    }//当前接受的可读数据小于声明数据体大小，结束。一般是数据长度和可读数据长度不匹配造成，一般不会

    int msgSize = 0;   //  已读的数据

    //创建数据存储类对象
    QMap<QString, QString> msg;
    QString TypeOfMessage;
    rStream >>TypeOfMessage;

    while(msgSize < _blocksize)
    {
        QString tmpMsg;
        rStream >> tmpMsg;   // "name:lily"

        //TypeOfMessage=tmpMsg.mid(0,1);
        qDebug()<<"TypeOfMessage:"<<TypeOfMessage;
        qDebug()<<"Now tmpMsg:"<<tmpMsg;

        int idxSpliter = tmpMsg.indexOf(":");//返回第一个：号前的字符数"name:lily"为4

        qDebug()<<"Now key:"<<tmpMsg.mid(0, idxSpliter)<<"\nnow msg[key]:"<<tmpMsg.mid(idxSpliter+1, tmpMsg.length() - idxSpliter);

        msg[tmpMsg.mid(0, idxSpliter)] = tmpMsg.mid(idxSpliter+1, tmpMsg.length() - idxSpliter);
        //根据存储容器的特点，截取：前的字符串作为key参数，用于存储：后的数据

        msgSize = initBytes - bytesAvailable();//已读的数据等于目前读取前可读数据-读取后可读数据

    }

    if(TypeOfMessage == QString("D"))//如果是"D"型消息，则对当前的socket中的uid进行记录
    {
        qDebug()<<"接收到上线通知，即将对socket中的uid进行记录";
        _uid = msg["uid"].toInt();
        qDebug()<<"当前socket中的uid已经记录为"<< _uid;
    }



    qDebug()<<"数据接收完成";
    // 接收完毕,发送处理信息的信号请求，根据上面的connect定义，会进行展示信息的操作
    emit dealMessage(msg,QString(TypeOfMessage));

    // 重新初始化_length，以便下一次接收
    _blocksize = 0;

    if (this->bytesAvailable() > 0)
    {
        // 如果尚有可以接收的数据，则自身调用readMessage接收剩余的数据
        this->receiveMessage();
    }
    return QString("a");

}




