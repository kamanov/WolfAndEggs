#ifndef MOTION_LOOPER
#define MOTION_LOOPER

#include "stdafx.h"
#include "MotionDetector.h"
#include "DetectMotionReport.h"
#include "Settings.h"


class Channel;

class MotionLooper
{
	Channel* owner_;
	MotionDetector* motionDetector_;
	DetectMotionReport* report_;
	Settings* settings_;

	bool isStopRequested;
	bool isPauseRequested;
public:
	MotionLooper();
	MotionLooper(Settings* settings);
	MotionLooper(Settings* settings, DetectMotionReport* report);
	~MotionLooper();

	void setSettings(Settings* settings);
	void readSettings();
	void setOwner(Channel * owner);
	void start();
	void stop();
	void pauseLoop();
	void continueLoop();

	void computeMotion(cv::Mat & motion,
		cv::Mat const & prev_frame,
		cv::Mat const & current_frame,
		cv::Mat const & next_frame,
		cv::Mat const & kernel_ero,
		cv::Mat const & kernel_dil);
};

#endif // MOTION_LOOPER