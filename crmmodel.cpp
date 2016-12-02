#include "crmmodel.h"

CRMModel::CRMModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)//, m_value(9000)
{
    // executed after object creation
    //m_value = 1;
    setTable("orders");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    select();
}
