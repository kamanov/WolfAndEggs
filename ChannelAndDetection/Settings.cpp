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
    COVER_RATIO = 2;

	KERNEL_ERO_SIZE = 2;
    KERNEL_DIL_SIZE = 10;

	THRESHOLD = 30;
    DELAY = 30;

	PRO_SETTINGS_MODE = true;
    ERODE = false;
	DILATE = true;

    STOP = false;
}

void Settings::changeFrameWidth(int x) { FRAME_WIDTH = x; }
void Settings::changeFrameHeigth(int x) { FRAME_WIDTH = x; }
void Settings::changeAreaWidth(int x ) { AREA_WIDTH = x; }
void Settings::changeAreaHeight(int x) { AREA_HEIGHT = x; }
void Settings::changeShiftFromBorder(int x) { SHIFT_FROM_BORDER = x; }

void Settings::changeMaxDeviation( int x) { MAX_DEVIATION = x; }
void Settings::changeCoverRatio( int x) { COVER_RATIO = x; }

void Settings::changeKernelEroSize(int x) { KERNEL_ERO_SIZE = x; }
void Settings::changeKernelDilSize(int x){ KERNEL_DIL_SIZE = x; }

void Settings::changeErode(bool b) { ERODE = b; }
void Settings::changeDilate(bool b) { DILATE = b; }

void Settings::changeThreshold(int x) { THRESHOLD = x; }
void Settings::changeDelay(int x) { DELAY = x; }

void Settings::changeProSettigsMode(bool b) { PRO_SETTINGS_MODE = b; }

void Settings::changeStop(bool b) { STOP = b; }
