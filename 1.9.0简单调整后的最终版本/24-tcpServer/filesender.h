#ifndef FILESENDER_H
#define FILESENDER_H

#include <QDialog>
#include <QAbstractSocket>

class QTcpSocket;
class QFile;
namespace Ui {
class filesender;
}

class filesender : public QDialog
{
    Q_OBJECT

public:
    explicit filesender(QString IP , QString sendfilename ,QWidget *parent = 0);
    ~filesender();
    void openFile();
    void send();

private slots:
    void startTransfer();
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError);


private:
    Ui::filesender *ui;
    QTcpSocket *tcpClient;
    QFile *localFile;            //要发送的文件
    qint64 totalBytes;           //发送数据的总大小
    qint64 bytesWritten;         //已经发送数据的大小
    qint64 bytesToWrite;         //剩余数据大小
    qint64 payloadSize;          //每次发送数据的大小
    QString fileName;            //保存文件路径
    QByteArray outBlock;         //数据缓冲区，即存放每次要发送的数据块
    QString _IP;                 //要发送的IP
    QString _sendfilename;        //要发送的文件名
};

#endif // FILESENDER_H

