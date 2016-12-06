#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
//#include <QSqlQuery>
#include <QDateTime>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QSqlDatabase baze = QSqlDatabase::database();//baze.database();
    Q_ASSERT(baze.isOpen());

    model = new CRMModel(this,baze);
    ui->tableView->setModel(model);
  //  ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->hideColumn(0);
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("name"),new QSqlRelationalDelegate(ui->tableView)); //для combobox работники

    new_o = new newOrder();
    new_o->setParent(this,Qt::Window);
    new_o->setModel(model);



    ui->calendarWidget = new QCalendarWidget();
    model->setFilter(QString("exec_date = '%1'").arg(QDate::currentDate().toString("yyyy-MM-dd"))); //установка фильтра модели на текущую дату

    connect(new_o,SIGNAL(ready()),this,SLOT(orderAccepted()));
    connect(new_o,SIGNAL(signalCancelOrder()),this,SLOT(orderCancled()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addOrderButton_clicked()
{
    const int row = model->rowCount();
    qDebug() << "inserting row" <<  model->insertRow(row);
    new_o->mapper->setCurrentModelIndex(model->index(row,0));
    new_o->show();
}

void MainWindow::orderAccepted()
{

    qDebug() << "adding new order" << model->submitAll();

}

void MainWindow::orderCancled()
{
    qDebug() << "cancel" << model->submitAll();
}



void MainWindow::on_delButton_clicked()
{

  int selectedRow = ui->tableView->currentIndex().row();
  if (selectedRow >=0)
  {
    int n = QMessageBox::warning(0,
    "Warning",
    "DELETE ORDER????"
    "\n Do you want to save the changes?",
    "Yes",
    "No",
     QString(),
     0,
     1
     );
     if(!n)
     {
        qDebug() << "deleting row:" << model->removeRow(selectedRow);
        model->submitAll();
     }
     else
     {
        qDebug() << "deleting cancled";
        model->submitAll();
     }

   }
   else
     {
        qDebug() << "no row selected";
        QMessageBox::warning(0,"warning","вы не выбрали ни одного заказа!!!",QMessageBox::Cancel);

      }
}



void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    model->setFilter(QString("exec_date = '%1'").arg(date.toString("yyyy-MM-dd")));
    qDebug() <<"selected:" << date.toString("yyyy-MM-dd");

}

void MainWindow::on_actionAdd_worker_triggered()
{
    workers_window = new workers;
    workers_window->show();
}

void MainWindow::on_editOrderPushButton_clicked()
{
    int selectedOrder = ui->tableView->currentIndex().row();
    qDebug() << "order to edit = " <<selectedOrder;
    new_o->mapper->setCurrentModelIndex(model->index(selectedOrder,0));
    new_o->show();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "OK clicked";
    model->submitAll();
//    ui->tableView->selectAll();
}

void MainWindow::on_actionAdd_order_triggered()
{
    const int row = model->rowCount();
    qDebug() << "inserting row" <<  model->insertRow(row);
    new_o->mapper->setCurrentModelIndex(model->index(row,0));
    new_o->show();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
