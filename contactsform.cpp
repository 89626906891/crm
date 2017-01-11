#include "contactsform.h"
#include "ui_contactsform.h"

ContactsForm::ContactsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactsForm)
{
    ui->setupUi(this);



    this->setWindowTitle("Контакты");


    QSqlDatabase baze = QSqlDatabase::database();
    Q_ASSERT(baze.isOpen());

    contactsModel =  new QSqlRelationalTableModel(this,baze);
    contactsModel->setTable("contacts");
    contactsModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    contactsModel->select();

    ui->contactsTableView->setModel(contactsModel);
    ui->contactsTableView->resizeColumnsToContents();
    ui->contactsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->contactsTableView->hideColumn(0);
    ui->contactsTableView->hideColumn(7);
    ui->contactsTableView->hideColumn(9);

    contactsModel->setHeaderData(1, Qt::Horizontal, "ФИО");
    contactsModel->setHeaderData(2, Qt::Horizontal, "группа");
    contactsModel->setHeaderData(3, Qt::Horizontal, "организация");
    contactsModel->setHeaderData(4, Qt::Horizontal, "комментарий");
    contactsModel->setHeaderData(5, Qt::Horizontal, "телефон");
    contactsModel->setHeaderData(6, Qt::Horizontal, "почта");
    contactsModel->setHeaderData(7, Qt::Horizontal, "добавочный тел");
    contactsModel->setHeaderData(8, Qt::Horizontal, "комент к телефону");
    contactsModel->setHeaderData(9, Qt::Horizontal, "телефон 2");
    contactsModel->setHeaderData(10, Qt::Horizontal, "дата добавления");



    newContact_window = new newContact;
    newContact_window->setModel(contactsModel);
    newContact_window->setParent(this,Qt::Window);

    connect(newContact_window,SIGNAL(signalContactReady()),this,SLOT(contactAccepted()));
    connect(newContact_window,SIGNAL(signalContactClose()),this,SLOT(contactCancled()));
    connect(newContact_window,SIGNAL(signalContactCanclel()),this,SLOT(contactCancled()));
}

ContactsForm::~ContactsForm()
{
    delete ui;
}


void ContactsForm::on_contactsTableView_doubleClicked(const QModelIndex &index)
{
    newContact_window->contactsMapper->setCurrentModelIndex(index);
    newContact_window->show();
    moveToCenter(newContact_window);
}

void ContactsForm::on_addContactsPushButton_clicked()
{
    const int row = contactsModel->rowCount();
    QSqlRecord recordAddDate = contactsModel->record();
    recordAddDate.setValue(contactsModel->fieldIndex("date_creation"),QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    qDebug() << "filling date_creation field" << contactsModel->insertRecord(row,recordAddDate);

   // qDebug() << "inserting row into contacts" <<  contactsModel->insertRow(row);
    newContact_window->contactsMapper->setCurrentModelIndex(contactsModel->index(row,0));
    newContact_window->show();
    moveToCenter(newContact_window);

}
void ContactsForm::contactAccepted()
{
    qDebug() << "adding new Contact" << contactsModel->submitAll();
    qDebug() << "updating Contacts model" << contactsModel->select(); //все равно не обновляет
}

void ContactsForm::contactCancled()
{
    qDebug() << "Contact canceled";
    contactsModel->revertAll();
}


void ContactsForm::on_delContactsPushButton_clicked()
{

        int selectedRow = ui->contactsTableView->currentIndex().row();
        if (selectedRow >=0)
        {
          int n = QMessageBox::warning(0,
          "ВНИМАНИЕ",
          "ТОЧНО СТЕРЕТЬ Контакт????"
          "\n ТЫ УВЕРЕН?", "ДА","Нет", QString(), 0,1);
           if(!n)
           {
              qDebug() << "deleting row:" << contactsModel->removeRow(selectedRow);
              contactsModel->submitAll();
           }
           else
           {
              qDebug() << "deleting cancled";
              contactsModel->submitAll();
           }

         }
         else
           {
              qDebug() << "no row selected";
              QMessageBox::warning(0,"warning","вы не выбрали ни одной записи!!!",QMessageBox::Cancel);

           }
}
