/********************************************************************************
** Form generated from reading UI file 'neworder.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWORDER_H
#define UI_NEWORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newOrder
{
public:
    QPushButton *applyButton;
    QPushButton *closeButton;
    QLineEdit *adressLineEdit;
    QTextEdit *orderTextEdit;
    QLineEdit *phoneLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *execDateEdit;
    QLabel *label_4;
    QComboBox *workerComboBox;
    QTimeEdit *timeEdit;
    QLabel *label_5;
    QLabel *label_6;
    QTimeEdit *timeEdit2;
    QSpinBox *spinBox;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *phone2lineEdit;
    QPushButton *plusPushButton;
    QPushButton *minusPushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;

    void setupUi(QWidget *newOrder)
    {
        if (newOrder->objectName().isEmpty())
            newOrder->setObjectName(QStringLiteral("newOrder"));
        newOrder->resize(959, 693);
        applyButton = new QPushButton(newOrder);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(680, 400, 99, 27));
        closeButton = new QPushButton(newOrder);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(780, 400, 99, 27));
        adressLineEdit = new QLineEdit(newOrder);
        adressLineEdit->setObjectName(QStringLiteral("adressLineEdit"));
        adressLineEdit->setGeometry(QRect(620, 10, 251, 27));
        orderTextEdit = new QTextEdit(newOrder);
        orderTextEdit->setObjectName(QStringLiteral("orderTextEdit"));
        orderTextEdit->setGeometry(QRect(620, 47, 251, 111));
        phoneLineEdit = new QLineEdit(newOrder);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));
        phoneLineEdit->setGeometry(QRect(620, 160, 251, 27));
        label = new QLabel(newOrder);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 60, 67, 17));
        label_2 = new QLabel(newOrder);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 10, 67, 17));
        label_3 = new QLabel(newOrder);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(540, 160, 67, 17));
        execDateEdit = new QDateEdit(newOrder);
        execDateEdit->setObjectName(QStringLiteral("execDateEdit"));
        execDateEdit->setGeometry(QRect(620, 230, 110, 27));
        label_4 = new QLabel(newOrder);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 230, 67, 17));
        workerComboBox = new QComboBox(newOrder);
        workerComboBox->setObjectName(QStringLiteral("workerComboBox"));
        workerComboBox->setGeometry(QRect(520, 400, 131, 27));
        timeEdit = new QTimeEdit(newOrder);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(540, 280, 118, 27));
        label_5 = new QLabel(newOrder);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(500, 280, 67, 17));
        label_6 = new QLabel(newOrder);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(690, 280, 67, 17));
        timeEdit2 = new QTimeEdit(newOrder);
        timeEdit2->setObjectName(QStringLiteral("timeEdit2"));
        timeEdit2->setGeometry(QRect(710, 280, 118, 27));
        spinBox = new QSpinBox(newOrder);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(550, 360, 121, 27));
        spinBox->setMaximum(999999999);
        label_7 = new QLabel(newOrder);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(510, 360, 31, 17));
        label_8 = new QLabel(newOrder);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 200, 67, 17));
        phone2lineEdit = new QLineEdit(newOrder);
        phone2lineEdit->setObjectName(QStringLiteral("phone2lineEdit"));
        phone2lineEdit->setGeometry(QRect(620, 190, 251, 27));
        plusPushButton = new QPushButton(newOrder);
        plusPushButton->setObjectName(QStringLiteral("plusPushButton"));
        plusPushButton->setGeometry(QRect(10, 40, 31, 31));
        minusPushButton = new QPushButton(newOrder);
        minusPushButton->setObjectName(QStringLiteral("minusPushButton"));
        minusPushButton->setGeometry(QRect(10, 80, 31, 31));
        formLayoutWidget = new QWidget(newOrder);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 20, 441, 661));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(newOrder);

        QMetaObject::connectSlotsByName(newOrder);
    } // setupUi

    void retranslateUi(QWidget *newOrder)
    {
        newOrder->setWindowTitle(QApplication::translate("newOrder", "Form", 0));
        applyButton->setText(QApplication::translate("newOrder", "apply", 0));
        closeButton->setText(QApplication::translate("newOrder", "close", 0));
        label->setText(QApplication::translate("newOrder", "order", 0));
        label_2->setText(QApplication::translate("newOrder", "adress", 0));
        label_3->setText(QApplication::translate("newOrder", "phone", 0));
        label_4->setText(QApplication::translate("newOrder", "exec date", 0));
        label_5->setText(QApplication::translate("newOrder", "from", 0));
        label_6->setText(QApplication::translate("newOrder", "till", 0));
        label_7->setText(QApplication::translate("newOrder", "$$$", 0));
        label_8->setText(QApplication::translate("newOrder", "phone2", 0));
        plusPushButton->setText(QApplication::translate("newOrder", "+", 0));
        minusPushButton->setText(QApplication::translate("newOrder", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class newOrder: public Ui_newOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWORDER_H
