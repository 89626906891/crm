#ifndef MYBUDDY_H
#define MYBUDDY_H
#include <pjsua2.hpp>
#include <iostream>
#include <pj/file_access.h>

using namespace pj;

class MyBuddy : public Buddy
{

public:
    MyBuddy();
    ~MyBuddy();

    virtual void onBuddyState();
};

#endif // MYBUDDY_H
