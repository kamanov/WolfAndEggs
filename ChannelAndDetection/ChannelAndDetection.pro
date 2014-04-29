#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T00:32:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChannelAndDetection
TEMPLATE = app


SOURCES += \
    channel.cpp \
    DetectMotionReport.cpp \
    game.cpp \
    main.cpp \
    MotionDetector.cpp \
    MotionLooper.cpp \
    ResponsibilityArea.cpp \
    Settings.cpp \
    stdafx.cpp

HEADERS  += \
    channel.h \
    DetectMotionReport.h \
    game.h \
    MotionDetector.h \
    MotionLooper.h \
    ResponsibilityArea.h \
    Settings.h \
    stdafx.h \
    targetver.h

FORMS    +=

OTHER_FILES += \
    ChannelAndDetection.pro.user \
    ReadMe.txt

INCLUDEPATH += "C:\opencv\build\include"
INCLUDEPATH += "C:\opencv\build\include\opencv"
INCLUDEPATH += "C:\opencv\build\include\opencv2"

LIBS += "C:\opencv\build\x86\vc10\lib\opencv_core246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_imgproc246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_highgui246.lib"
LIBS += "C:\opencv\build\x86\vc10\lib\opencv_video246.lib"

