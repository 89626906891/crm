#include "workers.h"
#include "ui_workers.h"

workers::workers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workers)
{
    ui->setupUi(this);
    this->setWindowTitle("Работники");


    QSqlDatabase baze = QSqlDatabase::database();
    Q_ASSERT(baze.isOpen());

    workersModel =  new QSqlRelationalTableModel(this,baze);
    workersModel->setTable("workers");
    workersModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);


    workersModel->select();

    ui->workersTableView->setModel(workersModel);
    ui->workersTableView->resizeColumnsToContents();
    //ui->workersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->workersTableView->hideColumn(0);


    newWorker_window = new newworker;
    newWorker_window->setModel(workersModel);
    newWorker_window->setParent(this,Qt::Window);


    connect(newWorker_window,SIGNAL(workerReady()),this,SLOT(workerAccepted()));
    connect(newWorker_window,SIGNAL(signal_workerCanclel()),this,SLOT(workerCancled())); //отмена по кнопке
    connect(newWorker_window,SIGNAL(sigWorkerClose()),this,SLOT(workerCancled())); //отмена по крестику

}

workers::~workers()
{
    delete ui;
}

void workers::on_addWorkerPushButton_clicked()
{
    const int row = workersModel->rowCount();
    qDebug() << "inserting row into workers" <<  workersModel->insertRow(row);
    newWorker_window->workerMapper->setCurrentModelIndex(workersModel->index(row,0));
    newWorker_window->show();

}

void workers::on_tableView_doubleClicked(const QModelIndex &index)
{
    newWorker_window->workerMapper->setCurrentModelIndex(index);
    newWorker_window->show();

}

void workers::workerAccepted()
{

    qDebug() << "adding new worker" << workersModel->submitAll();

    qDebug() << "apdating workers model" << workersModel->select(); //все равно не обновляет

}

void workers::workerCancled()
{
    qDebug() << "worker canceled";
    workersModel->revertAll();
}

void workers::on_workersTableView_doubleClicked(const QModelIndex &index)
{
    newWorker_window->workerMapper->setCurrentModelIndex(index);
    newWorker_window->show();
}
