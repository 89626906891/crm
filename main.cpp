#include "authdialog.h"
#include <QApplication>
#include <QLockFile>
#include <QDir>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //запрещяем запуск второго приложения на одном компе во избежании коллизий
    QString tmpDir = QDir::tempPath();
    QLockFile lockfile(tmpDir + "/smirnovCRM.lock");
    if(!lockfile.tryLock(100))
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Приложение уже запущено.\n"
                    "Сработал запрет на повторный запуск программы\n"
                    "Разрешено запускать только один CRM на компе!");
        msg.exec();
        return 1;
    }

    AuthDialog w;
    w.show();

    return a.exec();
}
