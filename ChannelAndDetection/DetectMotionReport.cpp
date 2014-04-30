#include "stdafx.h"
#include "DetectMotionReport.h"

DetectMotionReport::DetectMotionReport() :
inLeftUpArea_(false),
inRightUpArea_(false),
inLeftDownArea_(false),
inRightDownArea_(false)
{}

DetectMotionReport::DetectMotionReport(bool inLeftUpArea, bool inRightUpArea, bool inLeftDownArea, bool inRightDownArea) :
inLeftUpArea_(inLeftUpArea),
inRightUpArea_(inRightUpArea),
inLeftDownArea_(inLeftDownArea),
inRightDownArea_(inRightDownArea)
{}

void DetectMotionReport::clear()
{
	inLeftUpArea_ = false;
	inRightUpArea_ = false;
	inLeftDownArea_ = false;
	inRightDownArea_ = false;
}