#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDateTime>


#include "mainwindow.h"



namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthDialog(QWidget *parent = 0);
    ~AuthDialog();

private slots:
    void on_enterButton_clicked();
    void isAuth(QString user);

private:
    Ui::AuthDialog *ui;

    QSqlDatabase *db;
    QMessageBox *dbMess;
    QSqlQuery *query;
    QMessageBox *nullMess;
    QMessageBox *connMess;
    QMessageBox *enterMess;
    MainWindow *win;


};

#endif // AUTHDIALOG_H
