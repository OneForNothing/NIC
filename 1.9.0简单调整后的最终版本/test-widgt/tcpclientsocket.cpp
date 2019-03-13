#include "tcpclientsocket.h"
#include <QDataStream>
#include <QHostAddress>
#include<QDebug>
#include"log.h"


TcpClientSocket::TcpClientSocket(QObject *parent) :
    QTcpSocket(parent)
{
    logSysInit("qdebug.txt");
    _blocksize = 0;

    connect(this, SIGNAL(readyRead()),
            this, SLOT(receiveMessage()));

}




QString TcpClientSocket::serverIp() const
{
    return _serverIp;
}

void TcpClientSocket::setServerIp(const QString &serverIp)
{
    _serverIp = serverIp;
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

    // 连接到服务器
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

    bool ret = waitForConnected();

    // 断开连接
    disconnectFromHost();

    return ret;
}


// 发送消息
void TcpClientSocket::sendMessage(QMap<QString, QString> msg, QString TypeOfMessage)
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
       qDebug()<<"The key:"<<key;
       QString tmpMsg = key+":"+msg[key];
       qDebug()<<"The tmp Msg:"<<tmpMsg;
       wStream << tmpMsg;
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
    QString TypeOfMessage;//定义消息类型变量
    // 利用tcpSocket创建字节流对象
    QDataStream rStream(this);
    rStream.setVersion(QDataStream::Qt_5_2);

    // 接收数据

    // 读取数据长度
    if (_blocksize == 0)
    {
        if (this->bytesAvailable() < (int)sizeof(_blocksize))
        {
            // 可读数据小于2字节,退出。
            return QString("a");
        }

        rStream >> _blocksize;
        qDebug()<<"声明数据长度："<<_blocksize;


    }


    // 读数据体

    int initBytes = this->bytesAvailable();   // 当前接收的可读数据
    qDebug()<<"当前可接收数据长度："<<initBytes;

    // 判断消息体是否接收结束
    if (initBytes < _blocksize)
    {
        return QString("a");
    }

    int msgSize = 0;   //  已读的数据

    //
    QMap<QString, QString> msg;
    rStream >> TypeOfMessage;
    while(msgSize < _blocksize)
    {
        QString tmpMsg;
        qDebug()<<"TypeOfMessage"<<TypeOfMessage;

        rStream >> tmpMsg;   // "Nname:lily"

        qDebug()<<"tmpMsg:"<<tmpMsg;


        int idxSpliter = tmpMsg.indexOf(":");

        qDebug()<<"Key:"<<tmpMsg.mid(0, idxSpliter)<<"\nmessage:"<<tmpMsg.mid(idxSpliter+1, tmpMsg.length() - idxSpliter);
        msg[tmpMsg.mid(0, idxSpliter)] = tmpMsg.mid(idxSpliter+1, tmpMsg.length() - idxSpliter);

        msgSize = initBytes - bytesAvailable();
    }

    // 接收完毕
    emit dealMessage(msg,TypeOfMessage);

    // 重新初始化_length，以便下一次接收
    _blocksize = 0;

    if (this->bytesAvailable() > 0)
    {
        // readMessage接收剩余的数据
        this->receiveMessage();
    }

    return TypeOfMessage;
}




