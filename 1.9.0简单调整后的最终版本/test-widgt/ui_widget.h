/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QFontComboBox *fontComboBox;
    QPushButton *SendPushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(712, 538);
        Widget->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 410, 411, 121));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255,10);"));
        lineEdit->setFrame(false);
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(110, 380, 101, 31));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(10, 380, 101, 31));
        SendPushButton = new QPushButton(Widget);
        SendPushButton->setObjectName(QStringLiteral("SendPushButton"));
        SendPushButton->setGeometry(QRect(250, 490, 81, 31));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 490, 81, 31));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 380, 81, 31));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 181, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 60, 411, 311));
        plainTextEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255,10);"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 0, 181, 51));
        label_2->setFont(font);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 60, 251, 51));
        label_3->setFont(font);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 120, 181, 51));
        label_4->setFont(font);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(430, 180, 231, 51));
        label_5->setFont(font);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(430, 240, 221, 51));
        label_6->setFont(font);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(430, 300, 241, 51));
        label_7->setFont(font);
        plainTextEdit_2 = new QPlainTextEdit(Widget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(430, 350, 261, 171));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255,10);"));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 380, 75, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        SendPushButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
        SendPushButton->setShortcut(QApplication::translate("Widget", "Return", 0));
        pushButton_3->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", 0));
        pushButton->setText(QApplication::translate("Widget", "\344\274\240\350\276\223\346\226\207\344\273\266", 0));
        label->setText(QApplication::translate("Widget", "\347\276\244\350\201\212\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("Widget", "\345\245\275\345\217\213\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("Widget", "\346\230\265\347\247\260\357\274\232", 0));
        label_4->setText(QApplication::translate("Widget", "uid:", 0));
        label_5->setText(QApplication::translate("Widget", "\346\200\247\345\210\253\357\274\232", 0));
        label_6->setText(QApplication::translate("Widget", "\345\271\264\351\276\204\357\274\232", 0));
        label_7->setText(QApplication::translate("Widget", "\344\270\252\346\200\247\347\255\276\345\220\215\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("Widget", "\345\214\277\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
