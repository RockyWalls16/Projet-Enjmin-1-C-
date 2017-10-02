#include <stdio.h>
#include <iostream>

#include "NYTimer.cpp"
#include "DynamicEntity.h"
#include "Map.h"

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

	printf("OK");

	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		shallClose = getchar() == VK_ESCAPE;
	}

	printf("..OK");
}
