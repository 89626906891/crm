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

//    QSqlDatabase baze = QSqlDatabase::addDatabase("QMYSQL");
//    baze.setHostName("localhost");
//    baze.setDatabaseName("CRM");
//    baze.setUserName("root");
//    baze.setPassword("qqwwee");
//    if(!baze.open())
//    {
//        qDebug() << baze.lastError().text();
//    }
//    else{
//        qDebug() << "ok";
//    }

    QSqlDatabase baze = QSqlDatabase::database();//baze.database();
    Q_ASSERT(baze.isOpen());
//    model =  new QSqlTableModel(this,baze);
//    model->setTable("orders");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();
    model = new CRMModel(this,baze);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(4);

    new_o = new newOrder();
    new_o->setParent(this,Qt::Window);
    new_o->setModel(model);


    ui->calendarWidget = new QCalendarWidget();

    connect(new_o,SIGNAL(ready()),this,SLOT(orderAccepted()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

    new_o->mapper->setCurrentModelIndex(index);
    new_o->show();
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
     }

   }
   else
     {
        qDebug() << "no row selected";
        QMessageBox::warning(0,"warning","вы не выбрали ни одного заказа!!!",QMessageBox::Cancel);

      }
}





   //


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QMessageBox::information(NULL,"вы выбрали дату:",date.toString());
   //model->setFilter("exec_date="+date.toString("yyyy-MM-dd"));
  // setFilter("'date2'>" + date.toString("'yyyy-MM-dd'"));
  // model->select();

}
