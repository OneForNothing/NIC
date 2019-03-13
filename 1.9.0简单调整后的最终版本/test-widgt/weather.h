#ifndef WEATHER_H
#define WEATHER_H

#include <QMainWindow>
#include"mainwindow.h"

namespace Ui {
class weather;
}

class weather : public QMainWindow
{
    Q_OBJECT

public:
    explicit weather(MainWindow *wea,QWidget *parent = 0);
    ~weather();

private:
    Ui::weather *ui;
    MainWindow *_wea;
};

#endif // WEATHER_H
