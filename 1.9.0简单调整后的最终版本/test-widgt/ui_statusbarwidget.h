/********************************************************************************
** Form generated from reading UI file 'statusbarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSBARWIDGET_H
#define UI_STATUSBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statusbarwidget
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *statusbarwidget)
    {
        if (statusbarwidget->objectName().isEmpty())
            statusbarwidget->setObjectName(QStringLiteral("statusbarwidget"));
        statusbarwidget->resize(295, 521);
        statusbarwidget->setStyleSheet(QLatin1String("QListWidget{  \n"
"     background-color:rgba(255,255,255,100);\n"
"    color:black;  \n"
"    border:none;  \n"
"}  \n"
"  \n"
"QListWidget::item{  \n"
"    border:none;  \n"
"        height: 54px;  \n"
"}  \n"
"  \n"
"QListWidget::item:hover{  \n"
"    background:rgb(252,240,193)  \n"
"}  \n"
"  \n"
"QListWidget::item:selected{  \n"
"    background:rgb(252,233,161);  \n"
"    color:black;  \n"
"}  \n"
"  \n"
"QScrollBar:vertical {                 \n"
"    background:transparent;  \n"
"    width:9px;  \n"
"    margin: 0px 0px 2px 0px;  \n"
"}  \n"
"  \n"
"QScrollBar::handle:vertical {  \n"
"    background: rgb(195, 195, 195);  \n"
"    min-height: 20px;  \n"
"    border-radius: 3px;  \n"
"}  \n"
"  \n"
"QScrollBar::handle:vertical:hover{  \n"
"    background:rgba(0,0,0,30%);  \n"
"}  \n"
"  \n"
"QScrollBar::add-line:vertical {  \n"
"    height: 0px;  \n"
"    subcontrol-position: bottom;  \n"
"    subcontrol-origin: margin;  \n"
"}  \n"
"  \n"
"QScrollBar::sub-line:vertical {  \n"
"    height: 0px;  \n"
"    "
                        "subcontrol-position: top;  \n"
"    subcontrol-origin: margin;  \n"
"}  "));
        label = new QLabel(statusbarwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 30, 81, 71));
        pushButton = new QPushButton(statusbarwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 20, 71, 61));
        pushButton->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255,50);\n"
" \n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    selection-background-color: darkgray;"));
        pushButton->setAutoDefault(true);
        pushButton->setDefault(true);
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(statusbarwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 0, 41, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255,50);\n"
" \n"
"    border-radius: 10px;\n"
"    padding: 0 8px;\n"
"    selection-background-color: darkgray;"));

        retranslateUi(statusbarwidget);

        QMetaObject::connectSlotsByName(statusbarwidget);
    } // setupUi

    void retranslateUi(QWidget *statusbarwidget)
    {
        statusbarwidget->setWindowTitle(QApplication::translate("statusbarwidget", "Form", 0));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("statusbarwidget", "\346\215\242\350\202\244", 0));
    } // retranslateUi

};

namespace Ui {
    class statusbarwidget: public Ui_statusbarwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSBARWIDGET_H
