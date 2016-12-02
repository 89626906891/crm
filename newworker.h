#ifndef NEWWORKER_H
#define NEWWORKER_H

#include <QWidget>

namespace Ui {
class newworker;
}

class newworker : public QWidget
{
    Q_OBJECT

public:
    explicit newworker(QWidget *parent = 0);
    ~newworker();

private:
    Ui::newworker *ui;
};

#endif // NEWWORKER_H
