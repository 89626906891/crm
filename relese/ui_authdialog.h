/********************************************************************************
** Form generated from reading UI file 'authdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHDIALOG_H
#define UI_AUTHDIALOG_H

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

class Ui_AuthDialog
{
public:
    QPushButton *enterButton;
    QLabel *connectLabel;
    QLineEdit *passwordLineEdit;
    QLineEdit *loginLineEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AuthDialog)
    {
        if (AuthDialog->objectName().isEmpty())
            AuthDialog->setObjectName(QStringLiteral("AuthDialog"));
        AuthDialog->resize(284, 202);
        enterButton = new QPushButton(AuthDialog);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        enterButton->setGeometry(QRect(90, 130, 99, 27));
        connectLabel = new QLabel(AuthDialog);
        connectLabel->setObjectName(QStringLiteral("connectLabel"));
        connectLabel->setGeometry(QRect(10, 180, 251, 16));
        passwordLineEdit = new QLineEdit(AuthDialog);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(110, 90, 131, 27));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        loginLineEdit = new QLineEdit(AuthDialog);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(110, 50, 131, 27));
        label = new QLabel(AuthDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 51, 27));
        label_2 = new QLabel(AuthDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 91, 71, 31));

        retranslateUi(AuthDialog);

        QMetaObject::connectSlotsByName(AuthDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthDialog)
    {
        AuthDialog->setWindowTitle(QApplication::translate("AuthDialog", "AuthDialog", 0));
        enterButton->setText(QApplication::translate("AuthDialog", "\320\222\321\205\320\276\320\264", 0));
        connectLabel->setText(QApplication::translate("AuthDialog", "TextLabel", 0));
        label->setText(QApplication::translate("AuthDialog", "\320\233\320\276\320\263\320\270\320\275:", 0));
        label_2->setText(QApplication::translate("AuthDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0));
    } // retranslateUi

};

namespace Ui {
    class AuthDialog: public Ui_AuthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHDIALOG_H
