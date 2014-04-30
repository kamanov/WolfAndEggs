#ifndef RESPONSIBILITY_AREA
#define RESPONSIBILITY_AREA

#include "stdafx.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <string>


class ResponsibilityArea
{
	int xStart_;
	int yStart_;
	int width_;
	int height_;
	std::string title_;

	int getArea();

public:
	ResponsibilityArea();
	ResponsibilityArea(int xStart, int yStart, int widht, int height, std::string const & title);
	
	void setCoordSize(int xStart, int yStart_, int width, int height);
	bool detectMotion(cv::Mat const & motionFrame, int const MAX_DEVIATION, int const COVER_RATIO);
	std::string getTitle();

	void drawArea(cv::Mat & frame, bool isMotionOccurred);
};

#endif // RESPONSIBILITY_AREA