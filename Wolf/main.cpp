#include <QApplication>
#include <QIcon>
#include "mainwidget.h"

#include <iostream>
#include <QThread>

#include <string>

#include "channel.h"
#include "MotionLooper.h"
#include "wolf.h"

//Q_DECLARE_METATYPE(Wolf::WolfPosition)

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

    QObject::connect(thread, SIGNAL(started()), channel, SLOT(process()));
    QObject::connect(channel, SIGNAL(finished()), thread, SLOT(quit()));
    QObject::connect(channel, SIGNAL(finished()), channel, SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();

    mainWidget.show();
    a.exec();

    return 0;
}
