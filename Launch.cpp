#include <stdio.h>
#include <string>
#include <iostream>

#include "./include/Map.h"
#include "./include/NYTimer.h"

bool shallClose;
void loopGame();

using namespace std;

int main(int argc, char* args[])
{
	string command("mode ");
	command.append(to_string(WIDTH));
	command.append(",");
	command.append(to_string(HEIGHT));

	system(command.data());

	SMALL_RECT WinRect = { 0, 0, WIDTH, HEIGHT };
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);

	loopGame();

	return 0;
}

void loopGame()
{
	NYTimer timer;

	Player player0(IVector2(10,10), 0), player1(IVector2(12, 10), 1);
	player0.spawn();
	player1.spawn();

	while(!shallClose)
	{
		float delta = timer.getElapsedMs();

		Map::getMap().update(delta);
		Map::getMap().drawBuffer();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}
