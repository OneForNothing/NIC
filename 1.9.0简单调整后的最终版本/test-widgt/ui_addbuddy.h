/********************************************************************************
** Form generated from reading UI file 'addbuddy.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBUDDY_H
#define UI_ADDBUDDY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Addbuddy
{
public:
    QPushButton *search;
    QPushButton *quit;
    QLineEdit *uidsearch;
    QLabel *label;

    void setupUi(QDialog *Addbuddy)
    {
        if (Addbuddy->objectName().isEmpty())
            Addbuddy->setObjectName(QStringLiteral("Addbuddy"));
        Addbuddy->resize(529, 348);
        Addbuddy->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border-image: url(:/image-3/\346\263\250\345\206\214\350\203\214\346\231\257.jpg);}"));
        search = new QPushButton(Addbuddy);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(90, 230, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(16);
        search->setFont(font);
        quit = new QPushButton(Addbuddy);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(310, 230, 141, 51));
        quit->setFont(font);
        uidsearch = new QLineEdit(Addbuddy);
        uidsearch->setObjectName(QStringLiteral("uidsearch"));
        uidsearch->setGeometry(QRect(250, 100, 191, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        uidsearch->setFont(font1);
        label = new QLabel(Addbuddy);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 100, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\347\256\200\346\245\267\344\275\223"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        retranslateUi(Addbuddy);

        QMetaObject::connectSlotsByName(Addbuddy);
    } // setupUi

    void retranslateUi(QDialog *Addbuddy)
    {
        Addbuddy->setWindowTitle(QApplication::translate("Addbuddy", "Dialog", 0));
        search->setText(QApplication::translate("Addbuddy", "\347\241\256\345\256\232", 0));
        quit->setText(QApplication::translate("Addbuddy", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("Addbuddy", "uid\346\237\245\346\211\276\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Addbuddy: public Ui_Addbuddy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBUDDY_H
