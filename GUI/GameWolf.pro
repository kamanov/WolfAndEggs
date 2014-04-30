#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T04:32:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameWolf
TEMPLATE = app


SOURCES += main.cpp\
    egg.cpp \
    game.cpp \
    wolf.cpp \
    aboutwidget.cpp \
    mainmenu.cpp \
    managewidget.cpp \
    recordswidget.cpp \
    dialogrecs.cpp \
    button.cpp \
    updatedwidget.cpp \
    transformrect.cpp \
    mainwidget.cpp \
    settingswidget.cpp

HEADERS  += \
    egg.h \
    game.h \
    wolf.h \
    aboutwidget.h \
    mainmenu.h \
    managewidget.h \
    recordswidget.h \
    dialogrecs.h \
    button.h \
    transformrect.h \
    updatedwidget.h \
    mainwidget.h \
    settingswidget.h

RESOURCES += \
    resources.qrc
RC_FILE = rec.rc
