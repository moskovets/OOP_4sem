#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T20:04:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laba1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mygraphicview.cpp \
    work.cpp \
    mycontroller.cpp \
    point.cpp \
    model_action.cpp

HEADERS  += mainwindow.h \
    mygraphicview.h \
    work.h \
    mycontroller.h \
    point.h \
    action.h \
    model.h \
    model_action.h

FORMS    += mainwindow.ui \
    mygraphicview.ui \
    mycontroller.ui
