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
    ChannelAndDetection/channel.cpp \
    ChannelAndDetection/DetectMotionReport.cpp \
    ChannelAndDetection/MotionDetector.cpp \
    ChannelAndDetection/MotionLooper.cpp \
    ChannelAndDetection/ResponsibilityArea.cpp \
    ChannelAndDetection/Settings.cpp \
    ChannelAndDetection/stdafx.cpp \
    GUI/aboutwidget.cpp \
    GUI/button.cpp \
    GUI/dialogrecs.cpp \
    GUI/egg.cpp \
    GUI/game.cpp \
    GUI/mainmenu.cpp \
    GUI/mainwidget.cpp \
    GUI/managewidget.cpp \
    GUI/recordswidget.cpp \
    GUI/settingswidget.cpp \
    GUI/transformrect.cpp \
    GUI/updatedwidget.cpp \
    GUI/wolf.cpp

HEADERS  += \
    ChannelAndDetection/channel.h \
    ChannelAndDetection/DetectMotionReport.h \
    ChannelAndDetection/MotionDetector.h \
    ChannelAndDetection/MotionLooper.h \
    ChannelAndDetection/ResponsibilityArea.h \
    ChannelAndDetection/Settings.h \
    ChannelAndDetection/stdafx.h \
    ChannelAndDetection/targetver.h \
    GUI/aboutwidget.h \
    GUI/button.h \
    GUI/dialogrecs.h \
    GUI/egg.h \
    GUI/game.h \
    GUI/mainmenu.h \
    GUI/mainwidget.h \
    GUI/managewidget.h \
    GUI/recordswidget.h \
    GUI/settingswidget.h \
    GUI/transformrect.h \
    GUI/updatedwidget.h \
    GUI/wolf.h

RESOURCES += \
    GUI/resources.qrc
RC_FILE = GUI/rec.rc



INCLUDEPATH += "C:\OpenCV\opencv\build\include"
INCLUDEPATH += "C:\OpenCV\opencv\build\include\opencv"
INCLUDEPATH += "C:\OpenCV\opencv\build\include\opencv2"

LIBS += "C:\OpenCV\opencv\build\x86\vc10\lib\opencv_core249.lib"
LIBS += "C:\OpenCV\opencv\build\x86\vc10\lib\opencv_imgproc249.lib"
LIBS += "C:\OpenCV\opencv\build\x86\vc10\lib\opencv_highgui249.lib"
LIBS += "C:\OpenCV\opencv\build\x86\vc10\lib\opencv_video249.lib"
