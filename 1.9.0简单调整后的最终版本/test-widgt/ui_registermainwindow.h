/********************************************************************************
** Form generated from reading UI file 'registermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERMAINWINDOW_H
#define UI_REGISTERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerMainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLabel *pixLabel;
    QLabel *informationLabel;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit_4;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *registerMainWindow)
    {
        if (registerMainWindow->objectName().isEmpty())
            registerMainWindow->setObjectName(QStringLiteral("registerMainWindow"));
        registerMainWindow->resize(789, 587);
        registerMainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"border-image: url(:/image-3/\346\263\250\345\206\214\350\203\214\346\231\257.jpg);}"));
        centralwidget = new QWidget(registerMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 240, 211, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("\n"
"#lineEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background:  rgb(223,223,224);\n"
"    selection-background-color: darkgray;\n"
"}\n"
"\n"
""));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 320, 211, 41));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QLatin1String("\n"
"#lineEdit_2 {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background:  rgb(223,223,224);\n"
"    selection-background-color: darkgray;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 500, 221, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\260\221\345\204\277\347\256\200\344\275\223"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 400, 211, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(11);
        lineEdit_3->setFont(font2);
        lineEdit_3->setStyleSheet(QLatin1String("\n"
"#lineEdit_3 {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background:  rgb(223,223,224);\n"
"    selection-background-color: darkgray;\n"
"}"));
        pixLabel = new QLabel(centralwidget);
        pixLabel->setObjectName(QStringLiteral("pixLabel"));
        pixLabel->setGeometry(QRect(110, 20, 201, 181));
        informationLabel = new QLabel(centralwidget);
        informationLabel->setObjectName(QStringLiteral("informationLabel"));
        informationLabel->setGeometry(QRect(390, 60, 341, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        informationLabel->setFont(font3);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(390, 160, 321, 51));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(50, 20, 132, 22));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        radioButton->setFont(font4);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 20, 91, 22));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        radioButton_2->setFont(font5);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(390, 240, 321, 51));
        QFont font6;
        font6.setPointSize(11);
        font6.setItalic(true);
        lineEdit_4->setFont(font6);
        lineEdit_4->setStyleSheet(QLatin1String("\n"
"#lineEdit_4 {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background:  rgb(223,223,224);\n"
"    selection-background-color: darkgray;\n"
"}"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(390, 330, 331, 141));
        QFont font7;
        font7.setPointSize(11);
        textEdit->setFont(font7);
        textEdit->setStyleSheet(QLatin1String("\n"
"#textEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    background:  rgb(223,223,224);\n"
"    selection-background-color: darkgray;\n"
"}"));
        registerMainWindow->setCentralWidget(centralwidget);

        retranslateUi(registerMainWindow);

        QMetaObject::connectSlotsByName(registerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *registerMainWindow)
    {
        registerMainWindow->setWindowTitle(QApplication::translate("registerMainWindow", "MainWindow", 0));
        lineEdit->setPlaceholderText(QApplication::translate("registerMainWindow", "    username", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("registerMainWindow", "    password", 0));
        pushButton->setText(QApplication::translate("registerMainWindow", "REGISTER", 0));
        lineEdit_3->setPlaceholderText(QApplication::translate("registerMainWindow", "confine password", 0));
        pixLabel->setText(QApplication::translate("registerMainWindow", "TextLabel", 0));
        informationLabel->setText(QApplication::translate("registerMainWindow", "my personal information", 0));
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("registerMainWindow", "\347\224\267", 0));
        radioButton_2->setText(QApplication::translate("registerMainWindow", "\345\245\263", 0));
        lineEdit_4->setPlaceholderText(QApplication::translate("registerMainWindow", "\346\210\221\347\232\204\345\271\264\351\276\204\357\274\232", 0));
        textEdit->setPlaceholderText(QApplication::translate("registerMainWindow", "\346\210\221\347\232\204\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class registerMainWindow: public Ui_registerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERMAINWINDOW_H
