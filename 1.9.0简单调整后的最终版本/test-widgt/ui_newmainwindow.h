/********************************************************************************
** Form generated from reading UI file 'newmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAINWINDOW_H
#define UI_NEWMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newmainwindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newmainwindow)
    {
        if (newmainwindow->objectName().isEmpty())
            newmainwindow->setObjectName(QStringLiteral("newmainwindow"));
        newmainwindow->resize(498, 462);
        centralwidget = new QWidget(newmainwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 341, 321));
        newmainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(newmainwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 498, 30));
        newmainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(newmainwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        newmainwindow->setStatusBar(statusbar);

        retranslateUi(newmainwindow);

        QMetaObject::connectSlotsByName(newmainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *newmainwindow)
    {
        newmainwindow->setWindowTitle(QApplication::translate("newmainwindow", "MainWindow", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class newmainwindow: public Ui_newmainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAINWINDOW_H
