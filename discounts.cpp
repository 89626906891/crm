#include "discounts.h"
#include "ui_discounts.h"

discounts::discounts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::discounts)
{
    ui->setupUi(this);
    this->setWindowTitle("Скидки");

    QSqlDatabase baze = QSqlDatabase::database();
    Q_ASSERT(baze.isOpen());

    discountsModel = new QSqlRelationalTableModel(this,baze);
    discountsModel->setTable("discounts");
    discountsModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    discountsModel->select();


    ui->discountsTableView->setModel(discountsModel);
    ui->discountsTableView->resizeColumnsToContents();
    ui->discountsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->discountsTableView->hideColumn(0);


    new_discount_window = new newdiscount;
    new_discount_window->setModel(discountsModel);
    new_discount_window->setParent(this,Qt::Window);

    connect(new_discount_window,SIGNAL(discountReady()),this,SLOT(newDiscount()));
    connect(new_discount_window,SIGNAL(signalCancelDiscount()),this,SLOT(discountCancled()));
    connect(new_discount_window,SIGNAL(sigDiscountClose()),this,SLOT(discountCancled()));
}

discounts::~discounts()
{
    delete ui;
}

void discounts::on_discountsTableView_doubleClicked(const QModelIndex &index)
{
    //получаем значение 1 столбца выделенной строки
    QModelIndex currentDiscount  = ui->discountsTableView->currentIndex();
    qDebug() << ui->discountsTableView->model()->data(ui->discountsTableView->model()->index(currentDiscount.row(),1),0).toString();
    QString selectedDisount = ui->discountsTableView->model()->data(ui->discountsTableView->model()->index(currentDiscount.row(),1),0).toString();
    new_discount_window->tableByidDiscount(selectedDisount);

     //отправляем что показывать в маппере
    new_discount_window->discountMapper->setCurrentModelIndex(index);
    new_discount_window->show();
    moveToCenter(new_discount_window);
}

void discounts::newDiscount()
{
    qDebug() << "adding new discount" << discountsModel->submitAll();
}

void discounts::on_addDiscountPushButton_clicked()
{
    const int row = discountsModel->rowCount();
    qDebug() << "inserting row into Discounts" <<  discountsModel->insertRow(row);
    new_discount_window->discountMapper->setCurrentModelIndex(discountsModel->index(row,0));
    new_discount_window->show();
    moveToCenter(new_discount_window);

}
void discounts::discountCancled()
{
    qDebug() << "discount canceled";
    discountsModel->revertAll();
}

void discounts::on_findDiscountButton_clicked()
{

    QString idTofind = ui->findDiscountLineEdit->text();
    qDebug() << idTofind;
    if(idTofind==NULL)
    {
        discountsModel->setTable("discounts"); //наверное так не правильно делать
        discountsModel->select();
    }
    else
    {
        discountsModel->setFilter(QString( "card_id = '%1'").arg(idTofind));
        discountsModel->select();
    }

}
