#ifndef CHANNEL_H
#define CHANNEL_H


#include <QObject>
#include <iostream>
#include "DetectMotionReport.h"

class MotionLooper;

class Channel : public QObject
{
    Q_OBJECT

    MotionLooper* motionLooper_;

public:
   Channel(MotionLooper * motionLooper);

public slots:
   void process();

signals:
   void finished();
   void sendReport(DetectMotionReport);

};


#endif // CHANNEL_H
