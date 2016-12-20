#ifndef DISCOUNTS_H
#define DISCOUNTS_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QDebug>

#include "newdiscount.h"

namespace Ui {
class discounts;
}

class discounts : public QWidget
{
    Q_OBJECT

public:
    explicit discounts(QWidget *parent = 0);
    ~discounts();

    newdiscount *new_discount_window;
    QSqlRelationalTableModel *discountsModel;


private slots:
    void on_discountsTableView_doubleClicked(const QModelIndex &index);

    void on_addDiscountPushButton_clicked();
    void discountCancled();

    void on_findDiscountButton_clicked();
    void newDiscount();
private:
    Ui::discounts *ui;

};

#endif // DISCOUNTS_H
