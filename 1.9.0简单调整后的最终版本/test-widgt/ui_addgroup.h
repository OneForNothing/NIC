/********************************************************************************
** Form generated from reading UI file 'addgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUP_H
#define UI_ADDGROUP_H

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

class Ui_addgroup
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *addgroup)
    {
        if (addgroup->objectName().isEmpty())
            addgroup->setObjectName(QStringLiteral("addgroup"));
        addgroup->resize(529, 348);
        pushButton = new QPushButton(addgroup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 230, 93, 28));
        pushButton_2 = new QPushButton(addgroup);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 230, 93, 28));
        label = new QLabel(addgroup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 70, 341, 41));
        lineEdit = new QLineEdit(addgroup);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 150, 291, 31));

        retranslateUi(addgroup);

        QMetaObject::connectSlotsByName(addgroup);
    } // setupUi

    void retranslateUi(QDialog *addgroup)
    {
        addgroup->setWindowTitle(QApplication::translate("addgroup", "Dialog", 0));
        pushButton->setText(QApplication::translate("addgroup", "\347\241\256\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("addgroup", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("addgroup", "\350\257\267\350\276\223\345\205\245\344\275\240\350\246\201\351\202\200\350\257\267\345\257\271\350\261\241\347\232\204uid\357\274\214\344\273\245:\345\210\206\351\232\224", 0));
    } // retranslateUi

};

namespace Ui {
    class addgroup: public Ui_addgroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUP_H
