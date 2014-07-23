#-------------------------------------------------
#
# Project created by QtCreator 2014-07-02T21:18:52
#
#-------------------------------------------------

QT       += core gui axcontainer sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NameFix
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    excel.cpp \
    mmm.cpp \
    textdict.cpp \
    manualfix.cpp \
    mdb.cpp \
    mdbdict.cpp

HEADERS  += mainwindow.h \
    excel.h \
    mmm.h \
    textdict.h \
    manualfix.h \
    mdb.h \
    mdbdict.h

FORMS    += mainwindow.ui \
    manualfix.ui
