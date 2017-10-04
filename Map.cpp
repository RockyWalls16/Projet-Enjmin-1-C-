/*
 * Map.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "Map.h"
#include <algorithm>
#include <iostream>
#include <string>

Map::~Map()
{

}

void Map::update(float delta)
{
	for (Entity *e : entityList)
	{
		e->update(delta);
	}

	if (entityToSpawn != nullptr)
		addEntity(entityToSpawn);

	if (entityToRemove != nullptr)
		entityList.erase(std::remove(entityList.begin(), entityList.end(), entityToRemove), entityList.end());
}

void Map::addEntity(Entity *e)
{
	entityList.push_back(e);
}

void Map::prepareSpawnEntity(Entity * e)
{
	entityToSpawn = e;
}

void Map::removeEntity(Entity* e)
{
	entityToRemove = e;
}

void Map::drawBuffer()
{
	resetBuffer(mapWidth, mapHeight);
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
	std::string command("mode ");
	command.append(std::to_string(width));
	command.append(",");
	command.append(std::to_string(height));

	system(command.data());

	SMALL_RECT WinRect = { 0, 0, (short) width, (short) height };
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);

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
