#include "checkboxdelegate.h"

CheckBoxDelegate::CheckBoxDelegate(QObject *parent)
: QItemDelegate(parent)
{
}

//создает виджет редактора значения
QWidget *CheckBoxDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const
{
  if(index.isValid())
  {
    QCheckBox *editor = new QCheckBox(parent);
    editor->setCheckable(true); //может и не надо
    editor->installEventFilter(const_cast<CheckBoxDelegate*>(this)); //Регистрация фильтра событий (чтобы отслеживали изменения в чекбоксе)
    return editor;
  }
  else
  {
    return QItemDelegate::createEditor(parent,option,index);
  }
}
//передает значение от модели в редактор
void CheckBoxDelegate::setEditorData(QWidget *editor,const QModelIndex &index) const
{
  if(index.isValid())
  {
    QString value = index.model()->data(index,Qt::EditRole).toString();
    QCheckBox *checkBox=static_cast<QCheckBox*>(editor);
    if (value=="1")
    {
        checkBox->setCheckState(Qt::Checked);
    }
    else
    {
        checkBox->setCheckState(Qt::Unchecked);
    }
  }
  else
  {
    QItemDelegate::setEditorData(editor,index);
  }
}

//занчение от редактора в модель
void CheckBoxDelegate::setModelData(QWidget *editor,QAbstractItemModel *model,const QModelIndex &index) const
{
  if(index.isValid())
  {
    QCheckBox *checkBox=static_cast<QCheckBox*>(editor);
    QString value;
    if (checkBox->checkState()==Qt::Checked)
    {
        qDebug() << "order is Checked";
        value="1";
    }
    else
    {
        qDebug() << "order is UnChecked";
        value="0";
    }
    model->setData(index,value);
  }
  else
  {
    QItemDelegate::setModelData(editor,model,index);
  }
}


void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const
{
  if(index.isValid())
  {
    editor->setGeometry(option.rect);
  }
  else
  {
     QItemDelegate::updateEditorGeometry(editor,option,index);
  }

}
//отрисовка чекбокса в самой таблице tableview
void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    bool data = index.model()->data(index, Qt::DisplayRole).toBool();
    QStyleOptionButton checkboxstyle;
//    QRect checkbox_rect = QApplication::style()->subElementRect(QStyle::SE_CheckBoxIndicator, &checkboxstyle); //установка по центру ячейки
    checkboxstyle.rect = option.rect;
//    checkboxstyle.rect.setLeft(option.rect.x() + option.rect.width()/2 - checkbox_rect.width()/2);
    checkboxstyle.palette.setColor(QPalette::Highlight, index.data(Qt::BackgroundRole).value<QColor>());
    if(data)
        checkboxstyle.state = QStyle::State_On|QStyle::State_Enabled;
    else
        checkboxstyle.state = QStyle::State_Off|QStyle::State_Enabled;
    QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkboxstyle, painter);

}


