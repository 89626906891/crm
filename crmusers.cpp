#include "crmusers.h"
#include "ui_crmusers.h"

CRMusers::CRMusers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CRMusers)
{
    ui->setupUi(this);
    this->setWindowTitle("CRM пользователи");

    QSqlDatabase baze = QSqlDatabase::database();
    Q_ASSERT(baze.isOpen());

    CRMusersModel =  new QSqlRelationalTableModel(this,baze);
    CRMusersModel->setTable("users");
    CRMusersModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    CRMusersModel->select();

    ui->tableView->setModel(CRMusersModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(2);


    newcrmuser_window = new newCrmUser;
    newcrmuser_window->setModel(CRMusersModel);
    newcrmuser_window->setParent(this,Qt::Window);

    connect(newcrmuser_window,SIGNAL(CRMuserReady()),this,SLOT(CRMuserAccepted()));
    connect(newcrmuser_window,SIGNAL(CRMuserWindowClosed()),this,SLOT(newCRMuserCancel()));

}

CRMusers::~CRMusers()
{
    delete ui;
}

void CRMusers::on_addCrmUserPushButton_clicked()
{
    const int row = CRMusersModel->rowCount();
    qDebug() << "inserting row into CRMusers" <<  CRMusersModel->insertRow(row);
    newcrmuser_window->crmUserMapper->setCurrentModelIndex(CRMusersModel->index(row,0));
    newcrmuser_window->show();
    moveToCenter(newcrmuser_window);
}

void CRMusers::on_blockuserPushButton_clicked()
{

}

void CRMusers::on_tableView_doubleClicked(const QModelIndex &index)
{
    newcrmuser_window->crmUserMapper->setCurrentModelIndex(index);
    newcrmuser_window->show();
    moveToCenter(newcrmuser_window);
}

void CRMusers::CRMuserAccepted()
{
    qInfo(logInfo()) << "adding new CRMuser" << CRMusersModel->submitAll();
    qInfo(logInfo()) << "apdating CRMuserModel" << CRMusersModel->select(); //все равно не обновляет
}

void CRMusers::newCRMuserCancel()
{
    qInfo(logInfo()) << "newCRMuser canceled";
    CRMusersModel->revertAll();
}
