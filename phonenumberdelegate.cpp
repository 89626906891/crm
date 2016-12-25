#include "phonenumberdelegate.h"

PhoneNumberDelegate::PhoneNumberDelegate(QObject *parent)
:QItemDelegate(parent)
{
}

QWidget *PhoneNumberDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
    {
        QLineEdit *editor = new QLineEdit(parent);
        editor->installEventFilter(const_cast<PhoneNumberDelegate*>(this));
        if (editor)
        {
            editor->setInputMask("+7 (999) 999-99-99");
            return editor;
        }
    }
    else
    {
      return QItemDelegate::createEditor(parent,option,index);
    }
}
void PhoneNumberDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.isValid())
    {
      QLineEdit *line = static_cast<QLineEdit*>(editor);
      model->setData(index, line->text(), Qt::EditRole);

    }
    else
    {
      QItemDelegate::setModelData(editor,model,index);
    }
}
