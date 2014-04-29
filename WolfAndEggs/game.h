#ifndef GAME_H
#define GAME_H


#include <QObject>
#include <iostream>
#include "detectmotionreport.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game();

public slots:
    void process();
    void getReport(DetectMotionReport dmr);

signals:
   void finished();
};

#endif // GAME_H
