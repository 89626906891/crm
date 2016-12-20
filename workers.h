#ifndef WORKERS_H
#define WORKERS_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QDataWidgetMapper>



#include "newworker.h"

namespace Ui {
class workers;
}

class workers : public QWidget
{
    Q_OBJECT

public:
    explicit workers(QWidget *parent = 0);
    ~workers();

    newworker *newWorker_window;

private slots:
    void on_addWorkerPushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);
    void workerAccepted();
    void workerCancled();

    void on_workersTableView_doubleClicked(const QModelIndex &index);


private:
    Ui::workers *ui;
    QSqlRelationalTableModel *workersModel;

};

#endif // WORKERS_H
