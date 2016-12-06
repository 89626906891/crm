#ifndef NEWORDER_H
#define NEWORDER_H

#include <QWidget>

#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>

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

private slots:
    void on_applyButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::newOrder *ui;



};

#endif // NEWORDER_H
