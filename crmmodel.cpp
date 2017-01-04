#include "crmmodel.h"

CRMModel::CRMModel(QObject *parent, QSqlDatabase db)
    : QSqlRelationalTableModel(parent, db)
{

    setTable("orders");
    setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    setJoinMode(QSqlRelationalTableModel::LeftJoin);
    setRelation(fieldIndex("worker_id"),QSqlRelation("workers","worker_id","name"));
    setRelation(fieldIndex("order_status"),QSqlRelation("status","idstatus","status_name"));
    setRelation(fieldIndex("payment_id"),QSqlRelation("payment_type","payment_type_id","payment_name"));
    setRelation(fieldIndex("crmuser_id"),QSqlRelation("users","idusers","name"));

    select();
}


// закрашиваем в таблице поля цветом по значению
QVariant CRMModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::BackgroundColorRole)
    {
        if(QSqlRelationalTableModel::data(this->index(index.row(), 16)).toString() == "bank")
        {
            return QColor(Qt::yellow);
        }
        else if(QSqlRelationalTableModel::data(this->index(index.row(), 16)).toString() == "yandex")
        {
            return QColor(Qt::green);
        }
    }
//    else if (index.column() == fieldIndex("crmuser_id") && role == Qt::EditRole)
//    {
//         return QSqlRelationalTableModel::data(index,Qt::DisplayRole);
//    }
    else if(role==Qt::EditRole)
    {
        return QSqlRelationalTableModel::data(index,role);
    }
    else if(role == Qt::DisplayRole)
    {
        return QSqlRelationalTableModel::data(index,role);
    }
    return QVariant();
}


//Qt::ItemFlags CRMModel::flags(const QModelIndex &index) const
//{
//    if(!index.isValid())
//    {
//        return Qt::NoItemFlags;
//    }
//    if(index.column() == fieldIndex("crmuser_id"))
//    {
//        return QSqlQueryModel::flags(index)| Qt::NoItemFlags;
//    }

//  return QSqlQueryModel::flags(index);
//}



//    if (index.column() == fieldIndex("checked"))
//    {
//        return QSqlQueryModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEditable;
//    }
//QVariant CRMModel::data(const QModelIndex &index, int role) const
//{
//    if(!index.isValid())
//    {
//        return QVariant();
//    }
//    if( index.column() == fieldIndex("checked") && role == Qt::CheckStateRole )
//    {
//        return index.data(Qt::EditRole).toBool() ? QVariant(Qt::Checked) : QVariant(Qt::Unchecked);
//    }
//    return QSqlQueryModel::data(index, role);
//}

//bool CRMModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (role == Qt::CheckStateRole && index.column() == fieldIndex("checked"))
//    {
//        QVariant data = value.toInt() == Qt::Checked ? QVariant(true) : QVariant(false);
//        return QSqlQueryModel::setData(index, data, Qt::EditRole);

//       // emit dataChanged(index,index);
//    }
//    return QSqlQueryModel::setData(index, value, role);
//}



