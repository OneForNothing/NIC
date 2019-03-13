//#ifndef LOG_H
//#define LOG_H

//class log
//{
//public:
//    log();
//};

//#endif // LOG_H
#ifndef LOG_H
#define LOG_H


#include <QFile>
#include <QMessageLogger>
#include <qlogging.h>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

extern QMessageLogger *gMLog;
void logSysInit(QString filePath);
void logSysInit();

#endif // LOG_H
