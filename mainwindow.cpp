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


   //отслеживание бездействия пользователя
    //QWidget::setMouseTracking(true);
//    this->setMouseTracking(true);

    QSqlDatabase baze = QSqlDatabase::database();//baze.database();
    Q_ASSERT(baze.isOpen());

    model = new CRMModel(this,baze);
    ui->tableView->setModel(model);
  //  ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model->setHeaderData(1, Qt::Horizontal, "адрес");
    model->setHeaderData(2, Qt::Horizontal, "заказ");
    model->setHeaderData(3, Qt::Horizontal, "телефон");
    model->setHeaderData(4, Qt::Horizontal, "телефон 2");
    model->setHeaderData(6, Qt::Horizontal, "выполнить");
    model->setHeaderData(7, Qt::Horizontal, "со скольки");
    model->setHeaderData(8, Qt::Horizontal, "до скольки");
    model->setHeaderData(9, Qt::Horizontal, "выручка");
    model->setHeaderData(10, Qt::Horizontal, "работник");
    model->setHeaderData(13, Qt::Horizontal, "статус");
    model->setHeaderData(16, Qt::Horizontal, "тип оплаты");
    model->setHeaderData(18, Qt::Horizontal, "файл");
    model->setHeaderData(21, Qt::Horizontal, "кто принял");

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
 //   ui->tableView->setItemDelegateForColumn(model->fieldIndex("attach"), new buttonDelegate(ui->tableView)); //кнопка в таблице
    buttonDelegate *butDelegate = new buttonDelegate(ui->tableView);

    ui->tableView->setItemDelegateForColumn(model->fieldIndex("salary"), new salaryDelegate(ui->tableView)); //чтобы отображалась валюта
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("checked"),new CheckBoxDelegate(ui->tableView));  // устанавливаем делегат для checkbox checkboxdelegate.cpp
 //   ui->tableView->setItemDelegateForColumn(model->fieldIndex("crmuser_id"),new CrmUserDelegate(ui->tableView));



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


   // uploadFile_window = new uploadFileForm();



    connect(new_o,SIGNAL(ready()),this,SLOT(orderAccepted()));
    connect(new_o,SIGNAL(signalCancelOrder()),this,SLOT(orderCancled()));
    connect(new_o,SIGNAL(sigClose()),this,SLOT(orderCancled()));
    connect(ui->ComboWorkersBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(slot_comboWorkersBox_currentIndexChanged(QString)));
    // Подключаем СЛОТ вызова контекстного меню
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotRightClickMenuRequested(QPoint)));

    //connect(buttonDelegate.createNewUpload,SIGNAL(createNewUpload(int row)),this,SLOT(uploadFile(int row)));
    connect(butDelegate, SIGNAL(createNewUpload()), this, SLOT(uploadFile()));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("attach"), butDelegate);
   // connect(uploadFile_window,SIGNAL(readyToUpload(int,QString)),this,SLOT(uploadReady(int id,QString fileName)));



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

//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    if (event->type() == QEvent::MouseMove)
//    {
//        //QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
//        QTimer *mousetimer = new QTimer(this);
//        connect(mousetimer, SIGNAL(timeout()), this, SLOT(on_logoutPushButton_clicked()));
//        mousetimer->start(5000);
//    }
//}


void MainWindow::on_logoutPushButton_clicked()
{

    this->close();
    newauth = new AuthDialog;
    newauth->show();
}

