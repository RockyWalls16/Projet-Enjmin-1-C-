#ifndef TIMEMANAGER_H_
#define TIMEMANAGER_H_

#define MILLIS_FACTOR 1000.0
#define NANO_FACTOR 1000000.0
#define TICK_PER_SECOND 25.0
#define TICK_DELAY (1 / TICK_PER_SECOND)

#include <windows.h>

class TimeManager
{
private:
	static unsigned int fps;
	static unsigned int lastFps;
	static struct timeb lastTime;
	static double secondProgress;
	static double tickInterpolation;
	static double tickTime;
	static double delta;
	static struct timeb ts_start;

public:
	static void initTimer();
	static void updateTimer();

	static bool shallTick();

	static struct tm* getTimeOfDay();
	static double getTickInterpolation();
	static double getDelta();
	static float getFDelta();
	static struct timeb getTimeMillis();

	static unsigned int getFps()
	{
		return lastFps;
	}
};

#endif /* TIMEMANAGER_H_ */
