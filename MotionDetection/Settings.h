#ifndef SETTINGS
#define SETTINGS

struct Settings
{
	int FRAME_WIDTH;
	int FRAME_HEIGHT;
	int AREA_WIDTH;
	int AREA_HEIGHT;
	int SHIFT_FROM_BORDER;

	int MAX_DEVIATION;
	int COVER_RATIO;

	int KERNEL_ERO_SIZE;
	int KERNEL_DIL_SIZE;

	int THRESHOLD;
	int DELAY;

	bool PRO_SETTINGS_MODE;

	Settings();
	void setDefault();
};

#endif // SETTINGS
