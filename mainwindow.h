#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlTableModel>
#include <QCalendarWidget>
#include "crmmodel.h"



#include "neworder.h"
#include "delorderdialog.h"


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


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_addOrderButton_clicked();

    void on_delButton_clicked();

    void orderAccepted();

//    void slotDelOrder();


    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;

    newOrder *new_o;
    delOrderDialog *del_o;




};

#endif // MAINWINDOW_H
