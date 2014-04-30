#include "stdafx.h"
#include "Settings.h"

Settings::Settings()
{
	setDefault();
}

void Settings::setDefault()
{
	FRAME_WIDTH = 640;
	FRAME_HEIGHT = 480;

    AREA_WIDTH = FRAME_WIDTH / 10;
    AREA_HEIGHT = FRAME_HEIGHT / 5;
    SHIFT_FROM_BORDER = 30;

    MAX_DEVIATION = 1000;
	COVER_RATIO = 0.002;

	KERNEL_ERO_SIZE = 2;
    KERNEL_DIL_SIZE = 10;

	THRESHOLD = 30;
    DELAY = 30;

	PRO_SETTINGS_MODE = true;
    ERODE = false;
	DILATE = true;
}
