#ifndef NEWDISCOUNT_H
#define NEWDISCOUNT_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QCloseEvent>

namespace Ui {
class newdiscount;
}

class newdiscount : public QWidget
{
    Q_OBJECT

public:
    explicit newdiscount(QWidget *parent = 0);
    ~newdiscount();
    void setModel(QSqlRelationalTableModel *discountsModel);
    QDataWidgetMapper *discountMapper;
    void tableByidDiscount(QString selectedDiscount);


signals:
    void discountReady();
    void signalCancelDiscount();
    void sigDiscountClose();

private slots:
    void on_acceptDiscountPushButton_clicked();

    void on_cancelDiscountPushButton_clicked();

private:
    Ui::newdiscount *ui;
    QSqlRelationalTableModel *relDiscoutOrderModel;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // NEWDISCOUNT_H
