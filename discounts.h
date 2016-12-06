#ifndef DISCOUNTS_H
#define DISCOUNTS_H

#include <QWidget>

namespace Ui {
class discounts;
}

class discounts : public QWidget
{
    Q_OBJECT

public:
    explicit discounts(QWidget *parent = 0);
    ~discounts();

private:
    Ui::discounts *ui;
};

#endif // DISCOUNTS_H
