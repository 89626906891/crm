#include "crmmodel.h"

CRMModel::CRMModel(QObject *parent, QSqlDatabase db)
    : QSqlRelationalTableModel(parent, db)
{

    setTable("orders");
    setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    setJoinMode(QSqlRelationalTableModel::LeftJoin);
    setRelation(fieldIndex("worker_id"),QSqlRelation("workers","worker_id","name"));
    select();
}

//Qt::ItemFlags CRMModel::flags(const QModelIndex &index) const
//{
//    if(index.column() == fieldIndex("name"))
//            {
//                 return QSqlQueryModel::flags(index)| Qt::ItemIsEditable;
//            }
//                 return QSqlQueryModel::flags(index);
//}



