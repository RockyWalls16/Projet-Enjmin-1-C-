/*
 * Map.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "./include/Map.h"
#include <algorithm>
#include <iostream>

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
	memcpy(buffer, mapBackground, mapWidth * mapHeight * sizeof(CHAR_INFO));

	for(Entity *e : entityList)
	{
		e->drawEntity(buffer);
	}

	WriteConsoleOutput(hOutput, buffer, dwBufferSize,
					   dwBufferCoord, &rcRegion);
}

void Map::resetBuffer(int bufferWidth, int bufferHeight)
{
	// Clear memory
	if(buffer)
	{
		delete(buffer);
	}

	buffer = new CHAR_INFO[bufferWidth * bufferHeight];

	hOutput = (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { (short) bufferWidth , (short) bufferHeight };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, (short) (bufferWidth - 1), (short) (bufferHeight - 1) };
}


void Map::initMapBackground(int width, int height)
{
	// Clear memory
	if(mapBackground)
	{
		delete(mapBackground);
	}

	mapBackground = new CHAR_INFO[width * height];
	resetBuffer(width, height);
}

int Map::getBufferFlatIndex(int x, int y)
{
	return y * mapWidth + x;
}

int Map::getBufferFlatIndex(IVector2 position)
{
	return getBufferFlatIndex(position.x, position.y);
}

void Map::setMapSize(int width, int height)
{
	mapWidth = width;
	mapHeight = height;
}

Map& Map::getMap()
{
	static Map instance;
	return instance;
}
