#include"loginmainwindow.h"
#include <QApplication>
#include"log.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginMainWindow w;
    w.show();

//    logSysInit("qdebug.txt");
//        //打印日志到文件中
//        qDebug("这是中文");
//        qDebug()<<"hello";
//        qWarning("This is a warning message");
//        //qCritical("This is a critical message");
//        //qFatal("This is a fatal message");
//        if(gMLog){
//            gMLog->debug("aaaaa");
//        }

    return a.exec();
}
