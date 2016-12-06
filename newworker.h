#ifndef NEWWORKER_H
#define NEWWORKER_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QDebug>
#include <QSqlRelationalTableModel>

namespace Ui {
class newworker;
}

class newworker : public QWidget
{
    Q_OBJECT

public:
    explicit newworker(QWidget *parent = 0);
    ~newworker();

    QDataWidgetMapper *workerMapper;

    void setModel(QSqlRelationalTableModel *workersModel);


signals:
    void workerReady();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newworker *ui;



};

#endif // NEWWORKER_H
