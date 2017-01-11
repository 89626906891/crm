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
#include <QTimer>
#include <QSortFilterProxyModel>
#include <QMenu>
#include <QAction>
#include <QBoxLayout>
#include <QWidget>
#include <QTextCharFormat>

#include "crmmodel.h"
#include "neworder.h"
#include "delorderdialog.h"
#include "workers.h"
#include "discounts.h"
#include "checkboxdelegate.h"
//#include "comboboxstatusdelegate.h"
#include "phonenumberdelegate.h"
#include "salarydelegate.h"
#include "about.h"
#include "history.h"
#include "buttondelegate.h"
#include "loggingcategories.h"
#include "movetocenter.h"
#include "crmusers.h"
//#include "crmuserdelegate.h"
#include "uploadfileform.h"
#include "authdialog.h"
#include "contactsform.h"


class AuthDialog;


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


    void on_calendarWidget_clicked(const QDate &date = QDate::currentDate()); //сколько заказов на выбранный день, по умолчанию ткущий день
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

//    void moveToCenter(QWidget& widget); //перегрузка функций
//    void moveToCenter(QWidget* widget);//отцентровка открывающихся окон

    void setUserLogout();
    void whoOnline();
    void showOrdersForToday();


    void on_logoutPushButton_clicked();

    void on_actionLogout_triggered();


    void on_lastOrdersPushButton_clicked();

    void on_lastCancelOrdersPushButton_clicked();

    void slotRightClickMenuRequested(QPoint pos); //меню по правой кнопки крысы


    void on_actionHistoryLog_triggered();

    void on_actionCRMusers_triggered();

    void uploadFile();
    void startUpload(int ID,QString NAME);


    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();
    void on_b0_clicked();
    void on_bzvezda_clicked();
    void on_breshotka_clicked();



    void on_delPhoneCharPushButton_clicked();

    void on_actionContacts_triggered();

private:
    Ui::MainWindow *ui;

    newOrder *new_o;
    delOrderDialog *del_o;
    workers *workers_window;
    discounts *discounts_window;
    about *about_window;
    history *history_window;
    CRMusers *crmusers_window;

    QString clickedDay;
    int typeIndex;
  //  QSqlQuery *todayOrdersQuery;
    QSqlQuery *currentDayTotalOrdersQuery;

    QString userOnline; //сюда переписываем кто сейчас онлайн из окна авторизации
    uploadFileForm *uploadFile_window;
    AuthDialog *newauth;
    ContactsForm *contacts_window;


protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
