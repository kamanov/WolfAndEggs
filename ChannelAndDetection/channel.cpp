#include "channel.h"
#include "MotionLooper.h"
#include <QDebug>

extern DetectMotionReport* report;
extern Settings* settings;


Channel::Channel(MotionLooper * motionLooper): motionLooper_(motionLooper)
{
    motionLooper_->setOwner(this);
}

void Channel :: process(){


    motionLooper_->start();
    emit finished();

}

void Channel::getSettings(Settings* settings)
{
    motionLooper_->setSettings(settings);
}
