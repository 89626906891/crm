#ifndef HISTORYSIP_H
#define HISTORYSIP_H

#include <QWidget>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>

#include "loggingcategories.h"



namespace Ui {
class historySIP;
}

class historySIP : public QWidget
{
    Q_OBJECT

public:
    explicit historySIP(QWidget *parent = 0);
    ~historySIP();

private slots:
    void on_closePushButton_clicked();

private:
    Ui::historySIP *ui;
};

#endif // HISTORYSIP_H
