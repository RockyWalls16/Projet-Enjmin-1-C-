/*
 * GUISplash.cpp
 *
 *  Created on: 7 oct. 2017
 *      Author: valen
 */

#include <BufferRenderer.h>
#include <gui/GuiTitleScreen.h>
#include <gui/GUISplash.h>
#include <map/MapParser.h>
#include <math/Easing.h>
#include <utils/TimeManager.h>

GUISplash::GUISplash() : animationTime(0.0)
{
	logo = MapParser::loadMapData("buffers/logo.tmx", nullptr, false);
}

GUISplash::~GUISplash()
{
	delete(logo);
}

void GUISplash::renderGUI(BufferRenderer* renderBuffer)
{
	int x = (renderBuffer->getWidth() - logo->getWidth()) / 2;
	int fY = (renderBuffer->getHeight() - logo->getHeight()) / 2;
	int y = 0;

	animationTime += TimeManager::getDelta();
	if(animationTime <= 2.5F)
	{
		float t = Easing::Bounce::Out(animationTime > 1.0F ? 1.0F : animationTime);
		y = Easing::Interpolate(fY, -logo->getHeight(), t);
	}
	else if(animationTime <= 4.75F)
	{
		float t = Easing::Back::In(animationTime - 2.5F);
		y = Easing::Interpolate(logo->getHeight(), fY, t);
	}
	else
	{
		GuiTitleScreen* titleScreen = new GuiTitleScreen();
		titleScreen->open();

		close();
	}

	renderBuffer->applyBuffer(x, y, logo->getWidth(), logo->getHeight(), logo);
}
