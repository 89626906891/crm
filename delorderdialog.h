#ifndef DELORDERDIALOG_H
#define DELORDERDIALOG_H

#include <QDialog>

namespace Ui {
class delOrderDialog;
}

class delOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit delOrderDialog(QWidget *parent = 0);
    ~delOrderDialog();

signals:
    void delOrder();

private slots:
    void on_pushButton_clicked();

private:
    Ui::delOrderDialog *ui;
};

#endif // DELORDERDIALOG_H
