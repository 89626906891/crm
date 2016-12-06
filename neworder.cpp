#include "neworder.h"
#include "ui_neworder.h"

#include <QDate>
#include <QDebug>


newOrder::newOrder(QWidget *parent) :   //добавляем заначение редактируемой строки
    QWidget(parent),
    ui(new Ui::newOrder)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);




}

newOrder::~newOrder()
{
    delete ui;
}

void newOrder::setModel(QSqlRelationalTableModel *model)
{

    mapper->setModel(model);

    mapper->setItemDelegate(new QSqlRelationalDelegate(this));

    mapper->addMapping(ui->adressLineEdit,1);
    mapper->addMapping(ui->orderTextEdit,2,"plainText");
    mapper->addMapping(ui->phoneLineEdit,3);
    mapper->addMapping(ui->phone2lineEdit,4);
    mapper->addMapping(ui->execDateEdit,6);
    mapper->addMapping(ui->timeEdit,7);
    mapper->addMapping(ui->timeEdit2,8);
    mapper->addMapping(ui->spinBox,9);
    mapper->addMapping(ui->workerComboBox,10);


    QSqlTableModel *relModel = model->relationModel(10);
    ui->workerComboBox->setModel(relModel);
    ui->workerComboBox->setModelColumn(relModel->fieldIndex("name"));



}



void newOrder::on_applyButton_clicked()
{

    mapper->submit();
    emit ready();
    close();

}

void newOrder::on_closeButton_clicked()
{
    emit signalCancelOrder();
    close();
}


