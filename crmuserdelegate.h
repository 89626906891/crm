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
};

#endif // CRMUSERDELEGATE_H
