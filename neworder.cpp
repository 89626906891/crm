#include "neworder.h"
#include "ui_neworder.h"

#include <QDate>
#include <QDebug>


newOrder::newOrder(QWidget *parent) :   //добавляем заначение редактируемой строки
    QWidget(parent),
    ui(new Ui::newOrder)
{
    ui->setupUi(this);
    this->setWindowTitle("Добавление нового заказа");

    lineEditCounter = 0;



    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);

    ui->phoneLineEdit->setInputMask("+7 (999) 999-99-99");
    ui->phone2lineEdit->setInputMask("+7 (999) 999-99-99");




}

newOrder::~newOrder()
{
    delete ui;
}

void newOrder::setModel(QSqlRelationalTableModel *model)
{

    mapper->setModel(model);

    mapper->setItemDelegate(new QSqlRelationalDelegate(this));

    mapper->addMapping(ui->adressLineEdit,1);
    mapper->addMapping(ui->orderTextEdit,2,"plainText");
    mapper->addMapping(ui->phoneLineEdit,3);
    mapper->addMapping(ui->phone2lineEdit,4);
    mapper->addMapping(ui->execDateEdit,6);
    mapper->addMapping(ui->timeEdit,7);
    mapper->addMapping(ui->timeEdit2,8);
    mapper->addMapping(ui->spinBox,9);
    mapper->addMapping(ui->workerComboBox,10);


    QSqlTableModel *relModel = model->relationModel(10);
    ui->workerComboBox->setModel(relModel);
    ui->workerComboBox->setModelColumn(relModel->fieldIndex("name"));


}



void newOrder::on_applyButton_clicked()
{

    mapper->submit();
    emit ready();
    close();

}

void newOrder::on_closeButton_clicked()
{
    emit signalCancelOrder();
    close();
}



//переопределяем нажатие на кестик
void newOrder::closeEvent(QCloseEvent *event)
{
    emit sigClose();
    event->accept();
}



void newOrder::on_plusPushButton_clicked()
{
    QLineEdit *lineedit = new QLineEdit(this);
    lineedit->setObjectName("productLineEdit" + QString::number(lineEditCounter));
    lineEditCounter++;                                        // Инкрементируем счётчик
    ui->verticalLayout->addWidget(lineedit);                  // Помещаем  vertical layout

}

void newOrder::on_minusPushButton_clicked()
{
    int counter = 0;
    // Выполняем перебор всех элементов слоя, где располагаются динамические кнопки
    for(int i = 0; i < ui->verticalLayout->count(); i++)
    {
     counter++;
    }
    //теперь отнимаем от каунтера 1 а то кака обычно...
    if(counter>=1)
    {
        QLineEdit *line = qobject_cast<QLineEdit*>(ui->verticalLayout->itemAt(counter-1)->widget());
        line->hide();
        delete line;
    }
    else
    {
        qWarning(logWarning()) << "не могу удалить lineEdit";
    }


}
