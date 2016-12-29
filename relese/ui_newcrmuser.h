/********************************************************************************
** Form generated from reading UI file 'newcrmuser.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCRMUSER_H
#define UI_NEWCRMUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newCrmUser
{
public:
    QLineEdit *namelineEdit;
    QLineEdit *loginlineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *cancelpushButton;
    QPushButton *okpushButton;
    QCheckBox *accesscheckBox;
    QLabel *label_3;
    QLineEdit *passwordlineEdit;
    QCheckBox *activecheckBox;
    QLineEdit *paymentPasswordlineEdit;
    QLabel *label_4;

    void setupUi(QWidget *newCrmUser)
    {
        if (newCrmUser->objectName().isEmpty())
            newCrmUser->setObjectName(QStringLiteral("newCrmUser"));
        newCrmUser->resize(535, 356);
        namelineEdit = new QLineEdit(newCrmUser);
        namelineEdit->setObjectName(QStringLiteral("namelineEdit"));
        namelineEdit->setGeometry(QRect(180, 20, 331, 27));
        loginlineEdit = new QLineEdit(newCrmUser);
        loginlineEdit->setObjectName(QStringLiteral("loginlineEdit"));
        loginlineEdit->setGeometry(QRect(180, 50, 331, 27));
        label = new QLabel(newCrmUser);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 20, 67, 17));
        label_2 = new QLabel(newCrmUser);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 50, 67, 17));
        cancelpushButton = new QPushButton(newCrmUser);
        cancelpushButton->setObjectName(QStringLiteral("cancelpushButton"));
        cancelpushButton->setGeometry(QRect(250, 310, 99, 27));
        okpushButton = new QPushButton(newCrmUser);
        okpushButton->setObjectName(QStringLiteral("okpushButton"));
        okpushButton->setGeometry(QRect(360, 310, 99, 27));
        accesscheckBox = new QCheckBox(newCrmUser);
        accesscheckBox->setObjectName(QStringLiteral("accesscheckBox"));
        accesscheckBox->setGeometry(QRect(140, 260, 97, 22));
        label_3 = new QLabel(newCrmUser);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 80, 67, 17));
        passwordlineEdit = new QLineEdit(newCrmUser);
        passwordlineEdit->setObjectName(QStringLiteral("passwordlineEdit"));
        passwordlineEdit->setGeometry(QRect(180, 80, 331, 27));
        passwordlineEdit->setEchoMode(QLineEdit::Password);
        activecheckBox = new QCheckBox(newCrmUser);
        activecheckBox->setObjectName(QStringLiteral("activecheckBox"));
        activecheckBox->setGeometry(QRect(140, 290, 97, 22));
        paymentPasswordlineEdit = new QLineEdit(newCrmUser);
        paymentPasswordlineEdit->setObjectName(QStringLiteral("paymentPasswordlineEdit"));
        paymentPasswordlineEdit->setGeometry(QRect(180, 110, 331, 27));
        paymentPasswordlineEdit->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(newCrmUser);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 131, 17));

        retranslateUi(newCrmUser);

        QMetaObject::connectSlotsByName(newCrmUser);
    } // setupUi

    void retranslateUi(QWidget *newCrmUser)
    {
        newCrmUser->setWindowTitle(QApplication::translate("newCrmUser", "Form", 0));
        label->setText(QApplication::translate("newCrmUser", "name:", 0));
        label_2->setText(QApplication::translate("newCrmUser", "login:", 0));
        cancelpushButton->setText(QApplication::translate("newCrmUser", "cancel", 0));
        okpushButton->setText(QApplication::translate("newCrmUser", "ok", 0));
        accesscheckBox->setText(QApplication::translate("newCrmUser", "full access", 0));
        label_3->setText(QApplication::translate("newCrmUser", "password", 0));
        activecheckBox->setText(QApplication::translate("newCrmUser", "isActive", 0));
        label_4->setText(QApplication::translate("newCrmUser", "payment password:", 0));
    } // retranslateUi

};

namespace Ui {
    class newCrmUser: public Ui_newCrmUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCRMUSER_H
