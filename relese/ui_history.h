/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QTextBrowser *textBrowser;
    QPushButton *closeHistoryPushButton;

    void setupUi(QWidget *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName(QStringLiteral("history"));
        history->resize(752, 400);
        textBrowser = new QTextBrowser(history);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 731, 341));
        closeHistoryPushButton = new QPushButton(history);
        closeHistoryPushButton->setObjectName(QStringLiteral("closeHistoryPushButton"));
        closeHistoryPushButton->setGeometry(QRect(640, 10, 99, 27));

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QWidget *history)
    {
        history->setWindowTitle(QApplication::translate("history", "Form", 0));
        closeHistoryPushButton->setText(QApplication::translate("history", "close", 0));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
