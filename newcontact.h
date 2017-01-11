#ifndef NEWCONTACT_H
#define NEWCONTACT_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include <QCloseEvent>

#include "loggingcategories.h"

namespace Ui {
class newContact;
}

class newContact : public QWidget
{
    Q_OBJECT

public:
    explicit newContact(QWidget *parent = 0);
    ~newContact();

    void setModel(QSqlRelationalTableModel *contactsModel);
    QDataWidgetMapper *contactsMapper;


private slots:
    void on_okPushButton_clicked();
    void on_cancelPushButton_clicked();
signals:
    void signalContactReady();
    void signalContactCanclel();
    void signalContactClose();

private:
    Ui::newContact *ui;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // NEWCONTACT_H
