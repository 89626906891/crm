/********************************************************************************
** Form generated from reading UI file 'newworker.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWORKER_H
#define UI_NEWWORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newworker
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *workerLineEdit;
    QLineEdit *workerLineEdit2;

    void setupUi(QWidget *newworker)
    {
        if (newworker->objectName().isEmpty())
            newworker->setObjectName(QStringLiteral("newworker"));
        newworker->resize(400, 300);
        pushButton = new QPushButton(newworker);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 250, 99, 27));
        pushButton_2 = new QPushButton(newworker);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 250, 99, 27));
        workerLineEdit = new QLineEdit(newworker);
        workerLineEdit->setObjectName(QStringLiteral("workerLineEdit"));
        workerLineEdit->setGeometry(QRect(30, 20, 113, 27));
        workerLineEdit2 = new QLineEdit(newworker);
        workerLineEdit2->setObjectName(QStringLiteral("workerLineEdit2"));
        workerLineEdit2->setGeometry(QRect(30, 60, 113, 27));

        retranslateUi(newworker);

        QMetaObject::connectSlotsByName(newworker);
    } // setupUi

    void retranslateUi(QWidget *newworker)
    {
        newworker->setWindowTitle(QApplication::translate("newworker", "Form", 0));
        pushButton->setText(QApplication::translate("newworker", "ok", 0));
        pushButton_2->setText(QApplication::translate("newworker", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class newworker: public Ui_newworker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWORKER_H
