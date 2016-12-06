#include "workers.h"
#include "ui_workers.h"

workers::workers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workers)
{
    ui->setupUi(this);


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
    workersModel->select();
}

void workers::on_workersTableView_doubleClicked(const QModelIndex &index)
{
    newWorker_window->workerMapper->setCurrentModelIndex(index);
    newWorker_window->show();
}
