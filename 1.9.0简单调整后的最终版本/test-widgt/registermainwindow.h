#ifndef REGISTERMAINWINDOW_H
#define REGISTERMAINWINDOW_H
#include"tcpclientsocket.h"

#include <QMainWindow>

namespace Ui {
class registerMainWindow;
}

class registerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit registerMainWindow(QWidget *parent = 0);
    ~registerMainWindow();


private slots:
    void on_pushButton_clicked();
    void deelMessage(QMap<QString, QString> msg, QString TypeOfMessage);

private:
    Ui::registerMainWindow *ui;
    TcpClientSocket* _tcpclientSocket;
    QString _username;
};

#endif // REGISTERMAINWINDOW_H
