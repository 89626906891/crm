#include "authdialog.h"
#include "ui_authdialog.h"

AuthDialog::AuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Авторизация");


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CRM");
    db.setUserName("root");
    db.setPassword("qqwwee");
   // db.open();

    dbMess = new QMessageBox(this);

    if (!db.open()) {
        dbMess->critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Не могу установить соединение с базой.\n"
                     "Скорей всего сервер с базой не работает\n"
                     "или проблемы в интернет соединении \n\n"

                     "Нажмите Cancel для выхода."), dbMess->Cancel);

    }
    else
    {
       ui->connectLabel->setText("Cоединение с базой установленно!");
       ui->connectLabel->show();
    }
}

AuthDialog::~AuthDialog()
{

    delete ui;
}

void AuthDialog::on_enterButton_clicked()
{
    if(ui->passwordLineEdit->text()== NULL or ui->loginLineEdit->text()== NULL )
    {
        nullMess = new QMessageBox();
        nullMess->critical(0, qApp->tr("пустые поля"),
                           qApp->tr("поля не могут быть пустыми.\n"
                                    "одно из полей не заполненно!\n"
                                    "\n\n"

                                    "Нажмите Cancel для выхода."), nullMess->Cancel);
    }
    else
    {
        query = new QSqlQuery;
        query->prepare("SELECT * FROM users WHERE password = :pass AND login=:user");
        query->bindValue(":pass", ui->passwordLineEdit->text());
        query->bindValue(":user", ui->loginLineEdit->text());

        if(!query->exec())
        {
            connMess = new QMessageBox();
            connMess->critical(0, qApp->tr("запрос в базу не выполнен"),
                               qApp->tr("не отправить запрос к базе!!! .\n"
                                        "\n\n"

                                        "Нажмите Cancel для выхода."), connMess->Cancel);
        }
        else
        {
           QString user;
           while(query->next())
           {
             user = query->value(1).toString();  //тк начало с 0, а 1ый это айдишник
           }

           if (ui->loginLineEdit->text() == user)
           {
               win = new MainWindow();
               win->show();
               this->close();
           }
           else
           {
               enterMess = new QMessageBox();
               enterMess->critical(0, qApp->tr("Ошибка Доступа "),
                                  qApp->tr("неверный логин или пароль .\n"
                                           "\n\n"

                                           "Нажмите Cancel для выхода."), enterMess->Cancel);

           }
        }

    }
}
