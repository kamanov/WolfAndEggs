#ifndef MOTION_DETECTOR
#define MOTION_DETECTOR

#include "stdafx.h"
#include "ResponsibilityArea.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

struct DetectMotionReport
{
	bool inLeftUpArea_;
	bool inRightUpArea_;
	bool inLeftDownArea_;
	bool inRightDownArea_;

	DetectMotionReport();
	DetectMotionReport(bool inLeftUpArea, bool inRightUpArea, bool inLeftDownArea, bool inRightDownArea);
	void clear();
};

class MotionDetector
{
	ResponsibilityArea* leftUpArea_;
	ResponsibilityArea* rightUpArea_;
	ResponsibilityArea* leftDownArea_;
	ResponsibilityArea* rightDownArea_;

public:
	MotionDetector(int areaWidth, int areaHeight, int frameWidth, int frameHeight, int shiftFromBorder);
	~MotionDetector();

	void detectMotion(cv::Mat const & motionFrame, DetectMotionReport & report);
	void drawAreas(cv::Mat & frame);
};

#endif // MOTION_DETECTOR