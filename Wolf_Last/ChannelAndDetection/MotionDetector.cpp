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

void MotionDetector::detectMotion(cv::Mat const & motionFrame, DetectMotionReport * report, int const MAX_DEVIATION, int const COVER_RATIO)
{
	if (leftUpArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report->inLeftUpArea_ = true;
	}
	else {
		report->inLeftUpArea_ = false;
	}

	if (rightUpArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report->inRightUpArea_ = true;
	}
	else {
		report->inRightUpArea_ = false;
	}

	if (leftDownArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report->inLeftDownArea_ = true;
	}
	else {
		report->inLeftDownArea_ = false;
	}

	if (rightDownArea_->detectMotion(motionFrame, MAX_DEVIATION, COVER_RATIO)) {
		report->inRightDownArea_ = true;
	}
	else {
		report->inRightDownArea_ = false;
	}
}

void MotionDetector::setAreasCoord(int areaWidth, int areaHeight, int frameWidth, int frameHeight, int shiftFromBorder)
{
	leftUpArea_->setCoordSize(frameWidth - shiftFromBorder - areaWidth, shiftFromBorder,
		areaWidth, areaHeight);
	rightUpArea_->setCoordSize(shiftFromBorder, shiftFromBorder,
		areaWidth, areaHeight);
	leftDownArea_->setCoordSize(frameWidth - shiftFromBorder - areaWidth, frameHeight - shiftFromBorder - areaHeight,
		areaWidth, areaHeight);
	rightDownArea_->setCoordSize(shiftFromBorder, frameHeight - shiftFromBorder - areaHeight,
		areaWidth, areaHeight);
}

void MotionDetector::drawAreas(cv::Mat & frame, DetectMotionReport* report) {
	leftUpArea_->drawArea(frame, report->inLeftUpArea_);
	rightUpArea_->drawArea(frame, report->inRightUpArea_);
	leftDownArea_->drawArea(frame, report->inLeftDownArea_);
	rightDownArea_->drawArea(frame, report->inRightDownArea_);
}
