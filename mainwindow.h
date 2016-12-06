#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlTableModel>
#include <QCalendarWidget>
#include <QSqlRelationalDelegate>
#include <QSqlTableModel>
#include <QDebug>



#include "crmmodel.h"



#include "neworder.h"
#include "delorderdialog.h"
#include "workers.h"

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

private:
    Ui::MainWindow *ui;

    newOrder *new_o;
    delOrderDialog *del_o;
    workers *workers_window;


    int typeIndex;





};

#endif // MAINWINDOW_H
