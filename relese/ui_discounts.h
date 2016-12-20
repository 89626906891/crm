/********************************************************************************
** Form generated from reading UI file 'discounts.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCOUNTS_H
#define UI_DISCOUNTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_discounts
{
public:
    QPushButton *addDiscountPushButton;
    QTableView *discountsTableView;
    QPushButton *findDiscountButton;
    QLineEdit *findDiscountLineEdit;
    QLabel *label;

    void setupUi(QWidget *discounts)
    {
        if (discounts->objectName().isEmpty())
            discounts->setObjectName(QStringLiteral("discounts"));
        discounts->resize(1416, 441);
        addDiscountPushButton = new QPushButton(discounts);
        addDiscountPushButton->setObjectName(QStringLiteral("addDiscountPushButton"));
        addDiscountPushButton->setGeometry(QRect(20, 30, 99, 27));
        discountsTableView = new QTableView(discounts);
        discountsTableView->setObjectName(QStringLiteral("discountsTableView"));
        discountsTableView->setGeometry(QRect(10, 90, 1401, 341));
        findDiscountButton = new QPushButton(discounts);
        findDiscountButton->setObjectName(QStringLiteral("findDiscountButton"));
        findDiscountButton->setGeometry(QRect(440, 30, 99, 27));
        findDiscountLineEdit = new QLineEdit(discounts);
        findDiscountLineEdit->setObjectName(QStringLiteral("findDiscountLineEdit"));
        findDiscountLineEdit->setGeometry(QRect(300, 30, 131, 27));
        label = new QLabel(discounts);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 30, 121, 31));

        retranslateUi(discounts);

        QMetaObject::connectSlotsByName(discounts);
    } // setupUi

    void retranslateUi(QWidget *discounts)
    {
        discounts->setWindowTitle(QApplication::translate("discounts", "Form", 0));
        addDiscountPushButton->setText(QApplication::translate("discounts", "add discount", 0));
        findDiscountButton->setText(QApplication::translate("discounts", "find", 0));
        label->setText(QApplication::translate("discounts", "type ID here ->", 0));
    } // retranslateUi

};

namespace Ui {
    class discounts: public Ui_discounts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCOUNTS_H
