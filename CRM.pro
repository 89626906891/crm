#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T12:15:25
#
#-------------------------------------------------

QT       += core gui sql
CONFIG += C++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRM
TEMPLATE = app

LIBS += `pkg-config --cflags --libs libpjproject`
PKGCONFIG += libpjproject

SOURCES += main.cpp\
        authdialog.cpp \
    mainwindow.cpp \
    neworder.cpp \
    crmmodel.cpp \
    workers.cpp \
    newworker.cpp \
    discounts.cpp \
    newdiscount.cpp \
    checkboxdelegate.cpp \
    about.cpp \
    comboboxstatusdelegate.cpp \
    phonenumberdelegate.cpp \
    salarydelegate.cpp \
    buttondelegate.cpp \
    loggingcategories.cpp \
    history.cpp \
    movetocenter.cpp \
    crmusers.cpp \
    newcrmuser.cpp \
    crmuserdelegate.cpp \
    uploadfileform.cpp \
    contactsform.cpp \
    newcontact.cpp \
    myaccount.cpp \
    mycall.cpp \
    historysip.cpp \
    mybuddy.cpp \
    callwindow.cpp \
    sip.cpp

HEADERS  += authdialog.h \
    mainwindow.h \
    neworder.h \
    crmmodel.h \
    workers.h \
    newworker.h \
    discounts.h \
    newdiscount.h \
    checkboxdelegate.h \
    about.h \
    comboboxstatusdelegate.h \
    phonenumberdelegate.h \
    salarydelegate.h \
    buttondelegate.h \
    loggingcategories.h \
    history.h \
    movetocenter.h \
    crmusers.h \
    newcrmuser.h \
    crmuserdelegate.h \
    uploadfileform.h \
    contactsform.h \
    newcontact.h \
    myaccount.h \
    mycall.h \
    historysip.h \
    mybuddy.h \
    callwindow.h \
    sip.h

FORMS    += authdialog.ui \
    mainwindow.ui \
    neworder.ui \
    workers.ui \
    newworker.ui \
    discounts.ui \
    newdiscount.ui \
    about.ui \
    history.ui \
    crmusers.ui \
    newcrmuser.ui \
    uploadfileform.ui \
    contactsform.ui \
    newcontact.ui \
    historysip.ui \
    callwindow.ui

RESOURCES += \
    resources.qrc
