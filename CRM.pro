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
    history.cpp

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
    history.h

FORMS    += authdialog.ui \
    mainwindow.ui \
    neworder.ui \
    workers.ui \
    newworker.ui \
    discounts.ui \
    newdiscount.ui \
    about.ui \
    history.ui

RESOURCES += \
    resources.qrc
