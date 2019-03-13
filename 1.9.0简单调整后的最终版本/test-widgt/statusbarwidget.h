#ifndef STATUSBARWIDGET_H
#define STATUSBARWIDGET_H
#include"masklabel.h"
#include"tcpclientsocket.h"
#include"widget.h"
#include<QString>
#include"mainwindow.h"
#include <QWidget>
#include"weather.h"

namespace Ui {
class statusbarwidget;
}

class statusbarwidget : public QWidget
{
    Q_OBJECT

public:
    explicit statusbarwidget(int uid , QString username = QString("user") , QString wi = QString(":/image-3/icon.ico"),QWidget *parent = 0);
    ~statusbarwidget();

    QString getWeatherIcon() const;//获得天气图片
    void setWeatherIcon(const QString &value);//设置天气图片
    void sleep(int time);

private slots:
    void dealMessage(QMap<QString, QString> msg,QString TypeOfMessage);
    void creatwidget(QString username, int uid);
    void on_pushButton_clicked();
    void addgroupchat();
    void dealweatherreport();



    void on_pushButton_2_clicked();

signals:
    void addnewuser(QString username,int uid);
    void addBuddy(QString name, int uid);


private:
    Ui::statusbarwidget *ui;
    TcpClientSocket* _tcpclientSocket;
    int _uid;//自己的uid
    QString _username;//自己的用户名
    int widgetExist[99];//判断对应的uid的聊天窗口是否存在,存在则是对应的widget的编号，否则为0
    Widget* chatwidget[21];//提供至多20个聊天窗口的同时开启
    int chatwidgetnumber;
    QString weatherIcon;
    bool groupchatexist;
    Widget* groupchatwidget;
    MainWindow* wea;//天气预报
    weather* weatherwindow;//天气预报的窗口
};

#endif // STATUSBARWIDGET_H
