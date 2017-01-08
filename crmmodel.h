#ifndef CRMMODEL_H
#define CRMMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QColor>
class CRMModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:

    CRMModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
private:
//    int m_value;

public:
 //Qt::ItemFlags flags(const QModelIndex &index) const;
//    QVariant data(const QModelIndex &index, int role) const;
//    bool setData(const QModelIndex &index, const QVariant &value, int role);

    // QAbstractItemModel interface
public:
    QVariant data(const QModelIndex &index, int role) const;
};



#endif // CRMMODEL_H
