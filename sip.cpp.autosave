#include "sip.h"

sip::sip(QObject *parent) : QObject(parent)
{
    int ret = 0;
    Endpoint ep;

    try
    {
        ep.libCreate();
       // sipReady(ep);
        ret = PJ_SUCCESS;
    }
    catch (Error & err)
    {
//            std::cout << "Exception: " << err.info() << std::endl;
//            ret = 1;
    }

    // Init library
    EpConfig ep_cfg;
    ep_cfg.logConfig.level = 6;
    ep_cfg.logConfig.filename = "/home/alexey/crm/sip.log";
    ep.libInit(ep_cfg);


    // Transport
    TransportConfig tcfg;
    tcfg.port = 5060; //5080 mango
    ep.transportCreate(PJSIP_TRANSPORT_UDP, tcfg);

    // Start library
    ep.libStart();
    // std::cout << "*** PJSUA2 STARTED ***" << std::endl;

    // Add account
    AccountConfig acc_cfg;
    acc_cfg.idUri = "sip:user7@smirnov.mangosip.ru";
    acc_cfg.regConfig.registrarUri = "sip:smirnov.mangosip.ru";
    acc_cfg.sipConfig.authCreds.push_back(AuthCredInfo("digest", "*", SipLogin.toStdString(), 0, SipPass.toStdString()));

//  std::auto_ptr<MyAccount> acc(new MyAccount);
//  acc->create(acc_cfg);

    QThread *acc_thread = new QThread(this);
    MyAccount *acc = new MyAccount;
    try
    {
        acc->create(acc_cfg);
    }
    catch(Error& err)
    {
        std::cout << "Account creation error: " << err.info() << std::endl;
    }
    acc->moveToThread(acc_thread);
    acc_thread->start();

    //pj_thread_sleep(5000);


    // Just wait for ENTER key
    std::cout << "Press ENTER to quit..." << std::endl;
    std::cin.get();
}

void sip::resiveSipParameters(QString login, QString pass)
{
    SipLogin = login;
    SipPass = pass;
}
