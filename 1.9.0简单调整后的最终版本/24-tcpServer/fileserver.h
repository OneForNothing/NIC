#ifndef FILESERVER_H
#define FILESERVER_H

#include <QMainWindow>
#include <QAbstractSocket>
#include <QTcpServer>

class QTcpSocket;
class QFile;

namespace Ui {
class MainWindow;
}

class fileserver: public QMainWindow
{
    Q_OBJECT

public:
    explicit fileserver(Ui::MainWindow *parent=0);
    void start();
    void stop();
    ~fileserver();

private slots:
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);
private:
    Ui::MainWindow *ui;
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    qint64 totalBytes;    //存放总大小信息
    qint64 bytesReceived; //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QString fileName;     //存放文件名
    QFile *localFile;     //本地文件
    QByteArray inBlock;   //数据缓冲区
};

#endif // FILESERVER_H




