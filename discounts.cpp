#include "discounts.h"
#include "ui_discounts.h"

discounts::discounts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::discounts)
{
    ui->setupUi(this);
}

discounts::~discounts()
{
    delete ui;
}
