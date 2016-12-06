#ifndef NEWDISCOUNT_H
#define NEWDISCOUNT_H

#include <QWidget>

namespace Ui {
class newdiscount;
}

class newdiscount : public QWidget
{
    Q_OBJECT

public:
    explicit newdiscount(QWidget *parent = 0);
    ~newdiscount();

private:
    Ui::newdiscount *ui;
};

#endif // NEWDISCOUNT_H
