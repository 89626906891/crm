#include "newcrmuser.h"
#include "ui_newcrmuser.h"

newCrmUser::newCrmUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newCrmUser)
{
    ui->setupUi(this);

    crmUserMapper = new QDataWidgetMapper(this);
    crmUserMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);


}

newCrmUser::~newCrmUser()
{
    delete ui;
}

void newCrmUser::on_okpushButton_clicked()
{
    qInfo(logInfo()) << "creating new CRMuser" << crmUserMapper->submit();
    emit CRMuserReady();
    close();
}

void newCrmUser::on_cancelpushButton_clicked()
{
    qInfo(logInfo()) << "cancel button of new CRMuser clicked";
    emit CRMuserCancled();
    close();
}

void newCrmUser::closeEvent(QCloseEvent *event)
{
    emit CRMuserWindowClosed();
    event->accept();
}

void newCrmUser::setModel(QSqlRelationalTableModel *CRMusersModel)
{
    crmUserMapper->setModel(CRMusersModel);
    crmUserMapper->addMapping(ui->namelineEdit,8);
    crmUserMapper->addMapping(ui->loginlineEdit,1);
    crmUserMapper->addMapping(ui->passwordlineEdit,2);
    crmUserMapper->addMapping(ui->paymentPasswordlineEdit,9);
    crmUserMapper->addMapping(ui->accesscheckBox,6);
    crmUserMapper->addMapping(ui->activecheckBox,10);

}
