#include <stdio.h>
#include <iostream>

#include "DynamicEntity.h"
#include "Map.h"
#include "NYTimer.h"

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
	Map map;

	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		map.update(delta);

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