void MainWindow::on_actionLogout_triggered()
{
    this->close();
    newauth = new AuthDialog;
    newauth->show();
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


void MainWindow::uploadFile()
{
    int row = ui->tableView->currentIndex().row();
    if (row >=0)
    {
        uploadFile_window = new uploadFileForm();
        moveToCenter(uploadFile_window);
        uploadFile_window->setWindowTitle("Загрузка файла на сервер");
        uploadFile_window->orderinfo(row);
        uploadFile_window->show();

        connect(uploadFile_window,SIGNAL(readyToUpload(int,QString)),this,SLOT(startUpload(int,QString)));

    }
    else
    {
        qDebug() << "no selected order";
    }
}

void MainWindow::startUpload(int ID, QString NAME)
{
    qDebug() << ID;
    qDebug() << NAME;
    QSqlRecord recordAddFilePath = model->record();
    recordAddFilePath.setValue(model->fieldIndex("file_path"),NAME);
    qDebug() << "filling Attach fielepath" << model->setRecord(ID, recordAddFilePath);
}



void MainWindow::on_b1_clicked()
{
    char b1 = '1';
    QString phone = ui->PhoneLine->text().append(b1);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b2_clicked()
{
    char b2 = '2';
    QString phone = ui->PhoneLine->text().append(b2);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b3_clicked()
{
    char b3 = '3';
    QString phone = ui->PhoneLine->text().append(b3);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b4_clicked()
{
    char b4 = '4';
    QString phone = ui->PhoneLine->text().append(b4);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b5_clicked()
{
    char b5 = '5';
    QString phone = ui->PhoneLine->text().append(b5);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b6_clicked()
{
    char b6 = '6';
    QString phone = ui->PhoneLine->text().append(b6);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b7_clicked()
{
    char b7 = '7';
    QString phone = ui->PhoneLine->text().append(b7);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b8_clicked()
{
    char b8 = '8';
    QString phone = ui->PhoneLine->text().append(b8);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b9_clicked()
{
    char b9 = '9';
    QString phone = ui->PhoneLine->text().append(b9);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_b0_clicked()
{
    char b0 = '0';
    QString phone = ui->PhoneLine->text().append(b0);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_bzvezda_clicked()
{
    char bzvezda = '*';
    QString phone = ui->PhoneLine->text().append(bzvezda);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}

void MainWindow::on_breshotka_clicked()
{
    char breshotka = '#';
    QString phone = ui->PhoneLine->text().append(breshotka);
    qDebug() << phone;
    ui->PhoneLine->setText("");
    ui->PhoneLine->setText(phone);
}



void MainWindow::on_delPhoneCharPushButton_clicked()
{
    QString phoneNumber = ui->PhoneLine->text();
    QString newPhoneNumber= phoneNumber.remove(phoneNumber.length()-1,phoneNumber.length());
    ui->PhoneLine->setText(newPhoneNumber);
}

void MainWindow::on_actionContacts_triggered()
{
    contacts_window = new ContactsForm;
    moveToCenter(contacts_window);
    contacts_window->show();
}

void MainWindow::sipReady(Endpoint &ep) throw(Error)
{

        // Init library
        EpConfig ep_cfg;
        ep_cfg.logConfig.level = 6;
        ep_cfg.logConfig.filename = "/home/alexey/crm/sip.log";
        ep.libInit(ep_cfg);



        // Transport
        TransportConfig tcfg;
        tcfg.port = 5060;      //5080 mango
        ep.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);

        // Start library
        ep.libStart();
        // std::cout << "*** PJSUA2 STARTED ***" << std::endl;

        // Add account
        AccountConfig acc_cfg;
        acc_cfg.idUri = "sip:user7@smirnov.mangosip.ru";
        acc_cfg.regConfig.registrarUri = "sip:smirnov.mangosip.ru";
        acc_cfg.sipConfig.authCreds.push_back( AuthCredInfo("digest", "*","user7", 0, "m7quhX5r") );

        std::auto_ptr<MyAccount> acc(new MyAccount);
        acc->create(acc_cfg);

        pj_thread_sleep(2000);

        //buddy
        BuddyConfig cfg;
        cfg.uri = "sip:user6@smirnov.mangosip.ru";
        MyBuddy buddy;
        try {
            buddy.create(*acc, cfg);
            buddy.subscribePresence(true);
        }
        catch(Error& err)
        {
        }
        //presents activity
        try {
            PresenceStatus ps;
            ps.status = PJSUA_BUDDY_STATUS_ONLINE;
            // Optional, set the activity and some note
            ps.activity = PJRPID_ACTIVITY_BUSY;
            ps.note = "On the phone";
            acc->setOnlineStatus(ps);
        }
        catch(Error& err)
        {
        }





    //        // Make outgoing call
    //        Call *call = new MyCall(*acc);
    //        acc->calls.push_back(call);
    //        CallOpParam prm(true);
    //        prm.opt.audioCount = 1;
    //        prm.opt.videoCount = 0;
    //        call->makeCall("sip:79219505492@smirnov.mangosip.ru", prm);

        // Just wait for ENTER key
    //    std::cout << "Press ENTER to quit..." << std::endl;
    //    std::cin.get();



    //        CallInfo ci = call->getInfo();
    //        AudioMedia *aud_med = NULL;

    //        for (unsigned i=0; i<ci.media.size(); ++i)
    //        {
    //            if (ci.media[i].type == PJMEDIA_TYPE_AUDIO)
    //            {
    //                aud_med = (AudioMedia *)call->getMedia(i);
    //                break;
    //            }
    //        }



//        AudioMediaRecorder recorder;
//        AudioMedia& cap_med = Endpoint::instance().audDevManager().getCaptureDevMedia();
//        try
//        {
//            recorder.createRecorder("/home/alexey/file1.wav");
//            cap_med.startTransmit(recorder);
//        }
//        catch(Error& err) {
//        }

//        AudioMediaPlayer player;
//        AudioMedia& play_med = Endpoint::instance().audDevManager().getPlaybackDevMedia();
//        try
//        {
//            player.createPlayer("/home/alexey/file1.wav");
//            player.startTransmit(play_med);
//        }
//        catch(Error& err) {
//        }


    //        if (aud_med)
    //        {
    //            // This will connect the sound device/mic to the call audio media
    //            cap_med.startTransmit(*aud_med);
    //            // And this will connect the call audio media to the sound device/speaker
    //            aud_med->startTransmit(play_med);
    //        }

//        pj_thread_sleep(20000);

//        // Hangup all calls
//         ep.hangupAllCalls();


//        try
//        {
//            player.stopTransmit(play_med);
//        }
//        catch(Error& err) {
//        }
//        try
//        {
//           cap_med.stopTransmit(recorder);
//        }
//        catch(Error& err) {
//        }

//        pj_thread_sleep(10000);

        // Destroy library
//        std::cout << "*** PJSUA2 SHUTTING DOWN ***" << std::endl;
}

//void MainWindow::sipDestroy()
//{
//    //SIP destroy
//    int ret = 0;
//    try
//    {
//        ep.libDestroy();
//    }
//        catch(Error &err)
//    {
//        std::cout << "Exception: " << err.info() << std::endl;
//        ret = 1;
//    }

//    if (ret == PJ_SUCCESS)
//    {
//        std::cout << "Success" << std::endl;
//    }
//    else
//    {
//        std::cout << "Error Found" << std::endl;
//    }
//    return ret;
//    //SIP
//}

void MainWindow::on_actionSIPlog_triggered()
{
    historySipWindow = new historySIP;
    historySipWindow->show();
    moveToCenter(historySipWindow);
}

//void MainWindow::on_pushButton_2_clicked()
//{
//    int ret = 0;
//    Endpoint ep;

//    try
//    {
//        ep.libCreate();
//       // sipReady(ep);
//        ret = PJ_SUCCESS;
//    }
//    catch (Error & err)
//    {
////            std::cout << "Exception: " << err.info() << std::endl;
////            ret = 1;
//    }

//    // Init library
//    EpConfig ep_cfg;
//    ep_cfg.logConfig.level = 6;
//    ep_cfg.logConfig.filename = "/home/alexey/crm/sip.log";
//    ep.libInit(ep_cfg);


//    // Transport
//    TransportConfig tcfg;
//    tcfg.port = 5060; //5080 mango
//    ep.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);

//    // Start library
//    ep.libStart();
//    // std::cout << "*** PJSUA2 STARTED ***" << std::endl;

//    // Add account
//    AccountConfig acc_cfg;
//    acc_cfg.idUri = "sip:user7@smirnov.mangosip.ru";
//    acc_cfg.regConfig.registrarUri = "sip:smirnov.mangosip.ru";
//    acc_cfg.sipConfig.authCreds.push_back(AuthCredInfo("digest", "*","user7", 0, "m7quhX5r1"));

////  std::auto_ptr<MyAccount> acc(new MyAccount);
////  acc->create(acc_cfg);

//    QThread *acc_thread = new QThread(this);
//    MyAccount *acc = new MyAccount;
//    try
//    {
//        acc->create(acc_cfg);
//    }
//    catch(Error& err)
//    {
//        std::cout << "Account creation error: " << err.info() << std::endl;
//    }
//    acc->moveToThread(acc_thread);
//    acc_thread->start();

//    //pj_thread_sleep(5000);


//    // Just wait for ENTER key
//    std::cout << "Press ENTER to quit..." << std::endl;
//    std::cin.get();
//}
void MainWindow::on_CallPushButton_clicked()
{

}

QString MainWindow::getSipLogin() //достаем sip login с учетом того кто сейчас работает в системе
{
    QSqlQuery getSipLoginQuery;
    QString sipLogin;
    getSipLoginQuery.prepare(QString("SELECT sip_acc FROM users WHERE login='%1'")
                .arg(this->userOnline)
              );
    if(!getSipLoginQuery.exec())
    {
        qWarning(logWarning()) << "can't SELECT sip login";
    }
    else
    {
      while (getSipLoginQuery.next())
      {
           sipLogin = getSipLoginQuery.value(0).toString();
      }
    }
    return sipLogin;
}

QString MainWindow::getSipPassword() //достаем из базы пароль от sip того кто сейчас работает в системе
{
    QSqlQuery getSipPassQuery;
    QString sipPass;
    getSipPassQuery.prepare(QString("SELECT sip_pass FROM users WHERE login='%1'")
                .arg(this->userOnline)
              );
    if(!getSipPassQuery.exec())
    {
        qWarning(logWarning()) << "can't SELECT sip pass";
    }
    else
    {
      while (getSipPassQuery.next())
      {
           sipPass = getSipPassQuery.value(0).toString();
      }
    }
    return sipPass;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString login = getSipLogin();
    QString pass = getSipPassword();


    sip *mysip = new sip;
    QThread *sip_thread = new QThread(this);

    mysip->moveToThread(sip_thread);
    sip_thread->start();

    mysip->resiveSipParameters(login,pass); //передаем логин и пароль в sip.cpp для запуска авторизации
    mysip->startSip();

  //  connect(&sip_thread,SIGNAL(started()),&mysip,SLOT()

}
