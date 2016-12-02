#include "workers.h"
#include "ui_workers.h"

workers::workers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workers)
{
    ui->setupUi(this);
}

workers::~workers()
{
    delete ui;
}
