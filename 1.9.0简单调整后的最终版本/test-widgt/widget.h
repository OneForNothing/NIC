#ifndef WIDGET_H
#define WIDGET_H
#include"tcpclientsocket.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(int uid , QString username ,QWidget *parent = 0);
    void settouid(int touid);
    int gettouid();
    void settouername(QString tousername);
    QString gettousername();
    void settcpclientsocket(TcpClientSocket *tcpclientSocket);
    void gettouserinfo();
    ~Widget();
    void displayMessage(QMap<QString, QString> msg,QString TypeOfMessage);
    void resizeEvent(QResizeEvent *event);

private:
    bool saveFile(const QString& filename);

private slots:   
    void on_SendPushButton_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    TcpClientSocket* _tcpclientSocket;
    int _uid;//自己的uid
    QString _username;//自己的用户名
    int _touid;//发送对象的uid
    QString _tousername;//发送对象的用户
    bool niming;//匿名变量
};

#endif // WIDGET_H
