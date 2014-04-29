#ifndef SETTINGS
#define SETTINGS

struct Settings
{
	int AREA_WIDTH;
	int AREA_HEIGHT;
	int SHIFT_FROM_BORDER;

	int MAX_DEVIATION;
	int COVER_RATIO;

	int KERNEL_ERO_SIZE;
	int KERNEL_DIL_SIZE;

	int THRESHOLD;
	int DELAY;
};

#endif // SETTINGS
