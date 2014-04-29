#ifndef DETECT_MOTION_REPORT
#define DETECT_MOTION_REPORT

class DetectMotionReport
{
public:
	bool inLeftUpArea_;
	bool inRightUpArea_;
	bool inLeftDownArea_;
	bool inRightDownArea_;

	DetectMotionReport();
	DetectMotionReport(bool inLeftUpArea, bool inRightUpArea, bool inLeftDownArea, bool inRightDownArea);
	void clear();
};


#endif // DETECT_MOTION_REPORT
