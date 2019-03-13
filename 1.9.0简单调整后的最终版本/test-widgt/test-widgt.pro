#-------------------------------------------------
#
# Project created by QtCreator 2017-09-06T14:29:24
#
#-------------------------------------------------

QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test-widgt
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    client.cpp \
    tcpclientsocket.cpp \
    registermainwindow.cpp \
    loginmainwindow.cpp \
    statusbarwidget.cpp \
    personlist.cpp \
    personlistbuddy.cpp \
    addbuddy.cpp \
    filereceiver.cpp \
    newmainwindow.cpp \
    addgroup.cpp \
    mainwindow.cpp \
    weather.cpp \
    log.cpp

HEADERS  += widget.h \
    client.h \
    tcpclientsocket.h \
    registermainwindow.h \
    loginmainwindow.h \
    statusbarwidget.h \
    personlist.h \
    personlistbuddy.h \
    pixmap.h \
    addbuddy.h \
    filereceiver.h \
    newmainwindow.h \
    addgroup.h \
    mainwindow.h \
    weather.h \
    log.h

FORMS    += widget.ui \
    client.ui \
    registermainwindow.ui \
    loginmainwindow.ui \
    statusbarwidget.ui \
    addbuddy.ui \
    filereceiver.ui \
    newmainwindow.ui \
    addgroup.ui \
    mainwindow.ui \
    weather.ui

RESOURCES += \
    image-3.qrc \
    res.qrc
