#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlTableModel>
#include <QCalendarWidget>
#include <QSqlRelationalDelegate>

#include <QSqlTableModel>
#include <QDebug>
#include <QSqlRecord>
#include <QDesktopWidget>
#include <QRect>
#include <QPoint>

#include "crmmodel.h"
#include "neworder.h"
#include "delorderdialog.h"
#include "workers.h"
#include "discounts.h"
#include "checkboxdelegate.h"
#include "about.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CRMModel *model;
    void setUserOnline(QString user); //получаем из окна авторизации кто залогинелся


private slots:



    void on_addOrderButton_clicked();

    void on_delButton_clicked();

    void orderAccepted();
    void orderCancled();

//    void slotDelOrder();


    void on_calendarWidget_clicked(const QDate &date);
    void on_actionAdd_worker_triggered();
    void on_editOrderPushButton_clicked();
    void on_pushButton_clicked();
    void on_actionAdd_order_triggered();
    void on_actionExit_triggered();
    void slot_comboWorkersBox_currentIndexChanged(const QString &arg1);

    //void on_todayPushButton_clicked();

    void on_todayPushButton_clicked();
    void on_actionAddDiscount_triggered();
    void on_actionInfo_triggered();
    void moveToCenter(); //отцентровка открывающихся окон

    void setUserLogout();
    void whoOnline();



private:
    Ui::MainWindow *ui;

    newOrder *new_o;
    delOrderDialog *del_o;
    workers *workers_window;
    discounts *discounts_window;
    about *about_window;

    QString clickedDay;
    int typeIndex;
    QSqlQuery *todayOrdersQuery;
    QSqlQuery *currentDayTotalOrdersQuery;

    QString userOnline; //сюда переписываем кто сейчас онлайн из окна авторизации






    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
