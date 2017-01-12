#ifndef MYACCOUNT_H
#define MYACCOUNT_H
#include <pjsua2.hpp>
#include <iostream>
#include <memory>
#include <pj/file_access.h>

#include "mycall.h"

#define THIS_FILE "main.cpp"

using namespace pj;

class MyAccount : public Account
{
public:
    std::vector<Call *> calls;

public:
    MyAccount();

    ~MyAccount();

    void removeCall(Call *call);

    virtual void onRegState(OnRegStateParam &prm);

    virtual void onIncomingCall(OnIncomingCallParam &iprm);
};

#endif // MYACCOUNT_H
