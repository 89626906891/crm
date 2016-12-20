#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QWidget>
#include <QCheckBox>
#include <QDebug>
#include <QApplication>

class CheckBoxDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    CheckBoxDelegate(QObject *parent = 0);




    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CHECKBOXDELEGATE_H
