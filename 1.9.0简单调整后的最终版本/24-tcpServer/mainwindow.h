#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include"fileserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void sleep(int time);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_sendButton_clicked();

    void resetFileSever();

    void displayMessage(QMap<QString, QString> msg,QString TypeOfMessage);

private:
    Ui::MainWindow *ui;
    QString message;
    fileserver _fileserver;
    int groupchatuid[10];
    int groupchatnumber;
};

#endif // MAINWINDOW_H
