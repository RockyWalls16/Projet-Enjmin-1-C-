#include <TimeManager.h>
#include <time.h>

unsigned int TimeManager::fps = 0;
unsigned int TimeManager::lastFps = 0;
long TimeManager::lastTime = 0;
double TimeManager::secondProgress = 0;
double TimeManager::tickInterpolation = 0;
double TimeManager::delta = 0;
double TimeManager::tickTime = 0;

void TimeManager::initTimer()
{
	TimeManager::lastTime = TimeManager::getTimeMillis();
}

void TimeManager::updateTimer()
{
	fps++;

	long time = getTimeMillis();
	delta = (time - lastTime) / MILLIS_FACTOR;
	secondProgress += delta;
	tickTime += delta;

	tickInterpolation = tickTime / TICK_DELAY;

	// FPS calculation
	if(secondProgress >= 1.0)
	{
		lastFps = fps;
		secondProgress = 0.0;
		fps = 0;
	}

	lastTime = time;
}

bool TimeManager::shallTick()
{
	if(tickTime >= TICK_DELAY)
	{
		tickTime -= TICK_DELAY;
		tickInterpolation = tickTime / TICK_DELAY;

		return true;
	}

	return false;
}

long TimeManager::getTimeMillis()
{
	struct timespec ts_start;
	clock_gettime(CLOCK_MONOTONIC, &ts_start);

	return ts_start.tv_sec * MILLIS_FACTOR + ts_start.tv_nsec / NANO_FACTOR;
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

