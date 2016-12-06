#ifndef CRMMODEL_H
#define CRMMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>

class CRMModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:

    CRMModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
private:
    int m_value;

    // QAbstractItemModel interface
public:


    // QAbstractItemModel interface
public:
//    Qt::ItemFlags flags(const QModelIndex &index) const;
};



#endif // CRMMODEL_H
