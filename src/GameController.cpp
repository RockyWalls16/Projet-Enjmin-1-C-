/*
 * GameController.cpp
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */

#include <iostream>
#include "GameController.h"
#include "GameRenderer.h"
#include "utils/TimeManager.h"
#include "map/MapParser.h"
#include "map/Map.h"

GameController::GameController(): shallClose(false), currentMap(nullptr)
{

}

void GameController::initGame()
{
	// Init game renderer
	GameRenderer::getInstance().initRenderBuffer(80, 35);
	TimeManager::initTimer();

	if(!MapParser::loadColorObjectTypes())
	{
		return;
	}

	currentMap = MapParser::loadMap("logo.tmx");
	currentMap->spawnPlayers();
}

void GameController::loopGame()
{
	PlaySound("Assets/bgm.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	while (!shallClose)
	{
		TimeManager::updateTimer();

		while (TimeManager::shallTick())
		{
			if(currentMap)
			{
				currentMap->tick();
			}
		}

		GameRenderer::getInstance().renderGame();

		shallClose = GetAsyncKeyState(VK_ESCAPE);
	}
}

GameController& GameController::getInstance()
{
	static GameController instance;
	return instance;
}
