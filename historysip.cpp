#include "historysip.h"
#include "ui_historysip.h"

historySIP::historySIP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::historySIP)
{
    ui->setupUi(this);


    this->setWindowTitle("Логгирование событий SIP");


    QFile file("/home/alexey/crm/sip.log"); //создается в mainwondow
    if (!file.open(QIODevice::ReadOnly))
    {
       qWarning(logWarning()) << "Could not open logfile sip.log";
       return;
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    file.close();


}

historySIP::~historySIP()
{
    delete ui;
}

void historySIP::on_closePushButton_clicked()
{
    this->close();
}
