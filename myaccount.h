#ifndef MYACCOUNT_H
#define MYACCOUNT_H
#include <pjsua2.hpp>
#include <iostream>
#include <memory>
#include <pj/file_access.h>
#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include "mycall.h"

#include "callwindow.h"

#define THIS_FILE "main.cpp"

using namespace pj;

class MyAccount :public QObject,public Account
{
    Q_OBJECT

public:
    std::vector<Call *> calls;
    explicit MyAccount(QObject *parent = 0);


//public:
//    MyAccount();

    ~MyAccount();

    void removeCall(Call *call);

    virtual void onRegState(OnRegStateParam &prm);

    virtual void onIncomingCall(OnIncomingCallParam &iprm);


};

#endif // MYACCOUNT_H
