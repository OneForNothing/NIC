/********************************************************************************
** Form generated from reading UI file 'filereceiver.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERECEIVER_H
#define UI_FILERECEIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_filereceiver
{
public:
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QDialog *filereceiver)
    {
        if (filereceiver->objectName().isEmpty())
            filereceiver->setObjectName(QStringLiteral("filereceiver"));
        filereceiver->resize(400, 300);
        progressBar = new QProgressBar(filereceiver);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(60, 190, 281, 31));
        progressBar->setValue(0);
        label = new QLabel(filereceiver);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 271, 51));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        retranslateUi(filereceiver);

        QMetaObject::connectSlotsByName(filereceiver);
    } // setupUi

    void retranslateUi(QDialog *filereceiver)
    {
        filereceiver->setWindowTitle(QApplication::translate("filereceiver", "Dialog", 0));
        label->setText(QApplication::translate("filereceiver", "\346\226\207\344\273\266\346\216\245\346\224\266\344\270\255", 0));
    } // retranslateUi

};

namespace Ui {
    class filereceiver: public Ui_filereceiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERECEIVER_H
