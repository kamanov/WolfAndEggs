#ifndef CHANNEL_H
#define CHANNEL_H


#include <QObject>
#include <iostream>
#include "DetectMotionReport.h"
#include "Settings.h"

class MotionLooper;

class Channel : public QObject
{
    Q_OBJECT

    MotionLooper* motionLooper_;

public:
   Channel(MotionLooper * motionLooper);

public slots:
   void process();
   void getSettings(Settings* settings);

signals:
   void finished();
   void sendReport(int numberArea);

};


#endif // CHANNEL_H
