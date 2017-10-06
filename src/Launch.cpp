#include <map/Map.h>
#include <map/MapParser.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>

#include "utils/TimeManager.h"

bool shallClose;
void loopGame();

using namespace std;

int main(int argc, char* args[])
{
	TimeManager::initTimer();
	loopGame();

	return 0;
}

void loopGame()
{
	if (!(MapParser::loadColorObjectTypes() && MapParser::loadMap("Map_3.tmx")))
	{
		std::cout << "FAIL" << std::endl;
	}

	//PlaySound("Assets/bgm.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

	while (!shallClose)
	{
		TimeManager::updateTimer();

		while (TimeManager::shallTick())
		{
			Map::getMap().tick();
		}

		Map::getMap().render();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
