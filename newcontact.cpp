#include "newcontact.h"
#include "ui_newcontact.h"

newContact::newContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newContact)
{
    ui->setupUi(this);


    contactsMapper = new QDataWidgetMapper(this);
    contactsMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

newContact::~newContact()
{
    delete ui;
}

void newContact::setModel(QSqlRelationalTableModel *contactsModel)
{
    contactsMapper->setModel(contactsModel);
    contactsMapper->addMapping(ui->fioLineEdit,1);
    contactsMapper->addMapping(ui->groupLineEdit,2);
    contactsMapper->addMapping(ui->orgLineEdit,3);
    contactsMapper->addMapping(ui->commentLineEdit,4);
    contactsMapper->addMapping(ui->phoneLineEdit,5);
    contactsMapper->addMapping(ui->mailLineEdit,6);
    contactsMapper->addMapping(ui->addLineEdit,7);
    contactsMapper->addMapping(ui->telCommLineEdit,8);
    contactsMapper->addMapping(ui->phone2LineEdit,9);
 //contactsMapper->addMapping(ui->addDateLineEdit,10);

}

void newContact::on_okPushButton_clicked()
{
    qDebug() << "creating new worker" << contactsMapper->submit();
    emit signalContactReady();
    close();
}

void newContact::on_cancelPushButton_clicked()
{
    emit signalContactCanclel();
    close();
}

void newContact::closeEvent(QCloseEvent *event)
{
    emit signalContactClose();
    event->accept();
}
