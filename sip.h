#ifndef SIP_H
#define SIP_H

#include <QObject>
#include <QDebug>

#include <pjsua2.hpp>
#include <iostream>
#include <memory>
#include <pj/file_access.h>
#define THIS_FILE "main.cpp"
#include "myaccount.h"
#include "mycall.h"
#include "mybuddy.h"

class sip : public QObject
{
    Q_OBJECT
public:
    explicit sip(QObject *parent = 0);
    void resiveSipParameters(QString login,QString pass);
    void startSip();

public slots:
private:
    QString SipLogin;
    QString SipPass;

};

#endif // SIP_H
