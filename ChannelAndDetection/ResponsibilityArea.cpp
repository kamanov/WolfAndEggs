#include "stdafx.h"
#include "ResponsibilityArea.h"
#include <iostream>


ResponsibilityArea::ResponsibilityArea(int xStart, int yStart, int width, int height, std::string const & title = "")
: xStart_(xStart), yStart_(yStart), width_(width), height_(height), title_(title)
{}

void ResponsibilityArea::setCoordSize(int xStart, int yStart, int width, int height)
{
	xStart_ = xStart;
	yStart_ = yStart;
	width_ = width;
	height_ = height;
}

bool ResponsibilityArea::detectMotion(cv::Mat const & motionFrame, int const MAX_DEVIATION, int const COVER_RATIO)
{
	cv::Mat submotionFrame(motionFrame, cv::Rect(xStart_, yStart_, width_, height_));
	cv::Scalar mean, stddev;
	cv::meanStdDev(submotionFrame, mean, stddev);

	if (stddev[0] > MAX_DEVIATION) {
		return false;
	}

	int number_of_changes = 0;

	//loop over part of image and detect changes
	for (int j = 0; j < height_; ++j) {
		for (int i = 0; i < width_; ++i) {
			if (static_cast<int>(submotionFrame.at<uchar>(j, i)) == 255) {
				++number_of_changes;
			}
		}
	}

	if (number_of_changes > (int)(COVER_RATIO * getArea())) {
		//std::cout << number_of_changes << std::endl;
		return true;
	}

	return false;

}

int ResponsibilityArea::getArea()
{
	return width_ * height_;
}

void ResponsibilityArea::drawArea(cv::Mat & frame, bool isMotionOccurred)
{
	cv::Scalar red(0, 0, 255);
	cv::Scalar yellow(0, 255, 255);
	if (isMotionOccurred) {
		rectangle(frame, cv::Rect(xStart_, yStart_, width_, height_), red, 2);
	}
	else {
		rectangle(frame, cv::Rect(xStart_, yStart_, width_, height_), yellow, 2);
	}
}

std::string ResponsibilityArea::getTitle()
{
	return title_;
}