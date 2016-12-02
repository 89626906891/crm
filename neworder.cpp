#include "neworder.h"
#include "ui_neworder.h"

#include <QDate>

newOrder::newOrder(QWidget *parent) :   //добавляем заначение редактируемой строки
    QWidget(parent),
    ui(new Ui::newOrder)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);

    //ui->execDateTimeEdit->setDate(QDate::currentDate());

}

newOrder::~newOrder()
{
    delete ui;
}

void newOrder::setModel(QAbstractItemModel *model)
{

    mapper->setModel(model);
    mapper->addMapping(ui->adressLineEdit,1);
    mapper->addMapping(ui->orderTextEdit,2,"plainText");
    mapper->addMapping(ui->phoneLineEdit,3);
    mapper->addMapping(ui->execDateTimeEdit,5);

}

void newOrder::on_applyButton_clicked()
{

    mapper->submit();
    emit ready();
    close();

}

void newOrder::on_closeButton_clicked()
{
    close();
}


