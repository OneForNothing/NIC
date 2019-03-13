/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

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

class Ui_weather
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *weather)
    {
        if (weather->objectName().isEmpty())
            weather->setObjectName(QStringLiteral("weather"));
        weather->resize(475, 379);
        weather->setStyleSheet(QLatin1String("QMainWindow{\n"
"border-image: url(:/image-3/images/UI.png);}"));
        centralwidget = new QWidget(weather);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 141, 91));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 120, 61, 31));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 0, 241, 61));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 30, 301, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 60, 191, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 80, 171, 51));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 110, 181, 51));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 160, 61, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(110, 160, 61, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(200, 160, 61, 31));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(280, 160, 61, 31));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(370, 150, 61, 51));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 200, 81, 71));
        QFont font2;
        font2.setPointSize(10);
        label_13->setFont(font2);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(110, 200, 71, 71));
        label_14->setFont(font2);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(190, 200, 71, 71));
        label_15->setFont(font2);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(270, 210, 71, 71));
        label_16->setFont(font2);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(360, 200, 71, 81));
        label_17->setFont(font2);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 250, 81, 61));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(100, 250, 71, 61));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(180, 250, 81, 61));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(270, 250, 71, 61));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(370, 250, 61, 61));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 300, 71, 21));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(100, 300, 61, 21));
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(180, 300, 71, 21));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(270, 300, 61, 21));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(370, 300, 71, 21));
        weather->setCentralWidget(centralwidget);
        menubar = new QMenuBar(weather);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 475, 23));
        weather->setMenuBar(menubar);
        statusbar = new QStatusBar(weather);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        weather->setStatusBar(statusbar);

        retranslateUi(weather);

        QMetaObject::connectSlotsByName(weather);
    } // setupUi

    void retranslateUi(QMainWindow *weather)
    {
        weather->setWindowTitle(QApplication::translate("weather", "MainWindow", 0));
        label->setText(QApplication::translate("weather", "\345\256\236\346\227\266\346\260\224\346\270\251", 0));
        label_2->setText(QApplication::translate("weather", "\345\237\216\345\270\202", 0));
        label_3->setText(QApplication::translate("weather", "\346\227\245\346\234\237", 0));
        label_4->setText(QApplication::translate("weather", "\346\271\277\345\272\246", 0));
        label_5->setText(QApplication::translate("weather", "\351\243\216\345\220\221", 0));
        label_6->setText(QApplication::translate("weather", "\346\227\245\345\207\272\346\227\266\351\227\264", 0));
        label_7->setText(QApplication::translate("weather", "\346\227\245\350\220\275\346\227\266\351\227\264", 0));
        label_8->setText(QApplication::translate("weather", "\344\273\212\345\244\251", 0));
        label_9->setText(QApplication::translate("weather", "\346\227\245 \346\230\237\346\234\237", 0));
        label_10->setText(QApplication::translate("weather", "\346\227\245 \346\230\237\346\234\237", 0));
        label_11->setText(QApplication::translate("weather", "\346\227\245 \346\230\237\346\234\237", 0));
        label_12->setText(QApplication::translate("weather", "\346\227\245 \346\230\237\346\234\237", 0));
        label_13->setText(QApplication::translate("weather", "\345\244\251\346\260\224", 0));
        label_14->setText(QApplication::translate("weather", "\345\244\251\346\260\224", 0));
        label_15->setText(QApplication::translate("weather", "\345\244\251\346\260\224", 0));
        label_16->setText(QApplication::translate("weather", "\345\244\251\346\260\224", 0));
        label_17->setText(QApplication::translate("weather", "    \345\244\251\346\260\224", 0));
        label_18->setText(QApplication::translate("weather", "\346\270\251\345\272\246\350\214\203\345\233\264", 0));
        label_19->setText(QApplication::translate("weather", "\346\270\251\345\272\246\350\214\203\345\233\264", 0));
        label_20->setText(QApplication::translate("weather", "\346\270\251\345\272\246\350\214\203\345\233\264", 0));
        label_21->setText(QApplication::translate("weather", "\346\270\251\345\272\246\350\214\203\345\233\264", 0));
        label_22->setText(QApplication::translate("weather", "\346\270\251\345\272\246\350\214\203\345\233\264", 0));
        label_23->setText(QApplication::translate("weather", "TextLabel", 0));
        label_24->setText(QApplication::translate("weather", "TextLabel", 0));
        label_25->setText(QApplication::translate("weather", "TextLabel", 0));
        label_26->setText(QApplication::translate("weather", "TextLabel", 0));
        label_27->setText(QApplication::translate("weather", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class weather: public Ui_weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
