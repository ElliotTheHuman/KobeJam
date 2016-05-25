#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T14:37:45
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KobeJam_Prototype
TEMPLATE = app

CONFIG += resources_big

SOURCES += main.cpp\
        mainwindow.cpp \
    easy_mode.cpp \
    medium_mode.cpp \
    jordan_mode.cpp \
    credits.cpp \
    win_screen.cpp

HEADERS  += mainwindow.h \
    easy_mode.h \
    medium_mode.h \
    jordan_mode.h \
    credits.h \
    win_screen.h

FORMS    += mainwindow.ui \
    easy_mode.ui \
    medium_mode.ui \
    jordan_mode.ui \
    credits.ui \
    win_screen.ui

RESOURCES += \
    resources.qrc
