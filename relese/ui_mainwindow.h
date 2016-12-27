/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_order;
    QAction *actionExit;
    QAction *actionInfo;
    QAction *actionAdd_worker;
    QAction *actionAddDiscount;
    QAction *actionLogout;
    QAction *actionHistoryLog;
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *addOrderButton;
    QPushButton *delButton;
    QCalendarWidget *calendarWidget;
    QPushButton *editOrderPushButton;
    QPushButton *pushButton;
    QComboBox *ComboWorkersBox;
    QPushButton *todayPushButton;
    QFrame *frame;
    QLabel *ordersForTodaylabel;
    QLabel *currentDayordersLabel;
    QLabel *currentDayordersLabel_3;
    QLabel *findDatelabel;
    QLabel *currentDayordersLabel_2;
    QLabel *label;
    QPushButton *logoutPushButton;
    QPushButton *lastOrdersPushButton;
    QPushButton *lastCancelOrdersPushButton;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuAbout;
    QMenu *menuWorkers;
    QMenu *menuDiscount;
    QMenu *menuSystem;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1741, 1036);
        actionAdd_order = new QAction(MainWindow);
        actionAdd_order->setObjectName(QStringLiteral("actionAdd_order"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionAdd_worker = new QAction(MainWindow);
        actionAdd_worker->setObjectName(QStringLiteral("actionAdd_worker"));
        actionAddDiscount = new QAction(MainWindow);
        actionAddDiscount->setObjectName(QStringLiteral("actionAddDiscount"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionHistoryLog = new QAction(MainWindow);
        actionHistoryLog->setObjectName(QStringLiteral("actionHistoryLog"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 220, 1661, 751));
        addOrderButton = new QPushButton(centralwidget);
        addOrderButton->setObjectName(QStringLiteral("addOrderButton"));
        addOrderButton->setGeometry(QRect(530, 10, 151, 27));
        delButton = new QPushButton(centralwidget);
        delButton->setObjectName(QStringLiteral("delButton"));
        delButton->setGeometry(QRect(530, 40, 151, 27));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 491, 200));
        calendarWidget->setGridVisible(false);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        editOrderPushButton = new QPushButton(centralwidget);
        editOrderPushButton->setObjectName(QStringLiteral("editOrderPushButton"));
        editOrderPushButton->setGeometry(QRect(530, 70, 151, 27));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1680, 486, 51, 31));
        ComboWorkersBox = new QComboBox(centralwidget);
        ComboWorkersBox->setObjectName(QStringLiteral("ComboWorkersBox"));
        ComboWorkersBox->setGeometry(QRect(690, 170, 151, 27));
        todayPushButton = new QPushButton(centralwidget);
        todayPushButton->setObjectName(QStringLiteral("todayPushButton"));
        todayPushButton->setGeometry(QRect(530, 100, 151, 27));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(760, 10, 251, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ordersForTodaylabel = new QLabel(frame);
        ordersForTodaylabel->setObjectName(QStringLiteral("ordersForTodaylabel"));
        ordersForTodaylabel->setGeometry(QRect(196, 10, 51, 20));
        currentDayordersLabel = new QLabel(frame);
        currentDayordersLabel->setObjectName(QStringLiteral("currentDayordersLabel"));
        currentDayordersLabel->setGeometry(QRect(200, 40, 51, 16));
        currentDayordersLabel_3 = new QLabel(frame);
        currentDayordersLabel_3->setObjectName(QStringLiteral("currentDayordersLabel_3"));
        currentDayordersLabel_3->setGeometry(QRect(10, 40, 91, 17));
        findDatelabel = new QLabel(frame);
        findDatelabel->setObjectName(QStringLiteral("findDatelabel"));
        findDatelabel->setGeometry(QRect(110, 40, 81, 17));
        currentDayordersLabel_2 = new QLabel(centralwidget);
        currentDayordersLabel_2->setObjectName(QStringLiteral("currentDayordersLabel_2"));
        currentDayordersLabel_2->setGeometry(QRect(770, 20, 171, 17));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 166, 151, 31));
        logoutPushButton = new QPushButton(centralwidget);
        logoutPushButton->setObjectName(QStringLiteral("logoutPushButton"));
        logoutPushButton->setGeometry(QRect(530, 130, 151, 27));
        lastOrdersPushButton = new QPushButton(centralwidget);
        lastOrdersPushButton->setObjectName(QStringLiteral("lastOrdersPushButton"));
        lastOrdersPushButton->setGeometry(QRect(850, 170, 151, 27));
        lastCancelOrdersPushButton = new QPushButton(centralwidget);
        lastCancelOrdersPushButton->setObjectName(QStringLiteral("lastCancelOrdersPushButton"));
        lastCancelOrdersPushButton->setGeometry(QRect(1010, 170, 151, 27));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1741, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuWorkers = new QMenu(menuBar);
        menuWorkers->setObjectName(QStringLiteral("menuWorkers"));
        menuDiscount = new QMenu(menuBar);
        menuDiscount->setObjectName(QStringLiteral("menuDiscount"));
        menuSystem = new QMenu(menuBar);
        menuSystem->setObjectName(QStringLiteral("menuSystem"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuDiscount->menuAction());
        menuBar->addAction(menuWorkers->menuAction());
        menuBar->addAction(menuSystem->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuMenu->addAction(actionAdd_order);
        menuMenu->addAction(actionLogout);
        menuMenu->addAction(actionExit);
        menuAbout->addAction(actionInfo);
        menuWorkers->addAction(actionAdd_worker);
        menuDiscount->addAction(actionAddDiscount);
        menuSystem->addAction(actionHistoryLog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_order->setText(QApplication::translate("MainWindow", "add order", 0));
        actionExit->setText(QApplication::translate("MainWindow", "exit", 0));
        actionInfo->setText(QApplication::translate("MainWindow", "info", 0));
        actionAdd_worker->setText(QApplication::translate("MainWindow", "add worker", 0));
        actionAddDiscount->setText(QApplication::translate("MainWindow", "addDiscount", 0));
        actionLogout->setText(QApplication::translate("MainWindow", "logout", 0));
        actionHistoryLog->setText(QApplication::translate("MainWindow", "historyLog", 0));
        addOrderButton->setText(QApplication::translate("MainWindow", "add order", 0));
        delButton->setText(QApplication::translate("MainWindow", "del order", 0));
        editOrderPushButton->setText(QApplication::translate("MainWindow", "edit order", 0));
        pushButton->setText(QApplication::translate("MainWindow", "ok", 0));
        todayPushButton->setText(QApplication::translate("MainWindow", "today", 0));
        ordersForTodaylabel->setText(QString());
        currentDayordersLabel->setText(QString());
        currentDayordersLabel_3->setText(QApplication::translate("MainWindow", "\320\275\320\260\320\271\320\264\320\265\320\275\320\275\320\276 \320\275\320\260 ", 0));
        findDatelabel->setText(QString());
        currentDayordersLabel_2->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\275\320\276 \320\267\320\260 \321\201\320\265\320\263\320\276\320\264\320\275\321\217", 0));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260:", 0));
        logoutPushButton->setText(QApplication::translate("MainWindow", "logout", 0));
        lastOrdersPushButton->setText(QApplication::translate("MainWindow", "lastOrders", 0));
        lastCancelOrdersPushButton->setText(QApplication::translate("MainWindow", "lastCancelOrders", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "menu", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "about", 0));
        menuWorkers->setTitle(QApplication::translate("MainWindow", "workers", 0));
        menuDiscount->setTitle(QApplication::translate("MainWindow", "discount", 0));
        menuSystem->setTitle(QApplication::translate("MainWindow", "system", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
