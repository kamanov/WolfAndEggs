#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T11:43:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WolfAndEggs
TEMPLATE = app


SOURCES += main.cpp \
    ctest.cpp \
    channel.cpp \
    game.cpp \
    DetectMotionReport.cpp \
    MotionDetector.cpp \
    MotionLooper.cpp \
    ResponsibilityArea.cpp \
    stdafx.cpp \
    Detectmotionreport.cpp \
    MotionDetector.cpp

HEADERS  += \
    ctest.h \
    channel.h \
    game.h \
    DetectMotionReport.h \
    MotionDetector.h \
    MotionLooper.h \
    ResponsibilityArea.h \
    Settings.h \
    stdafx.h \
    targetver.h \
    DetectMotionReport.h \
    MotionDetector.h

FORMS    +=



INCLUDEPATH += "C:\opencv\build\include"
INCLUDEPATH += "C:\opencv\build\include\opencv"
INCLUDEPATH += "C:\opencv\build\include\opencv2"

LIBS += "C:\opencv\build\x86\vc10\lib\opencv_core246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_imgproc246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_highgui246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_video246.lib"

OTHER_FILES += \
    WolfAndEggs.pro.user






