#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QItemDelegate>
#include <QApplication>
#include <QDialog>
#include <QMouseEvent>
#include <QDebug>

class buttonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    buttonDelegate(QObject *parent = 0);

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // BUTTONDELEGATE_H
