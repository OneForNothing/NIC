/********************************************************************************
** Form generated from reading UI file 'loginmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINMAINWINDOW_H
#define UI_LOGINMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginMainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *losePwdButton;
    QPushButton *enterButton;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *regButton;
    QPushButton *pushButton;

    void setupUi(QMainWindow *loginMainWindow)
    {
        if (loginMainWindow->objectName().isEmpty())
            loginMainWindow->setObjectName(QStringLiteral("loginMainWindow"));
        loginMainWindow->resize(800, 600);
        loginMainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"border-image: url(:/image-3/\347\231\273\345\275\225\350\203\214\346\231\257.jpg);}"));
        centralwidget = new QWidget(loginMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 220, 311, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\273\206\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: rgb(240, 240, 240);\n"
"    selection-background-color: darkgray;\n"
"}"));
        losePwdButton = new QPushButton(centralwidget);
        losePwdButton->setObjectName(QStringLiteral("losePwdButton"));
        losePwdButton->setGeometry(QRect(330, 430, 119, 37));
        sizePolicy.setHeightForWidth(losePwdButton->sizePolicy().hasHeightForWidth());
        losePwdButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        losePwdButton->setFont(font1);
        losePwdButton->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        enterButton->setGeometry(QRect(130, 390, 161, 71));
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        font2.setWeight(75);
        enterButton->setFont(font2);
        enterButton->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255,50);\n"
" border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    selection-background-color: darkgray;"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 290, 311, 41));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit {\n"
"	\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background: rgb(240, 240, 240);\n"
"    selection-background-color: darkgray;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 70, 461, 151));
        QFont font3;
        font3.setFamily(QStringLiteral("Cambria Math"));
        font3.setPointSize(35);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        regButton = new QPushButton(centralwidget);
        regButton->setObjectName(QStringLiteral("regButton"));
        regButton->setGeometry(QRect(330, 390, 119, 37));
        sizePolicy1.setHeightForWidth(regButton->sizePolicy().hasHeightForWidth());
        regButton->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        regButton->setFont(font4);
        regButton->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 490, 141, 23));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\256\265\345\256\201\346\257\233\347\254\224\350\241\214\344\271\246"));
        font5.setPointSize(10);
        pushButton->setFont(font5);
        loginMainWindow->setCentralWidget(centralwidget);

        retranslateUi(loginMainWindow);

        QMetaObject::connectSlotsByName(loginMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *loginMainWindow)
    {
        loginMainWindow->setWindowTitle(QApplication::translate("loginMainWindow", "MainWindow", 0));
        lineEdit->setPlaceholderText(QApplication::translate("loginMainWindow", "                   username", 0));
        losePwdButton->setText(QApplication::translate("loginMainWindow", "\345\277\230\350\256\260\345\257\206\347\240\201", 0));
        enterButton->setText(QApplication::translate("loginMainWindow", "\347\231\273\345\275\225", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("loginMainWindow", "                   password", 0));
        label->setText(QString());
        regButton->setText(QApplication::translate("loginMainWindow", "\347\253\213\345\215\263\346\263\250\345\206\214", 0));
        pushButton->setText(QApplication::translate("loginMainWindow", "\346\211\253\347\240\201\345\205\263\346\263\250\357\274\214\346\233\264\345\244\232\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class loginMainWindow: public Ui_loginMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINMAINWINDOW_H
