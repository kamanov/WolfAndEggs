#include "game.h"
#include <iostream>
#include <QTime>

#include <imgproc\imgproc.hpp>
#include <highgui.h>

extern DetectMotionReport* report;
extern Settings* settings;


void sleep(int msec) {
    QTime tt;
    tt.start();
    while(tt.elapsed() < msec);
}



Game::Game()
{
}

void Game::process(){
/*
    while(true){
         std::cerr << "?";
         //game->sendSettings(settings);
         sleep(30); // msec
    }

    emit finished();
    */
    for(int i=0; i!= 100000;++i) {
        sleep(100); // msec
        std::cerr << i <<" ";
    }
}


void Game::getReport() {

    std::cerr << "----------------" << std::endl;

    std::cerr << report->inLeftUpArea_ << "!!!" << std::endl;
    std::cerr << report->inRightUpArea_ << "!!!"  << std::endl;
    std::cerr << report->inLeftDownArea_ << "!!!"  << std::endl;
    std::cerr << report->inRightDownArea_ << "!!!"  << std::endl;

}
