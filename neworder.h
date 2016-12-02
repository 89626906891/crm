#ifndef NEWORDER_H
#define NEWORDER_H

#include <QWidget>

#include <QDataWidgetMapper>



namespace Ui {
class newOrder;
}

class newOrder : public QWidget
{
    Q_OBJECT

public:
    explicit newOrder(QWidget *parent = 0);
    ~newOrder();

    void setModel(QAbstractItemModel *model);

    QDataWidgetMapper *mapper;

signals:
    void ready();

private slots:
    void on_applyButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::newOrder *ui;



};

#endif // NEWORDER_H
