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

    model->setHeaderData(1, Qt::Horizontal, "адрес");
    model->setHeaderData(2, Qt::Horizontal, "заказ");
    model->setHeaderData(3, Qt::Horizontal, "телефон");
    model->setHeaderData(4, Qt::Horizontal, "телефон 2");
    model->setHeaderData(7, Qt::Horizontal, "со скольки");
    model->setHeaderData(8, Qt::Horizontal, "до скольки");
    model->setHeaderData(9, Qt::Horizontal, "выручка");
    model->setHeaderData(10, Qt::Horizontal, "работник");

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(14);
    ui->tableView->hideColumn(15);
    ui->tableView->hideColumn(17);
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("name"),new QSqlRelationalDelegate(ui->tableView)); //для combobox работники
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("status_name"),new QSqlRelationalDelegate(ui->tableView)); //для комбобокса со статусом заказа
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("payment_name"),new QSqlRelationalDelegate(ui->tableView)); //способ оплаты
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("phone"), new PhoneNumberDelegate(ui->tableView)); //делаем маску для телефона
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("phone2"), new PhoneNumberDelegate(ui->tableView));


  for( int i = 0; i < model->rowCount(); ++i )
  {
    ui->tableView->setIndexWidget(ui->tableView->model()->index(i, model->fieldIndex("attach")),createButtonWidget());
  }
    //ui->tableView->setItemDelegateForColumn(model->fieldIndex("attach"), new buttonDelegate(ui->tableView)); //кнопка в таблице

    ui->tableView->setItemDelegateForColumn(model->fieldIndex("salary"), new salaryDelegate(ui->tableView)); //чтобы отображалась валюта
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("checked"),new CheckBoxDelegate(ui->tableView));  // устанавливаем делегат для checkbox checkboxdelegate.cpp





    new_o = new newOrder();
    new_o->setParent(this,Qt::Window);
    new_o->setModel(model);



    //посвечиваем текущий день
    QTextCharFormat fmt;
    fmt.setBackground(Qt::yellow);
    //QDate date = QDate::currentDate();
    ui->calendarWidget->setDateTextFormat(QDate::currentDate(), fmt);

    //определяем календарик
    ui->calendarWidget = new QCalendarWidget(this);

    // Устанавливаем Контекстное Меню
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);



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
    // Подключаем СЛОТ вызова контекстного меню
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotRightClickMenuRequested(QPoint)));




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
    recordAddDate.setValue(model->fieldIndex("add_date"),QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
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
    "\n ТЫ УВЕРЕН?", "ДА","Нет", QString(), 0,1);
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
    model->sort(7,Qt::AscendingOrder);
  //  qDebug() <<"selected:" << date.toString("yyyy-MM-dd");
    qInfo(logInfo()) <<"selected:" << date.toString("yyyy-MM-dd");
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
        qInfo(logInfo()) << "order to edit = " << selectedOrder;
        new_o->mapper->setCurrentModelIndex(model->index(selectedOrder,0));
        new_o->show();
        moveToCenter(new_o);
    }
    else
    {
        qInfo(logInfo()) << "no row selected";
        QMessageBox::warning(0,"warning","вы не выбрали ни одного заказа!!!",QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_clicked()
{
    qInfo(logInfo()) << "OK clicked";
    model->submitAll();
}

void MainWindow::on_actionAdd_order_triggered()
{
    const int row = model->rowCount();
    qInfo(logInfo()) << "inserting row" <<  model->insertRow(row);
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
    qInfo(logInfo()) << clickedDay;
    model->setFilter(QString( "name = '%1' and exec_date = '%2'")
                     .arg(arg1)
                     .arg(clickedDay));
    model->select();
}



void MainWindow::on_todayPushButton_clicked()
{
    QDate cdate = QDate::currentDate();
    cdate.setDate(cdate.year(),cdate.month(),cdate.day());
    ui->calendarWidget->setSelectedDate(cdate);
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





void MainWindow::setUserOnline(QString user)
{
    userOnline = user;  //запоминаем полученную переменую, запоминаем пользователя
}

void MainWindow::setUserLogout()
{
    qInfo(logInfo()) << "user "+this->userOnline+" is logout";

    QSqlQuery logoutTimeQuery;
    logoutTimeQuery.prepare(QString("UPDATE users SET lastlogout='%1' WHERE login='%2'")
                .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(this->userOnline)
              );

    if(!logoutTimeQuery.exec())
    {
        qWarning(logWarning()) << "can't update logoutTime";
    }
    QSqlQuery logoutQuery;
    logoutQuery.prepare(QString("UPDATE users SET online='0' WHERE login='%1'").arg(this->userOnline));
    if(!logoutQuery.exec())
    {
        qWarning(logWarning()) << "can't update LOGOUT";
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

//если будут коллизии первым делом проверить select. В базе datetime а тут проверяем по date
void MainWindow::showOrdersForToday()
{

    QSqlQuery todayOrdersQuery;
    todayOrdersQuery.prepare(QString("SELECT * FROM orders WHERE add_date LIKE '%1%'").arg(QDate::currentDate().toString("yyyy-MM-dd")));
    if(!todayOrdersQuery.exec())
    {
         qWarning(logWarning()) <<"error SELECTing todayOrdersQuery" << QDate::currentDate().toString("yyyy-MM-dd");
    }
    int ordersCounter = 0;
    while(todayOrdersQuery.next())
    {
        ordersCounter++;
    }

    QString orderz = QString::number(ordersCounter);
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


void MainWindow::on_lastOrdersPushButton_clicked()
{
    qDebug() << "lastOrdersPushButton_clicked ";

    //model->setFilter(QString("add_date = '%1'").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
    model->sort(5, Qt::DescendingOrder);




//    QSortFilterProxyModel *proxymodel = new QSortFilterProxyModel(this);
//    proxymodel->setSourceModel(model);
//    proxymodel->sort();
//    //proxymodel->setFilter(QString("add_date = '%1'").arg(QDate::currentDate().toString("yyyy-MM-dd")));
//    ui->tableView->setModel(proxymodel);
 //   proxymodel->select();

//

}

void MainWindow::on_lastCancelOrdersPushButton_clicked()
{
    qDebug() << "lastCancelOrdersPushButton_clicked ";
    //model->setFilter(QString( "status_name = 'cancel'"));
    model->setFilter( QString(tr("status_name = 'cancel'")));
    model->select();
}

void MainWindow::slotRightClickMenuRequested(QPoint pos)
{
    // Создаем объект контекстного меню
    QMenu * menu = new QMenu(this);
    // Создаём действия для контекстного меню
    QAction * editOrder = new QAction(trUtf8("Редактировать"), this);
    QAction * deleteOrder = new QAction(trUtf8("Удалить"), this);
    // Подключаем СЛОТы обработчики для действий контекстного меню
    connect(editOrder, SIGNAL(triggered()), this, SLOT(on_editOrderPushButton_clicked()));     // Обработчик вызова диалога редактирования
    connect(deleteOrder, SIGNAL(triggered()), this, SLOT(on_delButton_clicked())); // Обработчик удаления записи
    // Устанавливаем действия в меню
    menu->addAction(editOrder);
    menu->addAction(deleteOrder);
    // Вызываем контекстное меню
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}


//void MainWindow::slotRightClickDelete()
//{
//    /* Выясняем, какая из строк была выбрана
//     * */
//    int row = ui->deviceTableView->selectionModel()->currentIndex().row();
//    /* Проверяем, что строка была действительно выбрана
//     * */
//    if(row >= 0){
//        /* Задаём вопрос, стоит ли действительно удалять запись.
//         * При положительном ответе удаляем запись
//         * */
//        if (QMessageBox::warning(this,
//                                 trUtf8("Удаление записи"),
//                                 trUtf8("Вы уверены, что хотите удалить эту запись?"),
//                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
//        {
//            /* При отрицательном ответе делаем откат действий
//             * и закрываем диалог без удаления записи
//             * */
//            QSqlDatabase::database().rollback();
//            return;
//        } else {
//            /* В противном случае производим удаление записи.
//             * При успешном удалении обновляем таблицу.
//             * */
//            if(!modelDevice->removeRow(row)){
//                QMessageBox::warning(this,trUtf8("Уведомление"),
//                                     trUtf8("Не удалось удалить запись\n"
//                                            "Возможно она используется другими таблицами\n"
//                                            "Проверьте все зависимости и повторите попытку"));
//            }
//            modelDevice->select();
//            ui->deviceTableView->setCurrentIndex(modelDevice->index(-1, -1));
//        }
//    }
//}

void MainWindow::on_actionHistoryLog_triggered()
{
    history_window = new history;
    history_window->show();
    moveToCenter(history_window);
}

void MainWindow::on_actionCRMusers_triggered()
{
    crmusers_window = new CRMusers;
    crmusers_window->show();
    moveToCenter(crmusers_window);
}

QWidget* MainWindow::createButtonWidget() const
{
    QWidget* wgt = new QWidget;
    QBoxLayout* l = new QHBoxLayout;
    QPushButton* btn = new QPushButton( "Click me!" );
 //   connect( btn, SIGNAL( clicked( bool ) ), SLOT( onBtnClicked() ) );
    l->setMargin( 0 );
    l->addWidget( btn );
    l->addStretch();
    wgt->setLayout( l );

    return wgt;
}
