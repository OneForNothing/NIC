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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *cityEdit;
    QLabel *temp;
    QLabel *city;
    QLabel *date;
    QToolButton *getButton;
    QPushButton *minButton;
    QPushButton *closeButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *forecast_0_date;
    QLabel *forecast_0_type;
    QLabel *forecast_0_temp;
    QGridLayout *gridLayout_2;
    QLabel *forecast_1_date;
    QLabel *forecast_1_type;
    QLabel *forecast_1_temp;
    QGridLayout *gridLayout_3;
    QLabel *forecast_2_date;
    QLabel *forecast_2_type;
    QLabel *forecast_2_temp;
    QGridLayout *gridLayout_4;
    QLabel *forecast_3_date;
    QLabel *forecast_3_type;
    QLabel *forecast_3_temp;
    QGridLayout *gridLayout_5;
    QLabel *forecast_4_date;
    QLabel *forecast_4_type;
    QLabel *forecast_4_temp;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLabel *sunrise;
    QLabel *label_2;
    QLabel *sunset;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_7;
    QLabel *label_3;
    QLabel *shidu;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_8;
    QLabel *fengxiang;
    QLabel *fengli;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_9;
    QLabel *label_4;
    QTextBrowser *ganmao;
    QPushButton *updateButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(572, 459);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cityEdit = new QLineEdit(centralWidget);
        cityEdit->setObjectName(QStringLiteral("cityEdit"));
        cityEdit->setGeometry(QRect(10, 10, 71, 21));
        cityEdit->setFocusPolicy(Qt::StrongFocus);
        temp = new QLabel(centralWidget);
        temp->setObjectName(QStringLiteral("temp"));
        temp->setGeometry(QRect(50, 60, 150, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(55);
        font.setBold(false);
        font.setWeight(50);
        temp->setFont(font);
        temp->setAlignment(Qt::AlignCenter);
        city = new QLabel(centralWidget);
        city->setObjectName(QStringLiteral("city"));
        city->setGeometry(QRect(50, 160, 150, 30));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        city->setFont(font1);
        city->setAlignment(Qt::AlignCenter);
        date = new QLabel(centralWidget);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(150, 10, 200, 25));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        date->setFont(font2);
        date->setAlignment(Qt::AlignCenter);
        getButton = new QToolButton(centralWidget);
        getButton->setObjectName(QStringLiteral("getButton"));
        getButton->setGeometry(QRect(60, 10, 21, 21));
        getButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/search"), QSize(), QIcon::Normal, QIcon::Off);
        getButton->setIcon(icon1);
        getButton->setIconSize(QSize(21, 21));
        getButton->setAutoRaise(true);
        minButton = new QPushButton(centralWidget);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setGeometry(QRect(440, 5, 25, 25));
        minButton->setCursor(QCursor(Qt::PointingHandCursor));
        minButton->setFlat(true);
        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(470, 5, 25, 25));
        closeButton->setCursor(QCursor(Qt::PointingHandCursor));
        closeButton->setFlat(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 250, 501, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 15);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 10);
        forecast_0_date = new QLabel(layoutWidget);
        forecast_0_date->setObjectName(QStringLiteral("forecast_0_date"));
        forecast_0_date->setMinimumSize(QSize(80, 20));
        forecast_0_date->setMaximumSize(QSize(80, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        forecast_0_date->setFont(font3);
        forecast_0_date->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(forecast_0_date, 0, 0, 1, 1);

        forecast_0_type = new QLabel(layoutWidget);
        forecast_0_type->setObjectName(QStringLiteral("forecast_0_type"));
        forecast_0_type->setMinimumSize(QSize(78, 75));
        forecast_0_type->setScaledContents(true);

        gridLayout->addWidget(forecast_0_type, 1, 0, 1, 1);

        forecast_0_temp = new QLabel(layoutWidget);
        forecast_0_temp->setObjectName(QStringLiteral("forecast_0_temp"));
        forecast_0_temp->setMinimumSize(QSize(75, 20));
        forecast_0_temp->setMaximumSize(QSize(75, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        forecast_0_temp->setFont(font4);
        forecast_0_temp->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(forecast_0_temp, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 10);
        forecast_1_date = new QLabel(layoutWidget);
        forecast_1_date->setObjectName(QStringLiteral("forecast_1_date"));
        forecast_1_date->setMinimumSize(QSize(75, 20));
        forecast_1_date->setMaximumSize(QSize(75, 20));
        forecast_1_date->setFont(font3);
        forecast_1_date->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(forecast_1_date, 0, 0, 1, 1);

        forecast_1_type = new QLabel(layoutWidget);
        forecast_1_type->setObjectName(QStringLiteral("forecast_1_type"));
        forecast_1_type->setMinimumSize(QSize(78, 75));
        forecast_1_type->setScaledContents(true);

        gridLayout_2->addWidget(forecast_1_type, 1, 0, 1, 1);

        forecast_1_temp = new QLabel(layoutWidget);
        forecast_1_temp->setObjectName(QStringLiteral("forecast_1_temp"));
        forecast_1_temp->setMinimumSize(QSize(75, 20));
        forecast_1_temp->setMaximumSize(QSize(75, 20));
        forecast_1_temp->setFont(font4);
        forecast_1_temp->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(forecast_1_temp, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, -1, -1, 10);
        forecast_2_date = new QLabel(layoutWidget);
        forecast_2_date->setObjectName(QStringLiteral("forecast_2_date"));
        forecast_2_date->setMinimumSize(QSize(75, 20));
        forecast_2_date->setMaximumSize(QSize(75, 20));
        forecast_2_date->setFont(font3);
        forecast_2_date->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(forecast_2_date, 0, 0, 1, 1);

        forecast_2_type = new QLabel(layoutWidget);
        forecast_2_type->setObjectName(QStringLiteral("forecast_2_type"));
        forecast_2_type->setMinimumSize(QSize(78, 75));
        forecast_2_type->setScaledContents(true);

        gridLayout_3->addWidget(forecast_2_type, 1, 0, 1, 1);

        forecast_2_temp = new QLabel(layoutWidget);
        forecast_2_temp->setObjectName(QStringLiteral("forecast_2_temp"));
        forecast_2_temp->setMinimumSize(QSize(75, 20));
        forecast_2_temp->setMaximumSize(QSize(75, 20));
        forecast_2_temp->setFont(font4);
        forecast_2_temp->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(forecast_2_temp, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, -1, -1, 10);
        forecast_3_date = new QLabel(layoutWidget);
        forecast_3_date->setObjectName(QStringLiteral("forecast_3_date"));
        forecast_3_date->setMinimumSize(QSize(75, 20));
        forecast_3_date->setMaximumSize(QSize(75, 20));
        forecast_3_date->setFont(font3);
        forecast_3_date->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(forecast_3_date, 0, 0, 1, 1);

        forecast_3_type = new QLabel(layoutWidget);
        forecast_3_type->setObjectName(QStringLiteral("forecast_3_type"));
        forecast_3_type->setMinimumSize(QSize(78, 75));
        forecast_3_type->setScaledContents(true);

        gridLayout_4->addWidget(forecast_3_type, 1, 0, 1, 1);

        forecast_3_temp = new QLabel(layoutWidget);
        forecast_3_temp->setObjectName(QStringLiteral("forecast_3_temp"));
        forecast_3_temp->setMinimumSize(QSize(75, 20));
        forecast_3_temp->setMaximumSize(QSize(75, 20));
        forecast_3_temp->setFont(font4);
        forecast_3_temp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(forecast_3_temp, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, -1, -1, 10);
        forecast_4_date = new QLabel(layoutWidget);
        forecast_4_date->setObjectName(QStringLiteral("forecast_4_date"));
        forecast_4_date->setMinimumSize(QSize(75, 20));
        forecast_4_date->setMaximumSize(QSize(75, 20));
        forecast_4_date->setFont(font3);
        forecast_4_date->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(forecast_4_date, 0, 0, 1, 1);

        forecast_4_type = new QLabel(layoutWidget);
        forecast_4_type->setObjectName(QStringLiteral("forecast_4_type"));
        forecast_4_type->setMinimumSize(QSize(78, 75));
        forecast_4_type->setScaledContents(true);

        gridLayout_5->addWidget(forecast_4_type, 1, 0, 1, 1);

        forecast_4_temp = new QLabel(layoutWidget);
        forecast_4_temp->setObjectName(QStringLiteral("forecast_4_temp"));
        forecast_4_temp->setMinimumSize(QSize(75, 20));
        forecast_4_temp->setMaximumSize(QSize(75, 20));
        forecast_4_temp->setFont(font4);
        forecast_4_temp->setFrameShadow(QFrame::Plain);
        forecast_4_temp->setMidLineWidth(1);
        forecast_4_temp->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(forecast_4_temp, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 200, 211, 32));
        gridLayout_6 = new QGridLayout(layoutWidget1);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 30));
        label->setMaximumSize(QSize(30, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        label->setFont(font5);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        sunrise = new QLabel(layoutWidget1);
        sunrise->setObjectName(QStringLiteral("sunrise"));
        QFont font6;
        font6.setPointSize(10);
        sunrise->setFont(font6);

        gridLayout_6->addWidget(sunrise, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setFont(font5);

        gridLayout_6->addWidget(label_2, 0, 2, 1, 1);

        sunset = new QLabel(layoutWidget1);
        sunset->setObjectName(QStringLiteral("sunset"));
        sunset->setFont(font6);

        gridLayout_6->addWidget(sunset, 0, 3, 1, 1);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 200, 71, 32));
        gridLayout_7 = new QGridLayout(layoutWidget2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(30, 30));
        label_3->setMaximumSize(QSize(30, 30));
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setWeight(75);
        label_3->setFont(font7);
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_3, 0, 0, 1, 1);

        shidu = new QLabel(layoutWidget2);
        shidu->setObjectName(QStringLiteral("shidu"));
        shidu->setMinimumSize(QSize(30, 30));
        shidu->setMaximumSize(QSize(30, 30));
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setWeight(50);
        shidu->setFont(font8);
        shidu->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(shidu, 0, 1, 1, 1);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(100, 200, 168, 32));
        gridLayout_8 = new QGridLayout(layoutWidget3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        fengxiang = new QLabel(layoutWidget3);
        fengxiang->setObjectName(QStringLiteral("fengxiang"));
        fengxiang->setMinimumSize(QSize(70, 30));
        fengxiang->setMaximumSize(QSize(70, 30));
        fengxiang->setFont(font7);
        fengxiang->setScaledContents(true);
        fengxiang->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(fengxiang, 0, 0, 1, 1);

        fengli = new QLabel(layoutWidget3);
        fengli->setObjectName(QStringLiteral("fengli"));
        fengli->setMinimumSize(QSize(80, 30));
        fengli->setMaximumSize(QSize(80, 30));
        fengli->setFont(font8);

        gridLayout_8->addWidget(fengli, 0, 1, 1, 1);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(280, 100, 211, 87));
        gridLayout_9 = new QGridLayout(layoutWidget4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 75));
        label_4->setMaximumSize(QSize(30, 75));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font9.setPointSize(11);
        font9.setBold(true);
        font9.setWeight(75);
        label_4->setFont(font9);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_4, 0, 0, 1, 1);

        ganmao = new QTextBrowser(layoutWidget4);
        ganmao->setObjectName(QStringLiteral("ganmao"));
        QFont font10;
        font10.setPointSize(12);
        ganmao->setFont(font10);
        ganmao->setStyleSheet(QStringLiteral("background: transparent;border-color:transparent;border:0px;"));
        ganmao->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ganmao->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ganmao->setOpenLinks(false);

        gridLayout_9->addWidget(ganmao, 0, 1, 1, 1);

        updateButton = new QPushButton(centralWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(410, 5, 25, 25));
        updateButton->setCursor(QCursor(Qt::PointingHandCursor));
        updateButton->setIconSize(QSize(25, 25));
        updateButton->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(minButton, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));
        QObject::connect(cityEdit, SIGNAL(returnPressed()), getButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Weather", 0));
        cityEdit->setPlaceholderText(QApplication::translate("MainWindow", "\345\237\216\345\270\202", 0));
        temp->setText(QString());
        city->setText(QString());
        date->setText(QString());
#ifndef QT_NO_TOOLTIP
        getButton->setToolTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\244\251\346\260\224", 0));
#endif // QT_NO_TOOLTIP
        getButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        minButton->setToolTip(QApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        minButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QString());
        forecast_0_date->setText(QString());
        forecast_0_type->setText(QString());
        forecast_0_temp->setText(QString());
        forecast_1_date->setText(QString());
        forecast_1_type->setText(QString());
        forecast_1_temp->setText(QString());
        forecast_2_date->setText(QString());
        forecast_2_type->setText(QString());
        forecast_2_temp->setText(QString());
        forecast_3_date->setText(QString());
        forecast_3_type->setText(QString());
        forecast_3_temp->setText(QString());
        forecast_4_date->setText(QString());
        forecast_4_type->setText(QString());
        forecast_4_temp->setText(QString());
        label->setText(QString());
        sunrise->setText(QString());
        label_2->setText(QString());
        sunset->setText(QString());
        label_3->setText(QString());
        shidu->setText(QString());
        fengxiang->setText(QString());
        fengli->setText(QString());
        label_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        updateButton->setToolTip(QApplication::translate("MainWindow", "\346\215\242\350\202\244", 0));
#endif // QT_NO_TOOLTIP
        updateButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
