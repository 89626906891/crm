#include "newworker.h"
#include "ui_newworker.h"

newworker::newworker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newworker)
{
    ui->setupUi(this);
}

newworker::~newworker()
{
    delete ui;
}
