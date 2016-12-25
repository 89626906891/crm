//#include "comboboxstatusdelegate.h"

//ComboBoxStatusDelegate::ComboBoxStatusDelegate(QObject *parent)
//: QSqlRelationalDelegate(parent)
//{
//}
//создает виджет редактора значения
//QWidget *ComboBoxStatusDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{

//    if(index.isValid())
//    {
//      QComboBox *editor = new QComboBox(parent);
//      editor->installEventFilter(const_cast<ComboBoxStatusDelegate*>(this));
//      return editor;
//    }
//    else
//    {
//      return QItemDelegate::createEditor(parent,option,index);
//    }
//}
//из модели в редактор
//void ComboBoxStatusDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{
//    if(index.isValid())
//    {
//      QString value = index.model()->data(index, Qt::EditRole).toString();
//      QComboBox *comboBox = static_cast<QComboBox*>(editor);
//      comboBox->addItem(value);
//      if (value=="cancel")
//      {
//        QWidget *reasonWidget = new QWidget;
////        QLineEdit *reasonLineEdit = new QLineEdit(reasonWidget);
////        QPushButton *reasonPushButton = new QPushButton(reasonWidget);
//       reasonWidget->show();
//      }

//    }
//    else
//    {
//      QItemDelegate::setEditorData(editor,index);
//    }
//}
//передает значение от редактора в модель
//void ComboBoxStatusDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{
//    if(index.isValid())
//    {
//      QComboBox *comboBox = static_cast<QComboBox*>(editor);
//      model->setData(index, comboBox->currentText(), Qt::EditRole);

//    }
//    else
//    {
//      QItemDelegate::setModelData(editor,model,index);
//    }
//}


//void ComboBoxStatusDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    if(index.isValid())
//    {
//      editor->setGeometry(option.rect);
//    }
//    else
//    {
//       QItemDelegate::updateEditorGeometry(editor,option,index);
//    }

//}
