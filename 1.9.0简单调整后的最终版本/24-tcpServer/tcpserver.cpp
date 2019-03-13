#include "tcpserver.h"
#include "tcpclientsocket.h"
#include "common.h"

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent)
{
}


// 新连接进入时，由QTcpServer调用
void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    // 1. 创建socket
    TcpClientSocket* tcpClientSocket = new TcpClientSocket(this);

    // 2.设置socket描述符
    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    // 管理tcpClientSocket添加到list。
    Server* s = Common::getServerInstance();
    s->addClient(tcpClientSocket);


    // 建立信号槽

}
