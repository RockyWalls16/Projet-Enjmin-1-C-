/*
 * GUI.cpp
 *
 *  Created on: 7 oct. 2017
 *      Author: valen
 */

#include <gui/GUI.h>
#include <algorithm>
#include "GameRenderer.h"

GUI::~GUI()
{
	close();
}

void GUI::open()
{
	GameRenderer::getInstance().getOpenGUIs().push_back(this);
}

void GUI::close()
{
	GameRenderer::getInstance().getOpenGUIs().erase(std::remove(GameRenderer::getInstance().getOpenGUIs().begin(), GameRenderer::getInstance().getOpenGUIs().end(), this), GameRenderer::getInstance().getOpenGUIs().end());
}
