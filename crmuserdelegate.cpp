#include "crmuserdelegate.h"

CrmUserDelegate::CrmUserDelegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget *CrmUserDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
      return 0;
}
