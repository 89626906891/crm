#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);

    this->setWindowTitle("Логгирование событий CRM");


    QFile file("log.txt"); //файл лога создается в main.cpp
    if (!file.open(QIODevice::ReadOnly))
    {
       qWarning(logWarning()) << "Could not open logfile";
       return;
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    file.close();

}

history::~history()
{
    delete ui;
}

void history::on_closeHistoryPushButton_clicked()
{
    this->close();
}
