#include "salarydelegate.h"

salaryDelegate::salaryDelegate(QObject *parent):QStyledItemDelegate(parent)
{

}

QString salaryDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    QString val = QStyledItemDelegate::displayText(value,locale);
    QString s = val+QString::fromUtf8("\tруб.");
    return s;
}
