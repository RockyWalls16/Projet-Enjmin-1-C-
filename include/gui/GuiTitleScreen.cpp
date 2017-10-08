/*
 * GuiTitleScreen.cpp
 *
 *  Created on: 8 oct. 2017
 *      Author: valen
 */

#include <BufferRenderer.h>
#include <gui/GuiTitleScreen.h>
#include <GameController.h>
#include <map/MapParser.h>
#include <math/Easing.h>
#include <utils/Colors.h>
#include <utils/TimeManager.h>
#include <windows.h>
#include "GameController.h"

GuiTitleScreen::GuiTitleScreen() : timer(0.0F), playerChoice(0)
{
	titleBuffer = MapParser::loadMapData("buffers/title_screen.tmx", nullptr, false);
}

GuiTitleScreen::~GuiTitleScreen()
{
	delete(titleBuffer);
}

void GuiTitleScreen::renderGUI(BufferRenderer* renderBuffer)
{
	timer += TimeManager::getDelta() * 0.75F;
	if(timer > 1.0F)
	{
		timer = 1.0F;
	}
	float t = Easing::Elastic::Out(timer);

	int sizeX = t * titleBuffer->getWidth();
	int sizeY = t * titleBuffer->getHeight();

	if(GetAsyncKeyState(VK_DOWN))
	{
		playerChoice = 1;
	}
	else if(GetAsyncKeyState(VK_UP))
	{
		playerChoice = 0;
	}
	else if(GetAsyncKeyState(VK_RETURN))
	{
		switch(playerChoice)
		{
			case 0:
			{
				close();
				GameController::getInstance().setMap("Map_3.tmx");

				break;
			}
			case 1:
			{
				GameController::getInstance().setShallClose(true);
				break;
			}
		}
	}

	CHAR_INFO empty;
	empty.Char.AsciiChar = (char) 176;
	empty.Attributes = DARK_GRAY | BG_BLACK;

	CHAR_INFO cursor;
	cursor.Char.AsciiChar = (char) 16;
	cursor.Attributes = WHITE | BG_BLACK;

	renderBuffer->applyBuffer(titleBuffer->getWidth() / 2 - sizeX / 2, titleBuffer->getHeight() / 2 - sizeY / 2, sizeX, sizeY, titleBuffer);

	if(timer >= 1.0F)
	{
		renderBuffer->setCharAt(29, playerChoice == 0 ? 23 : 20, empty);
		renderBuffer->setCharAt(29, playerChoice == 1 ? 23 : 20, cursor);
	}
}
