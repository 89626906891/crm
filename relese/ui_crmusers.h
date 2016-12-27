/********************************************************************************
** Form generated from reading UI file 'crmusers.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRMUSERS_H
#define UI_CRMUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRMusers
{
public:
    QTableView *tableView;
    QPushButton *addCrmUserPushButton;

    void setupUi(QWidget *CRMusers)
    {
        if (CRMusers->objectName().isEmpty())
            CRMusers->setObjectName(QStringLiteral("CRMusers"));
        CRMusers->resize(719, 449);
        tableView = new QTableView(CRMusers);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 60, 681, 371));
        addCrmUserPushButton = new QPushButton(CRMusers);
        addCrmUserPushButton->setObjectName(QStringLiteral("addCrmUserPushButton"));
        addCrmUserPushButton->setGeometry(QRect(20, 10, 99, 27));

        retranslateUi(CRMusers);

        QMetaObject::connectSlotsByName(CRMusers);
    } // setupUi

    void retranslateUi(QWidget *CRMusers)
    {
        CRMusers->setWindowTitle(QApplication::translate("CRMusers", "Form", 0));
        addCrmUserPushButton->setText(QApplication::translate("CRMusers", "addCrmUser", 0));
    } // retranslateUi

};

namespace Ui {
    class CRMusers: public Ui_CRMusers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRMUSERS_H
