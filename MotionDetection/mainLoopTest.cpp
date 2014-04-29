#include "stdafx.h"
#include "MotionLooper.h"

int main()
{
	Settings* settings = new Settings();
	MotionLooper motionLooper(settings);
	motionLooper.start();
}