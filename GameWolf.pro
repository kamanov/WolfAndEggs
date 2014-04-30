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
    channel.cpp \
    chmain.cpp \
    DetectMotionReport.cpp \
    MotionDetector.cpp \
    MotionLooper.cpp \
    ResponsibilityArea.cpp \
    Settings.cpp \
    stdafx.cpp \
    wolf.cpp

HEADERS  += \
    egg.h \
    game.h \
    aboutwidget.h \
    mainmenu.h \
    managewidget.h \
    recordswidget.h \
    dialogrecs.h \
    button.h \
    transformrect.h \
    updatedwidget.h \
    mainwidget.h \
    channel.h \
    DetectMotionReport.h \
    MotionDetector.h \
    MotionLooper.h \
    ResponsibilityArea.h \
    Settings.h \
    stdafx.h \
    targetver.h \
    wolf.h

RESOURCES += \
    resources.qrc
RC_FILE = rec.rc

OTHER_FILES += \
    vc100.pdb \
    chick.gif \
    chickRight.gif \
    hensLeft.gif \
    hensRight.gif \
    zaya.gif \
    ic1.jpg \
    back.png \
    backabout.png \
    background1.png \
    backman.png \
    backmenu.png \
    but1.png \
    but2.png \
    chickenscore.png \
    dialog.png \
    ic1.png \
    icon.png \
    leftBottom.png \
    leftTop.png \
    menuBut.png \
    pause.png \
    rightBottom.png \
    rightTop.png \
    theend.png \
    111.ico \
    ic.ico \
    rec.rc \
    GameWolf.pro.user \
    GameWolf.pro.user.b871a8e.2.7pre1



INCLUDEPATH += "C:\opencv\build\include"
INCLUDEPATH += "C:\opencv\build\include\opencv"
INCLUDEPATH += "C:\opencv\build\include\opencv2"

LIBS += "C:\opencv\build\x86\vc10\lib\opencv_core246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_imgproc246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_highgui246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_video246.lib"
