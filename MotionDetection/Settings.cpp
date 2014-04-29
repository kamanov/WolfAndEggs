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

	AREA_WIDTH = 100;
	AREA_HEIGHT = 80;
	SHIFT_FROM_BORDER = 20;

	MAX_DEVIATION = 20;
	COVER_RATIO = 0.001;

	KERNEL_ERO_SIZE = 2;
	KERNEL_DIL_SIZE = 2;

	THRESHOLD = 30;
	DELAY = 30;

	PRO_SETTINGS_MODE = true;
}