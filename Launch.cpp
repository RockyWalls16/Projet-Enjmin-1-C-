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

	CHAR_INFO testInfos;
	testInfos.Attributes = 0x0E;
	testInfos.Char.AsciiChar = 'H';

	Entity test(IVector2(1,1),testInfos);
	map.addToBuffer(&test);

	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		map.update(delta);
		map.drawBuffer();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
