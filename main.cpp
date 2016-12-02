#include "authdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthDialog w;
    w.show();

    return a.exec();
}
