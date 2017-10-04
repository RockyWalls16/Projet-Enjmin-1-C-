#include <stdio.h>
#include <string>
#include <iostream>

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

	if(!(MapParser::loadColorObjectTypes() && MapParser::loadMap("Map_1.tmx")))
	{
		std::cout << "FAIL" << std::endl;
	}

	Player test(IVector2(2,5));
	test.spawn();


	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		Map::getMap().update(delta);
		Map::getMap().drawBuffer();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
