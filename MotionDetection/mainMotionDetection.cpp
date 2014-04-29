#include "stdafx.h"
#include "MotionDetector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <sys/types.h>
#include <sys/stat.h>

static const int SHIFT_FROM_BORDER = 50;
static const int KERNEL_ERO_SIZE = 4;
static const int THRESHOLD = 30;
static const int DELAY = 30;

void getGrayFrame(cv::VideoCapture & cam, cv::Mat & frame)
{
	cam >> frame;
	cv::cvtColor(frame, frame, CV_RGB2GRAY);
}

void computeMotion(cv::Mat & motion, 
	cv::Mat const & prev_frame, 
	cv::Mat const & current_frame, 
	cv::Mat const & next_frame, 
	cv::Mat const & kernel_ero)
{
	cv::Mat d1, d2;
	cv::absdiff(prev_frame, current_frame, d1);
	cv::absdiff(current_frame, next_frame, d2);
	cv::bitwise_and(d1, d2, motion);
	cv::threshold(motion, motion, THRESHOLD, 255, CV_THRESH_BINARY);
	
	cv::erode(motion, motion, kernel_ero);
	cv::dilate(motion, motion, kernel_ero);
	
}

void printReport(DetectMotionReport const & report)
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

int main()
{
	cv::VideoCapture cam;
	cam.set(CV_CAP_PROP_FRAME_WIDTH, 240);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	cam.open(0);

	cv::Mat prev_frame, current_frame, next_frame, result;
	getGrayFrame(cam, prev_frame);
	getGrayFrame(cam, current_frame);
	getGrayFrame(cam, next_frame);
	result = next_frame;

	int frameWidth = current_frame.cols;
	int frameHeight = current_frame.rows;

	MotionDetector motionDetector(frameWidth / 6, frameHeight / 6, frameWidth, frameHeight, SHIFT_FROM_BORDER);
	DetectMotionReport report;

	cv::Mat motionFrame;
	cv::Mat kernel_ero = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(KERNEL_ERO_SIZE, KERNEL_ERO_SIZE));
	
	cv::namedWindow("mainWindow");
	cv::namedWindow("motionWindow");
	while (true)
	{
		prev_frame = current_frame;
		current_frame = next_frame;
		cam >> next_frame;
		result = next_frame;
		cv::cvtColor(next_frame, next_frame, CV_RGB2GRAY);

		//motion detection
		computeMotion(motionFrame, prev_frame, current_frame, next_frame, kernel_ero);
		motionDetector.detectMotion(motionFrame, report);
		//end motion detection
		
		//print result
		printReport(report);
		report.clear();

		//Show frames
		motionDetector.drawAreas(result);
		motionDetector.drawAreas(motionFrame);
		cv::imshow("mainWindow", result);
		cv::imshow("motionWindow", motionFrame);

		if (cv::waitKey(DELAY) >= 0) break;
	}
}