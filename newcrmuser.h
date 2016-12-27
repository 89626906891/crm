#ifndef NEWCRMUSER_H
#define NEWCRMUSER_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include <QCloseEvent>

#include "loggingcategories.h"

namespace Ui {
class newCrmUser;
}

class newCrmUser : public QWidget
{
    Q_OBJECT

public:
    explicit newCrmUser(QWidget *parent = 0);
    ~newCrmUser();

    void setModel(QSqlRelationalTableModel *CRMusersModel);
    QDataWidgetMapper *crmUserMapper;
signals:
    void CRMuserReady();
    void CRMuserCancled();
    void CRMuserWindowClosed();

private slots:
    void on_okpushButton_clicked();

    void on_cancelpushButton_clicked();




private:
    Ui::newCrmUser *ui;



    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // NEWCRMUSER_H
