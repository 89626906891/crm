#ifndef NEWWORKER_H
#define NEWWORKER_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QDebug>
#include <QSqlRelationalTableModel>
#include <QCloseEvent>


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
    void signal_workerCanclel();
    void sigWorkerClose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newworker *ui;




    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // NEWWORKER_H
