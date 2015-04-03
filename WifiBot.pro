QT += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app

SOURCES += main.cpp \
    client.cpp \
    mainwindow.cpp

HEADERS += \
    client.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

