/*
 * Map.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "./include/Map.h"

Map::Map()
{
	// Init buffer
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



void Map::addToBuffer(Entity *e)
{
	entityList.push_back(e);
}

void Map::drawBuffer()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
					  dwBufferCoord, &rcRegion);

	for each (Entity *e in entityList)
		buffer[e->getPos().x][e->getPos().y] = e->getInfos();

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
					   dwBufferCoord, &rcRegion);
}
