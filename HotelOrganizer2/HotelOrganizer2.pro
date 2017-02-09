#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T21:18:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelOrganizer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    adminwindow.cpp \
    roomwindow.cpp \
    infoapplication.cpp \
    infoauthors.cpp \
    BazaDanych.cpp \
    BazaLogow.cpp \
    Klienci.cpp \
    Pokoje.cpp \
    Rezerwacje.cpp \
    Uzytkownicy.cpp

HEADERS  += mainwindow.h \
    adminwindow.h \
    roomwindow.h \
    infoapplication.h \
    infoauthors.h \
    BazaDanych.h \
    BazaLogow.h \
    Klienci.h \
    Pokoje.h \
    Rezerwacje.h \
    Uzytkownicy.h

FORMS    += mainwindow.ui \
    adminwindow.ui \
    roomwindow.ui \
    infoapplication.ui \
    infoauthors.ui

RESOURCES += \
    resources.qrc
