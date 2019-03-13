#ifndef FILERECEIVER_H
#define FILERECEIVER_H

#include <QDialog>
#include <QAbstractSocket>
#include <QTcpServer>

class QTcpSocket;
class QFile;

namespace Ui {
class filereceiver;
}

class filereceiver : public QDialog
{
    Q_OBJECT

public:
    explicit filereceiver(QString IP, QWidget *parent = 0);
    ~filereceiver();

private slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    Ui::filereceiver *ui;
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    qint64 totalBytes;    //存放总大小信息
    qint64 bytesReceived; //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QString fileName;     //存放文件名
    QFile *localFile;     //本地文件
    QByteArray inBlock;   //数据缓冲区
    QString _IP;          //用于存放本机IP
};

#endif // FILERECEIVER_H

