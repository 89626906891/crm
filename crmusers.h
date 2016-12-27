#ifndef CRMUSERS_H
#define CRMUSERS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

#include "movetocenter.h"
#include "newcrmuser.h"
#include "loggingcategories.h"

namespace Ui {
class CRMusers;
}

class CRMusers : public QWidget
{
    Q_OBJECT

public:
    explicit CRMusers(QWidget *parent = 0);
    ~CRMusers();

    newCrmUser *newcrmuser_window;

private slots:
    void on_addCrmUserPushButton_clicked();


    void on_blockuserPushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void CRMuserAccepted();
    void newCRMuserCancel();

private:
    Ui::CRMusers *ui;
    QSqlRelationalTableModel *CRMusersModel;


};

#endif // CRMUSERS_H
