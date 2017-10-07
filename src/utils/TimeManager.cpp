#include <windows.h>
#include <iostream>
#include <sys/timeb.h>
#include "utils/TimeManager.h"
#include "utils/Utils.h";

unsigned int TimeManager::fps = 0;
unsigned int TimeManager::lastFps = 0;
struct timeb TimeManager::lastTime;
double TimeManager::secondProgress = 0;
double TimeManager::tickInterpolation = 0;
double TimeManager::delta = 0;
double TimeManager::tickTime = 0;
struct timeb TimeManager::ts_start;

void TimeManager::initTimer()
{
	TimeManager::lastTime = TimeManager::getTimeMillis();
}

void TimeManager::updateTimer()
{
	fps++;

	struct timeb time = getTimeMillis();

	delta = ((time.time * 1000 + time.millitm) - (lastTime.time * 1000 + lastTime.millitm)) / MILLIS_FACTOR;

	secondProgress += delta;
	tickTime += delta;

	tickInterpolation = tickTime / TICK_DELAY;

	// FPS calculation
	if (secondProgress >= 1.0)
	{
		setLogLine(4);
		std::cout << "FPS:" << TimeManager::getFps() << "  ";

		lastFps = fps;
		secondProgress = 0.0;
		fps = 0;
	}

	lastTime = time;
}

bool TimeManager::shallTick()
{
	if (tickTime >= TICK_DELAY)
	{
		tickTime -= TICK_DELAY;
		tickInterpolation = tickTime / TICK_DELAY;

		return true;
	}

	return false;
}

struct timeb TimeManager::getTimeMillis()
{
	ftime(&ts_start);

	return ts_start;
}

double TimeManager::getTickInterpolation()
{
	return tickInterpolation;
}

double TimeManager::getDelta()
{
	return delta;
}

float TimeManager::getFDelta()
{
	return (float) delta;
}
