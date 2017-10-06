#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>

#include "Map.h"
#include "MapParser.h"
#include "Player.h"
#include "TimeManager.h"

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
	if(!(MapParser::loadColorObjectTypes() && MapParser::loadMap("Map_3.tmx")))
	{
		std::cout << "FAIL" << std::endl;
	}

	//PlaySound("Assets/bgm.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

	Player player0(IVector2(10,10), 0);//player1(IVector2(12, 10), 1);
	player0.spawn();
	//player1.spawn();


	while(!shallClose)
	{
		TimeManager::updateTimer();

		while(TimeManager::shallTick())
		{
			Map::getMap().tick();
		}

		Map::getMap().render();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
