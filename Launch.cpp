#include <stdio.h>
#include <iostream>

#include "./include/Map.h"
#include "./include/NYTimer.h"

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

	Entity test(IVector2(1,1));
	test.spawn();


	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		map.update(delta);
		map.drawBuffer();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
