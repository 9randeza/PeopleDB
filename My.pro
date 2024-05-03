TEMPLATE = app
CONFIG += console c++20
TARGET = APP

QT += core gui
QT += sql
QT += widgets

greaterThan(QT_MAJOR_VERSION,4):

SOURCES += dbmanager.cpp \
    interfacedb.cpp \
    main.cpp

HEADERS += \
    dbmanager.h \
    interfacedb.h
