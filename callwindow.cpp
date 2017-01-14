#include "callwindow.h"
#include "ui_callwindow.h"

CallWindow::CallWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CallWindow)
{
    ui->setupUi(this);
}

CallWindow::~CallWindow()
{
    delete ui;
}

void CallWindow::on_answerPushButton_clicked()
{
    emit answer();
}
