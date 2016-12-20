/********************************************************************************
** Form generated from reading UI file 'newdiscount.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDISCOUNT_H
#define UI_NEWDISCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newdiscount
{
public:
    QPushButton *cancelDiscountPushButton;
    QPushButton *acceptDiscountPushButton;
    QLineEdit *cardidlineEdit;
    QLabel *label;
    QLineEdit *clientNameLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *clientAdressLineEdit;
    QLabel *label_4;
    QLineEdit *EmailLineEdit;
    QLabel *label_5;
    QLineEdit *clientPhonelineEdit;
    QLabel *label_6;
    QLineEdit *DescriptionLineEdit;
    QCheckBox *activeCheckBox;
    QTableView *relationDiscontOrderTableView;

    void setupUi(QWidget *newdiscount)
    {
        if (newdiscount->objectName().isEmpty())
            newdiscount->setObjectName(QStringLiteral("newdiscount"));
        newdiscount->resize(1083, 486);
        cancelDiscountPushButton = new QPushButton(newdiscount);
        cancelDiscountPushButton->setObjectName(QStringLiteral("cancelDiscountPushButton"));
        cancelDiscountPushButton->setGeometry(QRect(30, 440, 99, 27));
        acceptDiscountPushButton = new QPushButton(newdiscount);
        acceptDiscountPushButton->setObjectName(QStringLiteral("acceptDiscountPushButton"));
        acceptDiscountPushButton->setGeometry(QRect(140, 440, 99, 27));
        cardidlineEdit = new QLineEdit(newdiscount);
        cardidlineEdit->setObjectName(QStringLiteral("cardidlineEdit"));
        cardidlineEdit->setGeometry(QRect(110, 20, 113, 27));
        label = new QLabel(newdiscount);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 67, 17));
        clientNameLineEdit = new QLineEdit(newdiscount);
        clientNameLineEdit->setObjectName(QStringLiteral("clientNameLineEdit"));
        clientNameLineEdit->setGeometry(QRect(110, 60, 113, 27));
        label_2 = new QLabel(newdiscount);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(16, 60, 81, 20));
        label_3 = new QLabel(newdiscount);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 91, 20));
        clientAdressLineEdit = new QLineEdit(newdiscount);
        clientAdressLineEdit->setObjectName(QStringLiteral("clientAdressLineEdit"));
        clientAdressLineEdit->setGeometry(QRect(110, 100, 113, 27));
        label_4 = new QLabel(newdiscount);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 130, 81, 20));
        EmailLineEdit = new QLineEdit(newdiscount);
        EmailLineEdit->setObjectName(QStringLiteral("EmailLineEdit"));
        EmailLineEdit->setGeometry(QRect(110, 140, 113, 27));
        label_5 = new QLabel(newdiscount);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 180, 91, 20));
        clientPhonelineEdit = new QLineEdit(newdiscount);
        clientPhonelineEdit->setObjectName(QStringLiteral("clientPhonelineEdit"));
        clientPhonelineEdit->setGeometry(QRect(110, 180, 113, 27));
        label_6 = new QLabel(newdiscount);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 220, 81, 20));
        DescriptionLineEdit = new QLineEdit(newdiscount);
        DescriptionLineEdit->setObjectName(QStringLiteral("DescriptionLineEdit"));
        DescriptionLineEdit->setGeometry(QRect(110, 220, 113, 27));
        activeCheckBox = new QCheckBox(newdiscount);
        activeCheckBox->setObjectName(QStringLiteral("activeCheckBox"));
        activeCheckBox->setGeometry(QRect(120, 270, 97, 22));
        relationDiscontOrderTableView = new QTableView(newdiscount);
        relationDiscontOrderTableView->setObjectName(QStringLiteral("relationDiscontOrderTableView"));
        relationDiscontOrderTableView->setGeometry(QRect(270, 20, 801, 451));

        retranslateUi(newdiscount);

        QMetaObject::connectSlotsByName(newdiscount);
    } // setupUi

    void retranslateUi(QWidget *newdiscount)
    {
        newdiscount->setWindowTitle(QApplication::translate("newdiscount", "Form", 0));
        cancelDiscountPushButton->setText(QApplication::translate("newdiscount", "cancel", 0));
        acceptDiscountPushButton->setText(QApplication::translate("newdiscount", "ok", 0));
        label->setText(QApplication::translate("newdiscount", "card id", 0));
        label_2->setText(QApplication::translate("newdiscount", "client name", 0));
        label_3->setText(QApplication::translate("newdiscount", "client adress", 0));
        label_4->setText(QApplication::translate("newdiscount", "client email", 0));
        label_5->setText(QApplication::translate("newdiscount", "client phone", 0));
        label_6->setText(QApplication::translate("newdiscount", "description", 0));
        activeCheckBox->setText(QApplication::translate("newdiscount", "active", 0));
    } // retranslateUi

};

namespace Ui {
    class newdiscount: public Ui_newdiscount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDISCOUNT_H
