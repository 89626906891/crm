#include "mybuddy.h"



MyBuddy::MyBuddy() {


}

MyBuddy::~MyBuddy() {}

void MyBuddy::onBuddyState()
{
    BuddyInfo bi = getInfo();
    std::cout << "Buddy " << bi.uri << " is " << bi.presStatus.statusText << std::endl;
}
