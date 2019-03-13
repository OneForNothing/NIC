/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *portLineEdit;
    QLineEdit *sendLineEdit;
    QPushButton *sendButton;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *revLineEdit;
    QLineEdit *ipLineEdit;
    QLabel *label_2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QProgressBar *serverProgressBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 464);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(120, 70, 231, 41));
        QFont font;
        font.setPointSize(16);
        portLineEdit->setFont(font);
        sendLineEdit = new QLineEdit(centralWidget);
        sendLineEdit->setObjectName(QStringLiteral("sendLineEdit"));
        sendLineEdit->setGeometry(QRect(130, 190, 221, 41));
        sendLineEdit->setFont(font);
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(30, 190, 71, 41));
        sendButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 61, 41));
        label->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 91, 41));
        label_3->setFont(font);
        revLineEdit = new QLineEdit(centralWidget);
        revLineEdit->setObjectName(QStringLiteral("revLineEdit"));
        revLineEdit->setGeometry(QRect(130, 130, 221, 41));
        revLineEdit->setFont(font);
        ipLineEdit = new QLineEdit(centralWidget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(120, 10, 231, 41));
        ipLineEdit->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 61, 41));
        label_2->setFont(font);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(50, 330, 131, 41));
        startButton->setFont(font);
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);
        stopButton->setGeometry(QRect(210, 330, 131, 41));
        stopButton->setFont(font);
        serverProgressBar = new QProgressBar(centralWidget);
        serverProgressBar->setObjectName(QStringLiteral("serverProgressBar"));
        serverProgressBar->setGeometry(QRect(50, 280, 291, 23));
        serverProgressBar->setValue(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        portLineEdit->setText(QApplication::translate("MainWindow", "8899", 0));
        sendLineEdit->setText(QString());
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("MainWindow", "IP:", 0));
        label_3->setText(QApplication::translate("MainWindow", "receive:", 0));
        revLineEdit->setText(QString());
        ipLineEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("MainWindow", "PORT:", 0));
        startButton->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", 0));
        stopButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
