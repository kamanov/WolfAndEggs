#ifndef MOTION_LOOPER
#define MOTION_LOOPER

#include "stdafx.h"
#include "MotionDetector.h"
#include "DetectMotionReport.h"
#include "Settings.h"

void getGrayFrame(cv::VideoCapture & cam, cv::Mat & frame);

void computeMotion(cv::Mat & motion,
	cv::Mat const & prev_frame,
	cv::Mat const & current_frame,
	cv::Mat const & next_frame,
	cv::Mat const & kernel_ero,
	cv::Mat const & kernel_dil);

void printReport(DetectMotionReport const & report);

class Channel
{
public:
	void sendReport(DetectMotionReport detectMotionReport){}
};

class MotionLooper
{
	Channel* owner_;
	MotionDetector motionDetector_;
	DetectMotionReport report_;
	Settings settings;
public:
	MotionLooper();
	~MotionLooper();

	void setSettings();
	void setOwner(Channel * owner);
	void start();
};

#endif // MOTION_LOOPER