#include "uploadfileform.h"
#include "ui_uploadfileform.h"

uploadFileForm::uploadFileForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uploadFileForm)
{
    ui->setupUi(this);


}

uploadFileForm::~uploadFileForm()
{
    delete ui;
}

void uploadFileForm::orderinfo(int id)
{
    ui->idlabel->setNum(id);
    ID =id;

}

void uploadFileForm::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home/",
                                                    tr("only archive file (*.zip *.tar *.tar.gz)"));

    ui->filePathLineEdit->setText(fileName);
    NAME = ui->filePathLineEdit->text();
}

void uploadFileForm::on_cancelUploadFilepushButton_clicked()
{
    this->close();
}

void uploadFileForm::on_uploadFilePushButton_clicked()
{
    emit readyToUpload(ID,NAME);
    this->close();
}

//void MainWindow::uploadReady()
//{
//        QSqlRecord recordAddFilePath = model->record();
//        recordAddFilePath.setValue(model->fieldIndex("attach"),fileName);
//        qDebug() << "filling Attach fielepath" << model->insertRecord(id,recordAddFilePath);
//}
