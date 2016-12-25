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
    this->showMaximized();
    //moveToCenter(this);

    this->setWindowTitle("CRM");

    //получаем из базы кто сейчас онлайн
    //и создаем таймер который каждую секунду проверяет кто онлайн
    whoOnline();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(whoOnline()));
    timer->start(1000);




    QSqlDatabase baze = QSqlDatabase::database();//baze.database();
    Q_ASSERT(baze.isOpen());

    model = new CRMModel(this,baze);
    ui->tableView->setModel(model);
  //  ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->hideColumn(0);


    ui->tableView->setItemDelegateForColumn(model->fieldIndex("name"),new QSqlRelationalDelegate(ui->tableView)); //для combobox работники
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("status_name"),new QSqlRelationalDelegate(ui->tableView)); //для комбобокса со статусом заказа
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("payment_name"),new QSqlRelationalDelegate(ui->tableView)); //способ оплаты
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("phone"), new PhoneNumberDelegate(ui->tableView)); //делаем маску для телефона
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("phone2"), new PhoneNumberDelegate(ui->tableView));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("salary"), new salaryDelegate(ui->tableView)); //чтобы отображалась валюта
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("checked"),new CheckBoxDelegate(ui->tableView));  // устанавливаем делегат для checkbox checkboxdelegate.cpp

    new_o = new newOrder();
    new_o->setParent(this,Qt::Window);
    new_o->setModel(model);


    ui->calendarWidget = new QCalendarWidget();

    //выводим кол-во добавленных заказов за день(обновляем раз в секунду)
    showOrdersForToday();
    QTimer *timerShowOrders = new QTimer(this);
    connect(timerShowOrders, SIGNAL(timeout()), this, SLOT(showOrdersForToday()));
    timerShowOrders->start(1000);






    model->setFilter(QString("exec_date = '%1'").arg(QDate::currentDate().toString("yyyy-MM-dd"))); //установка фильтра модели на текущую дату

    //сколько заказов на выбранный день, по умолчанию текущий
    on_calendarWidget_clicked();

    //выбранный день (начальные настройки)
    ui->findDatelabel->setText(QDate::currentDate().toString("yyyy-MM-dd"));



    QSqlTableModel *comboModel = model->relationModel(10);
    ui->ComboWorkersBox->setModel(comboModel);
    ui->ComboWorkersBox->setModelColumn(comboModel->fieldIndex("name"));



    connect(new_o,SIGNAL(ready()),this,SLOT(orderAccepted()));
    connect(new_o,SIGNAL(signalCancelOrder()),this,SLOT(orderCancled()));
    connect(new_o,SIGNAL(sigClose()),this,SLOT(orderCancled()));
    connect(ui->ComboWorkersBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(slot_comboWorkersBox_currentIndexChanged(QString)));




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addOrderButton_clicked()
{
    const int row = model->rowCount();
//  qDebug() << "inserting row" <<  model->insertRow(row); //убрал т.к. иначе создает 2 новых поля :(
// возможно так нельзя делать

    QSqlRecord recordAddDate = model->record();
    recordAddDate.setValue(model->fieldIndex("add_date"),QDate::currentDate().toString("yyyy-MM-dd"));
    qDebug() << "filling add_date field" << model->insertRecord(row,recordAddDate);

    new_o->mapper->setCurrentModelIndex(model->index(row,0));
    new_o->show();
    moveToCenter(new_o);
}

void MainWindow::orderAccepted()
{

    qDebug() << "adding new order" << model->submitAll();

}

void MainWindow::orderCancled()
{
    qDebug() << "cancel";
    model->revertAll();
}


