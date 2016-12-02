#ifndef WORKERS_H
#define WORKERS_H

#include <QWidget>

namespace Ui {
class workers;
}

class workers : public QWidget
{
    Q_OBJECT

public:
    explicit workers(QWidget *parent = 0);
    ~workers();

private:
    Ui::workers *ui;
};

#endif // WORKERS_H
