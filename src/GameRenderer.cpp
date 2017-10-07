/*
 * GameRenderer.cpp
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */

#include <string>
#include "GameRenderer.h"
#include "GameController.h"
#include "utils/Utils.h"
#include "utils/TimeManager.h"

GameRenderer::GameRenderer(): renderBuffer(nullptr), backgroundBuffer(nullptr), emptyBuffer(nullptr)
{
	consoleHandle = (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
}

void GameRenderer::initRenderBuffer(int width, int height)
{
	std::string command("mode ");
	command.append(std::to_string(width));
	command.append(",");
	command.append(std::to_string(height + 5));

	system(command.data());

	SMALL_RECT winRect = { 0, 0, (short) width, (short) (height + 5) };
	SMALL_RECT* winSize = &winRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, winSize);

	renderBuffer = new BufferRenderer(width, height);
	emptyBuffer = new BufferRenderer(width, height);
}

void GameRenderer::replaceBackgroundBuffer(BufferRenderer* newBackground)
{
	if(backgroundBuffer != newBackground)
	{
		delete(backgroundBuffer);
	}
	backgroundBuffer = newBackground;
}

GameRenderer& GameRenderer::getInstance()
{
	static GameRenderer instance;
	return instance;
}

void GameRenderer::renderGame()
{
	renderBuffer->applyBuffer(0, 0, emptyBuffer->getWidth(), emptyBuffer->getHeight(), emptyBuffer);

	Map* map = GameController::getInstance().getCurrentMap();
	if(map && map->getMapBackground())
	{
		replaceBackgroundBuffer(map->getMapBackground());
	}

	renderBuffer->applyBuffer(0, 0, backgroundBuffer->getWidth(), backgroundBuffer->getHeight(), backgroundBuffer);

	GameController::getInstance().getCurrentMap()->render(renderBuffer);

	renderBuffer->renderBuffer(0, 0, renderBuffer->getWidth(), renderBuffer->getHeight());
}
