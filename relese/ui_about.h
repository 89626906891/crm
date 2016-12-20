/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(276, 163);
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 50, 141, 51));
        pushButton = new QPushButton(about);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 110, 99, 27));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QWidget *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Form", 0));
        label->setText(QApplication::translate("about", "<html><head/><body><p>by <span style=\" font-weight:600;\">Smirnov Alexey </span></p><p>All  rights reserved</p></body></html>", 0));
        pushButton->setText(QApplication::translate("about", "ok", 0));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
