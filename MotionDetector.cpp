#include "stdafx.h"
#include "MotionDetector.h"

DetectMotionReport::DetectMotionReport() :
inLeftUpArea_(false),
inRightUpArea_(false),
inLeftDownArea_(false),
inRightDownArea_(false)
{}

DetectMotionReport::DetectMotionReport(bool inLeftUpArea, bool inRightUpArea, bool inLeftDownArea, bool inRightDownArea): 
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

MotionDetector::MotionDetector(int areaWidth, int areaHeight, int frameWidth, int frameHeight, int shiftFromBorder)
{
	leftUpArea_ = new ResponsibilityArea(frameWidth - shiftFromBorder - areaWidth, shiftFromBorder,
		areaWidth, areaHeight, "leftUpArea");

	rightUpArea_ = new ResponsibilityArea(shiftFromBorder, shiftFromBorder,
		areaWidth, areaHeight, "rightUpArea");

	leftDownArea_ = new ResponsibilityArea(frameWidth - shiftFromBorder - areaWidth, frameHeight - shiftFromBorder - areaHeight,
		areaWidth, areaHeight, "leftDownArea");

	rightDownArea_ = new ResponsibilityArea(shiftFromBorder, frameHeight - shiftFromBorder - areaHeight,
		areaWidth, areaHeight, "rightDownArea");
}

MotionDetector::~MotionDetector()
{
	delete leftUpArea_;
	delete rightUpArea_;
	delete leftDownArea_;
	delete rightDownArea_;
}

void MotionDetector::detectMotion(cv::Mat const & motionFrame, DetectMotionReport & report)
{
	if (leftUpArea_->detectMotion(motionFrame)) {
		report.inLeftUpArea_ = true;
	}

	if (rightUpArea_->detectMotion(motionFrame)) {
		report.inRightUpArea_ = true;
	}

	if (leftDownArea_->detectMotion(motionFrame)) {
		report.inLeftDownArea_ = true;
	}

	if (rightDownArea_->detectMotion(motionFrame)) {
		report.inRightDownArea_ = true;
	}
}

void MotionDetector::drawAreas(cv::Mat & frame) {
	leftUpArea_->drawArea(frame);
	rightUpArea_->drawArea(frame);
	leftDownArea_->drawArea(frame);
	rightDownArea_->drawArea(frame);
}



