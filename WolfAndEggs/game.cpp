#include "game.h"
#include <iostream>

Game::Game()
{
}

void Game::process(){

    emit finished();
}


void Game::getReport(DetectMotionReport dmr) {

    std::cout << dmr.inLeftUpArea_ << std::endl;
    std::cout << dmr.inRightUpArea_ << std::endl;
    std::cout << dmr.inLeftDownArea_ << std::endl;
    std::cout << dmr.inRightDownArea_ << std::endl;
}
