#ifndef SALARYDELEGATE_H
#define SALARYDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QStyledItemDelegate>
#include <QString>

class salaryDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    salaryDelegate(QObject *parent = 0);

    // QStyledItemDelegate interface
public:
    QString displayText(const QVariant &value, const QLocale &locale) const;
};

#endif // SALARYDELEGATE_H
