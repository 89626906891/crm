#include "newworker.h"
#include "ui_newworker.h"

newworker::newworker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newworker)
{
    ui->setupUi(this);

    workerMapper = new QDataWidgetMapper(this);
    workerMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);






}

newworker::~newworker()
{
    delete ui;
}


void newworker::setModel(QSqlRelationalTableModel *workersModel)
{
    workerMapper->setModel(workersModel);
    workerMapper->addMapping(ui->workerLineEdit,1);
    workerMapper->addMapping(ui->workerLineEdit2,2);

}
void newworker::on_pushButton_clicked()
{
    qDebug() << "creating new worker" << workerMapper->submit();
    emit workerReady();
    close();
}
