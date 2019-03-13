#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include "tcpclientsocket.h"
#include "tcpserver.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

    // 启动服务器

    void start(int port);

    // 停止服务器
    void stop(void);

    // 添加新的连接socket

    void addClient(TcpClientSocket* c);

    // 获取连接socket
    QList<TcpClientSocket*>& getClients(void);   // 获取对象还是引用？？？

signals:

public slots:

private:
    QList<TcpClientSocket*> _clients;   // 用于存储连接socket
    TcpServer* _tcpServer;    // 监听服务对象


};

#endif // SERVER_H
