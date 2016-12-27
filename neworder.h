#ifndef NEWORDER_H
#define NEWORDER_H

#include <QWidget>

#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
#include <QCloseEvent>
#include <QLineEdit>
#include <QDebug>

#include "loggingcategories.h"

namespace Ui {
class newOrder;
}

class newOrder : public QWidget
{
    Q_OBJECT

public:
    explicit newOrder(QWidget *parent = 0);
    ~newOrder();

    void setModel(QSqlRelationalTableModel *model);
    void setRelModel(QSqlTableModel *relModel);

    QDataWidgetMapper *mapper;
    QSqlTableModel *relModel;
signals:
    void ready();
    void signalCancelOrder();
    void sigClose();

private slots:
    void on_applyButton_clicked();

    void on_closeButton_clicked();

    void on_plusPushButton_clicked();

    void on_minusPushButton_clicked();

private:
    Ui::newOrder *ui;
    int lineEditCounter;




    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // NEWORDER_H
