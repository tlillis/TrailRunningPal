#-------------------------------------------------
#
# Project created by QtCreator 2018-10-14T12:03:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    athlwindow.cpp \
    coachwindow.cpp \
    importwindow.cpp \
    windowfacade.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    athlwindow.h \
    coachwindow.h \
    importwindow.h \
    windowfacade.h \
    login.h

FORMS    += mainwindow.ui \
    athlwindow.ui \
    coachwindow.ui \
    importwindow.ui
