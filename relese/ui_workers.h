/********************************************************************************
** Form generated from reading UI file 'workers.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERS_H
#define UI_WORKERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_workers
{
public:
    QPushButton *addWorkerPushButton;
    QTableView *workersTableView;

    void setupUi(QWidget *workers)
    {
        if (workers->objectName().isEmpty())
            workers->setObjectName(QStringLiteral("workers"));
        workers->resize(520, 399);
        addWorkerPushButton = new QPushButton(workers);
        addWorkerPushButton->setObjectName(QStringLiteral("addWorkerPushButton"));
        addWorkerPushButton->setGeometry(QRect(400, 20, 99, 27));
        workersTableView = new QTableView(workers);
        workersTableView->setObjectName(QStringLiteral("workersTableView"));
        workersTableView->setGeometry(QRect(10, 70, 501, 321));

        retranslateUi(workers);

        QMetaObject::connectSlotsByName(workers);
    } // setupUi

    void retranslateUi(QWidget *workers)
    {
        workers->setWindowTitle(QApplication::translate("workers", "Form", 0));
        addWorkerPushButton->setText(QApplication::translate("workers", "add worker", 0));
    } // retranslateUi

};

namespace Ui {
    class workers: public Ui_workers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERS_H
