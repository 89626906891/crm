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
    newworker.cpp

HEADERS  += authdialog.h \
    mainwindow.h \
    neworder.h \
    crmmodel.h \
    workers.h \
    newworker.h

FORMS    += authdialog.ui \
    mainwindow.ui \
    neworder.ui \
    workers.ui \
    newworker.ui
