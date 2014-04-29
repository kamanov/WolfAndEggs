#include "stdafx.h"
#include "MotionLooper.h"
#include "channel.h"


static void getGrayFrame(cv::VideoCapture & cam, cv::Mat & frame);
static void printReport(DetectMotionReport const & report);

MotionLooper::MotionLooper() 
: owner_(NULL), motionDetector_(new MotionDetector()), report_(new DetectMotionReport()), settings_(NULL), isStopRequested(false), isPauseRequested(false)
{}

MotionLooper::MotionLooper(Settings* settings)
: owner_(NULL), motionDetector_(new MotionDetector()), report_(new DetectMotionReport()), settings_(settings), isStopRequested(false), isPauseRequested(false)
{}

MotionLooper::~MotionLooper()
{
	delete report_;
}

void MotionLooper::setOwner(Channel* owner)
{
	owner_ = owner;
}

void MotionLooper::readSettings()
{
	motionDetector_->setAreasCoord(settings_->AREA_WIDTH, settings_->AREA_HEIGHT,
		settings_->FRAME_WIDTH, settings_->FRAME_HEIGHT, settings_->SHIFT_FROM_BORDER);
}

void MotionLooper::setSettings(Settings *settings)
{
    settings_ = settings;
    readSettings();
}

bool MotionLooper::motionOccurred()
{
    return report_->inLeftUpArea_
            || report_->inRightUpArea_
            || report_->inLeftDownArea_
            || report_->inRightDownArea_;
}

int MotionLooper::getNumberArea(DetectMotionReport report)
{
    if (report.inLeftUpArea_) {
        return 1;
    }

    if (report.inRightUpArea_) {
        return 2;
    }

    if (report.inLeftDownArea_) {
        return 3;
    }

    if (report.inRightDownArea_) {
        return 4;
    }

    return 0;
}

void MotionLooper::computeMotion(cv::Mat & motion,
	cv::Mat const & prev_frame,
	cv::Mat const & current_frame,
	cv::Mat const & next_frame,
	cv::Mat const & kernel_ero,
	cv::Mat const & kernel_dil)
{
	cv::Mat d1, d2;
	cv::absdiff(prev_frame, current_frame, d1);
	cv::absdiff(current_frame, next_frame, d2);
	cv::bitwise_and(d1, d2, motion);
	cv::threshold(motion, motion, settings_->THRESHOLD, 255, CV_THRESH_BINARY);

	if (settings_->ERODE) {
		cv::erode(motion, motion, kernel_ero);
	}
	if (settings_->DILATE) {
		cv::dilate(motion, motion, kernel_dil);
	}
}

void MotionLooper::start()
{
	cv::VideoCapture cam;
    cam.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	cam.open(0);

	cv::Mat prev_frame, current_frame, next_frame, result;
	getGrayFrame(cam, prev_frame);
	getGrayFrame(cam, current_frame);
	getGrayFrame(cam, next_frame);
	result = next_frame;

	settings_->FRAME_WIDTH = current_frame.cols;
	settings_->FRAME_HEIGHT = current_frame.rows;
	settings_->AREA_WIDTH = settings_->FRAME_WIDTH / 6;
	settings_->AREA_HEIGHT = settings_->FRAME_HEIGHT / 6;

	readSettings();

	cv::namedWindow("mainWindow");
	cv::namedWindow("motionWindow");

	while (true)
	{
		readSettings();

        cv::Mat motionFrame;
        cv::Mat kernel_ero = cv::getStructuringElement(cv::MORPH_RECT,
            cv::Size(settings_->KERNEL_ERO_SIZE, settings_->KERNEL_ERO_SIZE));
        cv::Mat kernel_dil = cv::getStructuringElement(cv::MORPH_RECT,
            cv::Size(settings_->KERNEL_DIL_SIZE, settings_->KERNEL_DIL_SIZE));

		prev_frame = current_frame;
		current_frame = next_frame;
		cam >> next_frame;
		result = next_frame;

        if(next_frame.channels() == 3)
            cv::cvtColor(next_frame, next_frame, CV_RGB2GRAY);

		//motion detection
		computeMotion(motionFrame, prev_frame, current_frame, next_frame, kernel_ero, kernel_dil);
		motionDetector_->detectMotion(motionFrame, report_, settings_->MAX_DEVIATION, settings_->COVER_RATIO);
		//end motion detection

        if (motionOccurred()) {
            owner_->sendReport(getNumberArea(*report_));
        }

		//printReport(*report_);

		//Show frames
		if (settings_->PRO_SETTINGS_MODE) {
			motionDetector_->drawAreas(result, report_);
			motionDetector_->drawAreas(motionFrame, report_);
			cv::Mat mirResult;
			cv::Mat mirMotion;
			cv::flip(result, mirResult, 1);
			cv::flip(motionFrame, mirMotion, 1);
			cv::imshow("mainWindow", mirResult);
			cv::imshow("motionWindow", mirMotion);
		}

		if (isStopRequested) {
			break;
		}

		if (cv::waitKey(settings_->DELAY) >= 0) break;
	}
}

/*== helpers ==*/
static void getGrayFrame(cv::VideoCapture & cam, cv::Mat & frame)
{
	cam >> frame;
    if(frame.channels()==3)
        cv::cvtColor(frame, frame, CV_RGB2GRAY);
}

static void printReport(DetectMotionReport const & report)
{
	if (report.inLeftUpArea_) {
		std::cout << "in Left Up Area" << std::endl;
	}
	if (report.inRightUpArea_) {
		std::cout << "in Right Up Area" << std::endl;
	}
	if (report.inLeftDownArea_) {
		std::cout << "in Left Down Area" << std::endl;
	}
	if (report.inRightDownArea_) {
		std::cout << "in Right Down Area" << std::endl;
	}
}
