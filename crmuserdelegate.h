#ifndef CRMUSERDELEGATE_H
#define CRMUSERDELEGATE_H

#include <QObject>
#include <QItemDelegate>

class CrmUserDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit CrmUserDelegate(QObject *parent = 0);

signals:

public slots:

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // QItemDelegate interface
protected:
    void drawFocus(QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect) const;
};

#endif // CRMUSERDELEGATE_H
