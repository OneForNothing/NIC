#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);

    QString serverIp() const;
    void setServerIp(const QString &serverIp);

    QString serverPort() const;
    void setServerPort(const QString &serverPort);


    // 连接到服务器
    bool connectToServer(void);
    bool testConnect(void);

    // 发送消息
    void sendMessage(QMap<QString, QString> msg, QString TypeOfMessage);


signals:

    void dealMessage(QMap<QString, QString> msg,QString TypeOfMessage);

public slots:

    QString receiveMessage(void);


private:
    QString _serverIp;     // 服务器的IP
    QString _serverPort;   // 服务器的port

    quint16  _blocksize;   // 数据体大小

};

#endif // TCPCLIENTSOCKET_H
