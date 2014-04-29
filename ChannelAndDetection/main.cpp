#include <QApplication>

#include <iostream>
#include <QThread>
#include <QApplication>
#include <QWidget>
#include <QFont>
#include <QPushButton>

#include <string>

#include "channel.h"
#include "MotionLooper.h"
#include "game.h"




 int main(int argc, char *argv[])
 {

     QApplication app(argc, argv);

     Settings* settings = new Settings();


     MotionLooper* ml = new MotionLooper(settings);
     Channel* channel= new Channel(ml);
     QThread* thread = new QThread;
     channel->moveToThread(thread);

     Game* game = new Game();

     QObject::connect(channel, SIGNAL(sendReport(int)), game, SLOT(getReport(int)), Qt::DirectConnection);
     //QObject::connect(game, SIGNAL(sendSettings(Settings*)), channel, SLOT(getSettings(Settings*)));
     QObject::connect(thread, SIGNAL(started()), channel, SLOT(process()));
     QObject::connect(channel, SIGNAL(finished()), thread, SLOT(quit()));
     QObject::connect(channel, SIGNAL(finished()), channel, SLOT(deleteLater()));
     QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

     thread->start();

     //QThread* thread2 = new QThread;
     //game->moveToThread(thread2);

     //QObject::connect(thread2, SIGNAL(started()), game, SLOT(process()));
     //QObject::connect(game, SIGNAL(finished()), thread2, SLOT(quit()));
  //   QObject::connect(game, SIGNAL(finished()), game, SLOT(deleteLater()));
    // QObject::connect(thread2, SIGNAL(finished()), thread2, SLOT(deleteLater()));

    // thread2->start();
     //DetectMotionReport report;
     //channel->sendReport(report);




     return app.exec();
}
