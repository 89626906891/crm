#include "delorderdialog.h"
#include "ui_delorderdialog.h"



delOrderDialog::delOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delOrderDialog)
{
    ui->setupUi(this);
}

delOrderDialog::~delOrderDialog()
{
    delete ui;
}


void delOrderDialog::on_pushButton_clicked()
{
    emit delOrder();
}

