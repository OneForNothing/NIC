/********************************************************************************
** Form generated from reading UI file 'filesender.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESENDER_H
#define UI_FILESENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_filesender
{
public:
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QDialog *filesender)
    {
        if (filesender->objectName().isEmpty())
            filesender->setObjectName(QStringLiteral("filesender"));
        filesender->resize(430, 313);
        label = new QLabel(filesender);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 70, 201, 71));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        progressBar = new QProgressBar(filesender);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(80, 190, 241, 41));
        progressBar->setValue(0);

        retranslateUi(filesender);

        QMetaObject::connectSlotsByName(filesender);
    } // setupUi

    void retranslateUi(QDialog *filesender)
    {
        filesender->setWindowTitle(QApplication::translate("filesender", "Dialog", 0));
        label->setText(QApplication::translate("filesender", "\345\207\206\345\244\207\344\270\213\345\217\221\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class filesender: public Ui_filesender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESENDER_H
