#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>

#include "Map.h"
#include "NYTimer.h"
#include "MapParser.h"
#include "Player.h"

bool shallClose;
void loopGame();

using namespace std;

int main(int argc, char* args[])
{
	loopGame();

	return 0;
}

void loopGame()
{
	NYTimer timer;
	float lastTime = 0;

	if(!(MapParser::loadColorObjectTypes() && MapParser::loadMap("Map_1.tmx")))
	{
		std::cout << "FAIL" << std::endl;
	}

	PlaySound("Assets/bgm.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);

	Player player0(IVector2(10,10), 0), player1(IVector2(12, 10), 1);
	player0.spawn();
	player1.spawn();


	while(!shallClose)
	{
		Map::getMap().update(timer.getElapsedMs() - lastTime);
		lastTime = timer.getElapsedMs();

		//Map::getMap().drawBuffer();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
