#ifndef MOTION_DETECTOR
#define MOTION_DETECTOR

#include "stdafx.h"
#include "ResponsibilityArea.h"
#include "DetectMotionReport.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <sys/types.h>
#include <sys/stat.h>


class MotionDetector
{
	ResponsibilityArea* leftUpArea_;
	ResponsibilityArea* rightUpArea_;
	ResponsibilityArea* leftDownArea_;
	ResponsibilityArea* rightDownArea_;

public:
	MotionDetector();
	MotionDetector(int areaWidth, int areaHeight, int frameWidth, int frameHeight, int shiftFromBorder);
	~MotionDetector();

	void detectMotion(cv::Mat const & motionFrame, DetectMotionReport * report, int const MAX_DEVIATION, int const COVER_RATIO);
	void setAreasCoord(int areaWidth, int areaHeight, int frameWidth, int frameHeight, int shiftFromBorder);
	void drawAreas(cv::Mat & frame, DetectMotionReport* report);
};

#endif // MOTION_DETECTOR