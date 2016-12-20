#include "newdiscount.h"
#include "ui_newdiscount.h"

newdiscount::newdiscount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newdiscount)
{
    ui->setupUi(this);
    this->setWindowTitle("Добавление новой скидки");

    discountMapper = new QDataWidgetMapper(this);
    discountMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);







}

newdiscount::~newdiscount()
{
    delete ui;
}
void newdiscount::setModel(QSqlRelationalTableModel *discountsModel)
{
    discountMapper->setModel(discountsModel);
    discountMapper->addMapping(ui->cardidlineEdit,1);
    discountMapper->addMapping(ui->clientNameLineEdit,4);
    discountMapper->addMapping(ui->clientAdressLineEdit,5);
    discountMapper->addMapping(ui->EmailLineEdit,6);
    discountMapper->addMapping(ui->clientPhonelineEdit,7);
    discountMapper->addMapping(ui->DescriptionLineEdit,8);
    discountMapper->addMapping(ui->activeCheckBox,10);

}


void newdiscount::on_acceptDiscountPushButton_clicked()
{
    qDebug() << "creating new Discount" << discountMapper->submit();
    emit discountReady();
    close();
}

void newdiscount::on_cancelDiscountPushButton_clicked()
{
    emit signalCancelDiscount();
    close();
}

void newdiscount::tableByidDiscount(QString selectedDiscount)
{
    //создаем таблицу номеркарты-заказы
    QSqlDatabase baze = QSqlDatabase::database();
    Q_ASSERT(baze.isOpen());

    qDebug() << selectedDiscount;


     relDiscoutOrderModel = new QSqlRelationalTableModel(this,baze);
     //устанавливаем связь с таблицой discounts
     relDiscoutOrderModel->setTable("orders");
     relDiscoutOrderModel->setJoinMode(QSqlRelationalTableModel::LeftJoin);
     relDiscoutOrderModel->setRelation(relDiscoutOrderModel->fieldIndex("discount_card"),QSqlRelation("discounts","discount_id","card_id"));
     //делаем сортировку по выбранной дисконтной карте
     relDiscoutOrderModel->setFilter(QString("discount_card = '%1'").arg(selectedDiscount));
     relDiscoutOrderModel->select();



     ui->relationDiscontOrderTableView->setModel(relDiscoutOrderModel);
}

void newdiscount::closeEvent(QCloseEvent *event)
{
    emit sigDiscountClose();
    event->accept();
}
