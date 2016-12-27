#ifndef WORKERS_H
#define WORKERS_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QDataWidgetMapper>



#include "newworker.h"
#include "movetocenter.h"

namespace Ui {
class workers;
}

class workers : public QWidget
{
    Q_OBJECT

public:
    explicit workers(QWidget *parent = 0);
    ~workers();



private slots:
    void on_addWorkerPushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);
    void workerAccepted();
    void workerCancled();

    void on_workersTableView_doubleClicked(const QModelIndex &index);


private:
    Ui::workers *ui;
    QSqlRelationalTableModel *workersModel;
    newworker *newWorker_window;
};

#endif // WORKERS_H
