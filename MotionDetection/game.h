#ifndef GAME_H
#define GAME_H


#include <QObject>
#include <iostream>
#include "detectmotionreport.h"
#include "Settings.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game();

public slots:
    void process();
    void getReport();

signals:
   void sendSettings(Settings*);
   void finished();
};

#endif // GAME_H
