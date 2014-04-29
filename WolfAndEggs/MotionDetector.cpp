#include "stdafx.h"
#include "MotionDetector.h"


MotionDetector::MotionDetector()
{
	leftUpArea_ = new ResponsibilityArea(0, 0, 0, 0, "leftUpArea");

	rightUpArea_ = new ResponsibilityArea(0, 0, 0, 0, "rightUpArea");

	leftDownArea_ = new ResponsibilityArea(0, 0, 0, 0, "leftDownArea");

	rightDownArea_ = new ResponsibilityArea(0, 0, 0, 0, "rightDownArea");
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

void MotionDetector::detectMotion(cv::Mat const & motionFrame, DetectMotionReport & report, int const MAX_DEVIATION, int const COVER_RATIO)
{
	if (leftUpArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report.inLeftUpArea_ = true;
	}

	if (rightUpArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report.inRightUpArea_ = true;
	}

	if (leftDownArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report.inLeftDownArea_ = true;
	}

	if (rightDownArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report.inRightDownArea_ = true;
	}
}

void MotionDetector::setAreasCoord(int areaWidth, int areaHeight, int frameWidth, int frameHeight, int shiftFromBorder)
{
	leftUpArea_->setSize(frameWidth - shiftFromBorder - areaWidth, shiftFromBorder,
		areaWidth, areaHeight);
	rightUpArea_->setSize(shiftFromBorder, shiftFromBorder,
		areaWidth, areaHeight);
	leftDownArea_->setSize(frameWidth - shiftFromBorder - areaWidth, frameHeight - shiftFromBorder - areaHeight,
		areaWidth, areaHeight);
	rightDownArea_->setSize(shiftFromBorder, frameHeight - shiftFromBorder - areaHeight,
		areaWidth, areaHeight);
}

void MotionDetector::drawAreas(cv::Mat & frame) {
	leftUpArea_->drawArea(frame);
	rightUpArea_->drawArea(frame);
	leftDownArea_->drawArea(frame);
	rightDownArea_->drawArea(frame);
}
