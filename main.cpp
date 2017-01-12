#include "authdialog.h"
#include <QApplication>
#include <QLockFile>
#include <QDir>
#include <QMessageBox>
#include <QScopedPointer>// Умный указатель
#include <QLoggingCategory>
#include <QDateTime>
#include <QTextStream>
#include <QFile>


// Умный указатель на файл логирования
QScopedPointer<QFile>   m_logFile;

// Объявляение обработчика
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);


int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Smirnov corp");
    QCoreApplication::setOrganizationDomain("89626906891");
    QCoreApplication::setApplicationName("CRM");


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


    //запускаем логгирование CRM в файл
    m_logFile.reset(new QFile("log.txt"));
    //открываем файл логгирования
    m_logFile.data()->open(QFile::Append | QFile::Text);
    //установка обработчика
    qInstallMessageHandler(messageHandler);



    AuthDialog w;
    w.show();

    return a.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //открываем поток записи в файл
    QTextStream out(m_logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    // По типу определяем, к какому уровню относится сообщение
    switch(type)
    {
        case QtInfoMsg:     out << "INF" ;break;
        case QtDebugMsg:    out << "DBG "; break;
        case QtWarningMsg:  out << "WRN "; break;
        case QtCriticalMsg: out << "CRT "; break;
        case QtFatalMsg:    out << "FTL "; break;
    }
    // Записываем в вывод категорию сообщения и само сообщение
    out << context.category << ":" << msg << endl;
    out.flush();// Очищаем буферизированные данные
}






