#include <QApplication>
#include <QIcon>
#include "GUI/mainwidget.h"

#include <iostream>
#include <QThread>

#include <string>

#include "ChannelAndDetection/channel.h"
#include "ChannelAndDetection/MotionLooper.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon ic(":/ic.ico");
    QApplication::setWindowIcon(ic);

    Settings settings;
    MainWidget mainWidget(&settings);

    MotionLooper* ml = new MotionLooper(&settings);
    Channel* channel= new Channel(ml);
    QThread* thread = new QThread;

    channel->moveToThread(thread);

    QObject::connect(channel, SIGNAL(sendReport(int)), &mainWidget, SLOT(setWolfPosition(int)), Qt::DirectConnection);
    QObject::connect(&mainWidget, SIGNAL(endSig()), thread, SLOT(terminate()));
    QObject::connect(thread, SIGNAL(started()), channel, SLOT(process()));

    thread->start();

    mainWidget.show();
    a.exec();
    thread->wait();

    delete thread;
    delete channel;
    delete ml;

    return 0;
}
