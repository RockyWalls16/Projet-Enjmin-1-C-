#include <stdio.h>
#include <iostream>

#include "Map.h"
#include "NYTimer.h"
#include "MapParser.h"

bool shallClose;
void loopGame();

int main(int argc, char* args[])
{
	loopGame();

	return 0;
}

void loopGame()
{
	NYTimer timer;

	if(!MapParser::loadMap("Map_1.tmx"))
	{
		std::cout << "Failed to load map" << std::endl;
	}

	Entity test(IVector2(1,1));
	test.spawn();


	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		Map::getMap().update(delta);
		Map::getMap().drawBuffer();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
