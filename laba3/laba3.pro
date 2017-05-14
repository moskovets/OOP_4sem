#-------------------------------------------------
#
# Project created by QtCreator 2017-05-09T14:40:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laba3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cpoint.cpp \
    cline.cpp \
    cexception.cpp \
    cbasevector.cpp \
    ctransformmatrix.cpp

HEADERS  += mainwindow.h \
    cpoint.h \
    cline.h \
    cexception.h \
    cbasevector.h \
    cvector.h \
    cvector_imp.h \
    cmatrix.h \
    cmatrix_imp.h \
    ctransformmatrix.h

FORMS    += mainwindow.ui
