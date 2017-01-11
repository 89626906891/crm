#ifndef CONTACTSFORM_H
#define CONTACTSFORM_H

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>


#include "newcontact.h"
#include "movetocenter.h"


namespace Ui
{
    class ContactsForm;
}

class ContactsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContactsForm(QWidget *parent = 0);
    ~ContactsForm();

private slots:
    void on_contactsTableView_doubleClicked(const QModelIndex &index);
    void on_addContactsPushButton_clicked();
    void contactAccepted();
    void contactCancled();

    void on_delContactsPushButton_clicked();

private:
    Ui::ContactsForm *ui;


    QSqlRelationalTableModel *contactsModel;

    newContact *newContact_window;

};

#endif // CONTACTSFORM_H
