#ifndef SETTINGS
#define SETTINGS

#include <QObject>

class Settings : public QObject
{

    Q_OBJECT

public:

	int FRAME_WIDTH;
	int FRAME_HEIGHT;
	int AREA_WIDTH;
	int AREA_HEIGHT;
	int SHIFT_FROM_BORDER;

	int MAX_DEVIATION;
    int COVER_RATIO;

	int KERNEL_ERO_SIZE;
	int KERNEL_DIL_SIZE;
	bool ERODE;
	bool DILATE;

	int THRESHOLD;
	int DELAY;

	bool PRO_SETTINGS_MODE;

	Settings();
	void setDefault();

public slots:

   void changeFrameWidth(int);
   void changeFrameHeigth(int);
   void changeAreaWidth(int);
   void changeAreaHeight(int);
   void changeShiftFromBorder(int);

   void changeMaxDeviation( int );
   void changeCoverRatio( int );

   void changeKernelEroSize(int);
   void changeKernelDilSize(int);

   void changeErode(bool);
   void changeDilate(bool);

   void changeThreshold(int);
   void changeDelay(int);

   void changeProSettigsMode(bool);


};

#endif // SETTINGS
