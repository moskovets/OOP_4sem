#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T21:36:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laba4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cbutton.cpp \
    cdoor.cpp \
    ccabin.cpp \
    ccontroller.cpp

HEADERS  += mainwindow.h \
    cbutton.h \
    cdoor.h \
    times.h \
    ccabin.h \
    ccontroller.h

FORMS    += mainwindow.ui