//не работают условия
void MainWindow::on_delButton_clicked()
{

  int selectedRow = ui->tableView->currentIndex().row();
  if (selectedRow >=0)
  {
    int n = QMessageBox::warning(0,
    "ВНИМАНИЕ",
    "ТОЧНО СТЕРЕТЬ ЗАКАЗ????"
    "\n ТЫ УВЕРЕН?",
    "ДА",
    "Нет",
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
    clickedDay = date.toString("yyyy-MM-dd");
    model->setFilter(QString("exec_date = '%1'").arg(date.toString("yyyy-MM-dd")));
    qDebug() <<"selected:" << date.toString("yyyy-MM-dd");
    //выводим кол-во заказов на выбранный день в календаре
    currentDayTotalOrdersQuery = new QSqlQuery;
    currentDayTotalOrdersQuery->prepare("SELECT * FROM orders WHERE exec_date = :d");
    currentDayTotalOrdersQuery->bindValue(":d", date.toString("yyyy-MM-dd"));
    currentDayTotalOrdersQuery->exec();
    int currentDayOrdersCounter = 0;
    while(currentDayTotalOrdersQuery->next())
    {
       currentDayOrdersCounter++;
    }
    QString currentDayOrderz = QString::number(currentDayOrdersCounter);
    ui->currentDayordersLabel->setText(currentDayOrderz);

    //меняем лэйбл с датой
    ui->findDatelabel->setText(date.toString("yyyy-MM-dd"));

}

void MainWindow::on_actionAdd_worker_triggered()
{
    workers_window = new workers;
    workers_window->show();
    moveToCenter(workers_window);
}

void MainWindow::on_editOrderPushButton_clicked()
{
    int selectedOrder = ui->tableView->currentIndex().row();
    if (selectedOrder >=0)
    {
        qDebug() << "order to edit = " << selectedOrder;
        new_o->mapper->setCurrentModelIndex(model->index(selectedOrder,0));
        new_o->show();
        moveToCenter(new_o);
    }
    else
    {
        qDebug() << "no row selected";
        QMessageBox::warning(0,"warning","вы не выбрали ни одного заказа!!!",QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "OK clicked";



//    int changedRow =   currentIndex().row();
//    if (changedRow >=0)
//    {
//        qDebug() << "changedRow = " << changedRow;

//    }




    model->submitAll();
//    ui->tableView->selectAll();
}

void MainWindow::on_actionAdd_order_triggered()
{
    const int row = model->rowCount();
    qDebug() << "inserting row" <<  model->insertRow(row);
    new_o->mapper->setCurrentModelIndex(model->index(row,0));
    new_o->show();
    moveToCenter(new_o);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::slot_comboWorkersBox_currentIndexChanged(const QString &arg1)
{

    qDebug() << "worker selected = " << arg1;
    if(clickedDay=="") //при запуске программы значение NULL
    {
        clickedDay = QDate::currentDate().toString("yyyy-MM-dd");
    }
    qDebug() << clickedDay;
    model->setFilter(QString( "name = '%1' and exec_date = '%2'")
                     .arg(arg1)
                     .arg(clickedDay));
    model->select();
}



void MainWindow::on_todayPushButton_clicked()
{
    ui->calendarWidget->showToday();
    //не работает!!!!!!!!!
}

void MainWindow::on_actionAddDiscount_triggered()
{
    discounts_window = new discounts;
    discounts_window->show();
    moveToCenter(discounts_window);
}

void MainWindow::on_actionInfo_triggered()
{
    about_window = new about;
    about_window->show();
    moveToCenter(about_window);
}



//отцентровка окна
void MainWindow::moveToCenter(QWidget& widget)
{
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (widget.width()/2));
    center.setY(center.y() - (widget.height()/2));
    widget.move(center);
}
//отцентровка с использованием перегрузки функции
void MainWindow::moveToCenter(QWidget* widget)
{
    moveToCenter(*widget);
}


void MainWindow::setUserOnline(QString user)
{
    userOnline = user;  //запоминаем полученную переменую, запоминаем пользователя
}

void MainWindow::setUserLogout()
{
    qDebug() << "user "+this->userOnline+" is logout";

    QSqlQuery logoutTimeQuery;
    logoutTimeQuery.prepare(QString("UPDATE users SET lastlogout='%1' WHERE login='%2'")
                .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(this->userOnline)
              );

    if(!logoutTimeQuery.exec())
    {
        qDebug() << "can't update logoutTime";
    }
    QSqlQuery logoutQuery;
    logoutQuery.prepare(QString("UPDATE users SET online='0' WHERE login='%1'").arg(this->userOnline));
    if(!logoutQuery.exec())
    {
        qDebug() << "can't update LOGOUT";
    }
}

//извлекаем данные данные кто онлайн

void MainWindow::whoOnline()
{
    QVector<QString> stringVector;
    QSqlQuery whoOnlineQuery;
    whoOnlineQuery.exec("SELECT login FROM users WHERE online='1'");
    while(whoOnlineQuery.next())
    {
      stringVector.push_back(whoOnlineQuery.value(0).toString());
      stringVector.push_back("  ");
    }
    QString str;
    for (int i=0; i<stringVector.size(); i++)
    {
        str += QString(stringVector.at(i));
    }
    statusBar()->showMessage(str);
}

void MainWindow::showOrdersForToday()
{
    todayOrdersQuery = new QSqlQuery;
    todayOrdersQuery->prepare("SELECT * FROM orders WHERE add_date = :date");
    todayOrdersQuery->bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));
    todayOrdersQuery->exec();
    int ordersCounter = 0;
    while(todayOrdersQuery->next())
    {
        ordersCounter++;
    }
    //QString orderz = QVariant(ordersCounter).toString();
    QString orderz = QString::number(ordersCounter);
    //qDebug() << "add orders for today:" << orderz;
    ui->ordersForTodaylabel->setText(orderz);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText("Вы уверены, что хотите выйти из CRM?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int result = msgBox.exec();
    switch (result)
    {
      case QMessageBox::Yes:
          this->setUserLogout();  //если выходим то записываем в базу 0
          event->accept();
          break;
      case QMessageBox::No:
          event->ignore();
          break;
      default:
          MainWindow::closeEvent(event);
          break;
    }
}


void MainWindow::on_logoutPushButton_clicked()
{

}

void MainWindow::on_actionLogout_triggered()
{

}

