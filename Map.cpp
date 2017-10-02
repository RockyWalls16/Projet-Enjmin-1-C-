/*
 * Map.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "./include/Map.h"
#include <algorithm>

Map::Map()
{
	// Init buffer
	resetBuffer();
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { WIDTH,HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, WIDTH - 1, HEIGHT - 1 };
}

Map::~Map()
{

}

void Map::update(float delta)
{
}



void Map::addEntity(Entity *e)
{
	entityList.push_back(e);
}


void Map::removeEntity(Entity* e)
{
	entityList.erase(std::remove(entityList.begin(), entityList.end(), e), entityList.end());
}

void Map::drawBuffer()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
					  dwBufferCoord, &rcRegion);

	for(Entity *e : entityList)
	{
		e->drawEntity(buffer);
	}

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
					   dwBufferCoord, &rcRegion);
}

void Map::resetBuffer()
{
	buffer = new CHAR_INFO*[HEIGHT];
	for(int i = 0; i < HEIGHT; ++i)
	{
		buffer[i] = new CHAR_INFO[WIDTH];
	}
}

Map& Map::getMap()
{
	static Map instance;
	return instance;
}
