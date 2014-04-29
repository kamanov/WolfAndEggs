#include "channel.h"
#include "MotionLooper.h"

Channel::Channel(MotionLooper * motionLooper): motionLooper_(motionLooper)
{
    motionLooper_->setOwner(this);
}

void Channel :: process(){

    for(int i=0; i!=1000; ++i)
       std::cout << "1";

    motionLooper_->start();

    for(int i=0; i!=1000; ++i)
       std::cout << "2";

    emit finished();
}


