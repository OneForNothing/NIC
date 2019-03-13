#-------------------------------------------------
#
# Project created by QtCreator 2017-09-04T15:09:27
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 24-tcpServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclientsocket.cpp \
    tcpserver.cpp \
    server.cpp \
    common.cpp \
    fileserver.cpp \
    database.cpp \
    showcpumemory.cpp \
    filesender.cpp

HEADERS  += mainwindow.h \
    tcpclientsocket.h \
    tcpserver.h \
    server.h \
    common.h \
    fileserver.h \
    database.h \
    showcpumemory.h \
    filesender.h

FORMS    += mainwindow.ui \
    filesender.ui
