#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QItemDelegate>
#include <QApplication>
#include <QDialog>
#include <QMouseEvent>
#include <QDebug>

#include <QLabel>


#include "uploadfileform.h"
#include "movetocenter.h"

class buttonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    buttonDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
signals:
    void createNewUpload();
private:

};

#endif // BUTTONDELEGATE_H
