#include "myaccount.h"


MyAccount::MyAccount()
{}

MyAccount::~MyAccount()
{
    std::cout << "*** Account is being deleted: No of calls="
              << calls.size() << std::endl;
}

void MyAccount::removeCall(Call *call)
{
    for (std::vector<Call *>::iterator it = calls.begin();
         it != calls.end(); ++it)
    {
        if (*it == call) {
            calls.erase(it);
            break;
        }
    }
}

void MyAccount::onRegState(OnRegStateParam &prm)
{
    AccountInfo ai = getInfo();
    std::cout << (ai.regIsActive? "*** Register: code=" : "*** Unregister: code=")
              << prm.code << std::endl;
}

void MyAccount::onIncomingCall(OnIncomingCallParam &iprm)
{
    Call *call = new MyCall(*this, iprm.callId);
    CallInfo ci = call->getInfo();
    CallOpParam prm;

    std::cout << "*** Incoming Call: " <<  ci.remoteUri << " [" << ci.stateText << "]" << std::endl;

    calls.push_back(call);
    prm.statusCode = (pjsip_status_code)200;
    call->answer(prm);
}
