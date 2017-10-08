/*
 * GameController.cpp
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */

#include <gui/GUISplash.h>
#include <GameController.h>
#include <GameRenderer.h>
#include <map/MapParser.h>
#include <minwindef.h>
#include <mmsystem.h>
#include <utils/TimeManager.h>
#include <winuser.h>

GameController::GameController(): shallClose(false), currentMap(nullptr)
{

}

void GameController::initGame()
{
	if(!MapParser::loadColorObjectTypes())
	{
		std::cout << "Check the following files are in the same directory as this executable:" << std::endl
		<< " - tinyxml2.dll" << std::endl
		<< " - 'Maps' Folder" << std::endl
		<< "    - objecttypes.xml" << std::endl
		<< "    - some maps (.tmx)" << std::endl
		<< "    - 'buffers' folder with all file in it" << std::endl
		<< " - 'Assets' folders" << std::endl;

		return;
	}


	// Init game renderer
	GameRenderer::getInstance().initRenderBuffer(80, 36);
	TimeManager::initTimer();

	GUISplash* splashScreen = new GUISplash();
	splashScreen->open();
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

		if(GetAsyncKeyState(VK_ESCAPE))
		{
			shallClose = true;
		}
	}
}

GameController& GameController::getInstance()
{
	static GameController instance;
	return instance;
}

void GameController::setMap(std::string mapName)
{
	currentMap = MapParser::loadMap(mapName);
	currentMap->spawnPlayers();
}
