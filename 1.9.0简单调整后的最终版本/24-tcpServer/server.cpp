#include "server.h"
#include <QMessageBox>
#include <QDebug>

Server::Server(QObject *parent) :
    QObject(parent)
{
    _tcpServer = new TcpServer(this);
}


// 启动
void Server::start(int port)
{
    // 启动监听
    if (false == _tcpServer->listen(QHostAddress::Any, port))
    {
        QMessageBox::warning(NULL, "error", "无法启动监听", QMessageBox::Ok);
        qDebug() << _tcpServer->errorString();
    }//监听启动失败则返回相关报错
}


// 停止
void Server::stop()
{
    // 清list
    _clients.clear();

    // 关闭服务器
    _tcpServer->close();
}


// 添加
void Server::addClient(TcpClientSocket *c)
{
    _clients.append(c);
}


QList<TcpClientSocket *> &Server::getClients()
{
    return _clients;
}

