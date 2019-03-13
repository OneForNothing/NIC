#ifndef LOGINMAINWINDOW_H
#define LOGINMAINWINDOW_H
#include"tcpclientsocket.h"
#include"statusbarwidget.h"
#include <QMainWindow>

namespace Ui {
class loginMainWindow;
}

class loginMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginMainWindow(QWidget *parent = 0);
    ~loginMainWindow();

private slots:
    void deelMessage(QMap<QString, QString> msg,QString TypeOfMessage);
    void on_losePwdButton_clicked();

    void on_enterButton_clicked();

    void on_regButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::loginMainWindow *ui;
    TcpClientSocket* _tcpclientSocket;
    QString _username;//记录用户自己输入的username
    int _uid;//记录服务器返回的自己的uid
};

#endif // LOGINMAINWINDOW_H
