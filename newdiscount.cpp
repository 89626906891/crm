#include "newdiscount.h"
#include "ui_newdiscount.h"

newdiscount::newdiscount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newdiscount)
{
    ui->setupUi(this);
}

newdiscount::~newdiscount()
{
    delete ui;
}
