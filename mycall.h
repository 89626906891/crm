#ifndef MYCALL_H
#define MYCALL_H
#include <pjsua2.hpp>
#include <iostream>
#include <memory>
#include <pj/file_access.h>


#include "myaccount.h"

#define THIS_FILE "main.cpp"

using namespace pj;

class MyAccount;

class MyCall : public Call
{
private:
    MyAccount *myAcc;

public:
    MyCall(Account &acc, int call_id = PJSUA_INVALID_ID);

    virtual void onCallState(OnCallStateParam &prm);//когда состояние вызова изменилось
    virtual void onCallMediaState(OnCallMediaStateParam &prm);//когда состояние микр или динамик изменилось
};

#endif // MYCALL_H
