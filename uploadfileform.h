#ifndef UPLOADFILEFORM_H
#define UPLOADFILEFORM_H

#include <QWidget>
#include <QFileDialog>



namespace Ui {
class uploadFileForm;
}

class uploadFileForm : public QWidget
{
    Q_OBJECT

public:
    explicit uploadFileForm(QWidget *parent = 0);
    ~uploadFileForm();

    void orderinfo(int id);


signals:
    void readyToUpload(int ID,QString NAME);

private slots:
    void on_pushButton_clicked();
    void on_cancelUploadFilepushButton_clicked();
    void on_uploadFilePushButton_clicked();

private:
    Ui::uploadFileForm *ui;
    int ID;
    QString NAME;

};

#endif // UPLOADFILEFORM_H
