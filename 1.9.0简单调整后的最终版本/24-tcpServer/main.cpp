#include "mainwindow.h"
#include <QApplication>

MainWindow *mw = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mw = &w;
    w.show();

    return a.exec();
}
