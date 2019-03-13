/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QPushButton *openButton;
    QPushButton *sendButton;
    QLabel *clientStatusLabel;
    QProgressBar *clientProgressBar;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(430, 348);
        openButton = new QPushButton(Client);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(50, 240, 111, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        openButton->setFont(font);
        sendButton = new QPushButton(Client);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(232, 240, 111, 41));
        sendButton->setFont(font);
        clientStatusLabel = new QLabel(Client);
        clientStatusLabel->setObjectName(QStringLiteral("clientStatusLabel"));
        clientStatusLabel->setGeometry(QRect(50, 150, 311, 71));
        clientStatusLabel->setFont(font);
        clientProgressBar = new QProgressBar(Client);
        clientProgressBar->setObjectName(QStringLiteral("clientProgressBar"));
        clientProgressBar->setGeometry(QRect(30, 50, 391, 71));
        clientProgressBar->setValue(0);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        openButton->setText(QApplication::translate("Client", "\346\211\223\345\274\200", 0));
        sendButton->setText(QApplication::translate("Client", "\345\217\221\351\200\201", 0));
        clientStatusLabel->setText(QApplication::translate("Client", "\347\212\266\346\200\201\357\274\232\347\255\211\345\276\205\346\211\223\345\274\200\346\226\207\344\273\266\343\200\202\343\200\202\343\200\202", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
