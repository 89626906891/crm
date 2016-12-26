#ifndef POPUPCALDELEGATE_H
#define POPUPCALDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QItemDelegate>

class popUpCalDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    popUpCalDelegate(bool calpopup = true, QObject *parent = 0);

private:
    bool m_calpopup;

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // POPUPCALDELEGATE_H








