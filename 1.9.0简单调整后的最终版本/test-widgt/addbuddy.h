#ifndef ADDBUDDY_H
#define ADDBUDDY_H
#include"tcpclientsocket.h"

#include <QDialog>

namespace Ui {
class Addbuddy;
}

class Addbuddy : public QDialog
{
    Q_OBJECT

public:
    explicit Addbuddy(QWidget *parent = 0);
    ~Addbuddy();
    void search();
    void setfromuid(int uid);

private slots:
    void on_search_clicked();

    void on_quit_clicked();

private:
    Ui::Addbuddy *ui;
    TcpClientSocket* _tcpclientSocket;
    int fromuid;
};

#endif // ADDBUDDY_H
