#ifndef ADDGROUP_H
#define ADDGROUP_H
#include"tcpclientsocket.h"

#include <QDialog>

namespace Ui {
class addgroup;
}

class addgroup : public QDialog
{
    Q_OBJECT

public:
    explicit addgroup(TcpClientSocket* tcpclientSocket , QWidget *parent = 0);
    void setfromuid(int fromuid);
    ~addgroup();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addgroup *ui;
    TcpClientSocket* _tcpclientSocket;
    int _fromuid;
};

#endif // ADDGROUP_H
