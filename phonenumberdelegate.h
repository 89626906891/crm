#ifndef PHONENUMBERDELEGATE_H
#define PHONENUMBERDELEGATE_H
#include <QObject>
#include <QItemDelegate>
#include <QLineEdit>
class PhoneNumberDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    PhoneNumberDelegate(QObject *parent = 0);

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // PHONENUMBERDELEGATE_H
