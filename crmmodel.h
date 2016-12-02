#ifndef CRMMODEL_H
#define CRMMODEL_H

#include <QObject>
#include <QSqlTableModel>

class CRMModel : public QSqlTableModel
{
    Q_OBJECT
public:
    //CRMModel(); // *1
    CRMModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase()); // *2 // if we call CRMModel() the application will not know what to call *1 or *2
private:
    int m_value;
};



#endif // CRMMODEL_H
