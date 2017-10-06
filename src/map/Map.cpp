/*
 * Map.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include <map/Map.h>
#include "utils/Utils.h"
#include <algorithm>
#include <iostream>
#include <string>

Map::~Map()
{

}

void Map::tick()
{
	for (Entity *e : entityList)
	{
		e->tick();
	}

	//Spawn queued entities
	for (Entity* spawned : entityToSpawn)
	{
		addEntity(spawned);
	}
	entityToSpawn.clear();

	//Despawn queued entities
	for (Entity* despawned : entityToRemove)
	{
		entityList.erase(
				std::remove(entityList.begin(), entityList.end(), despawned),
				entityList.end());
		delete (despawned);
	}
	entityToRemove.clear();

}

void Map::addEntity(Entity *e)
{
	entityList.push_back(e);
}

void Map::prepareSpawnEntity(Entity * e)
{
	entityToSpawn.push_back(e);
}

void Map::removeEntity(Entity* e)
{
	entityToRemove.push_back(e);
}

void Map::render()
{
	resetBuffer(mapWidth, mapHeight);
	memcpy(buffer, mapBackground, mapWidth * mapHeight * sizeof(CHAR_INFO));

	for (Entity *e : entityList)
	{
		e->render(buffer);
	}

	WriteConsoleOutput(hOutput, buffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

void Map::resetBuffer(int bufferWidth, int bufferHeight)
{
	// Clear memory
	if (buffer)
	{
		delete (buffer);
	}

	buffer = new CHAR_INFO[bufferWidth * bufferHeight];

	hOutput = (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize =
	{	(short) bufferWidth , (short) bufferHeight};
	dwBufferCoord =
	{	0, 0};
	rcRegion =
	{	0, 0, (short) (bufferWidth - 1), (short) (bufferHeight - 1)};

	/*CONSOLE_FONT_INFOEX cfi;
	 cfi.cbSize = sizeof(cfi);
	 cfi.nFont = 0;
	 cfi.dwFontSize.X = 8;
	 cfi.dwFontSize.Y = 8;
	 cfi.FontFamily = FF_DONTCARE;
	 cfi.FontWeight = FW_NORMAL;
	 SetCurrentConsoleFontEx(hOutput, FALSE, &cfi);*/
}

void Map::initMapBackground(int width, int height)
{
	std::string command("mode ");
	command.append(std::to_string(width));
	command.append(",");
	command.append(std::to_string(height + 5));

	system(command.data());

	SMALL_RECT WinRect =
	{ 0, 0, (short) width, (short) (height + 5) };
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);

	// Clear memory
	if (mapBackground)
	{
		delete (mapBackground);
	}

	mapBackground = new CHAR_INFO[width * height];
	resetBuffer(width, height);
}

int Map::getBufferFlatIndex(int x, int y)
{
	int yOffset = 0;

	if (x >= mapWidth)
		yOffset--;
	else if (x < 0)
		yOffset++;

	int index = (y + yOffset) * mapWidth + x;
	return index < 0 || index >= mapWidth * mapHeight ? 0 : index;
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

void Map::respawnPlayers()
{
	entityToRemove.clear();
	entityToSpawn.clear();

	// Remove every players
	std::vector<Entity*>::iterator it = entityList.begin();
	while (it != entityList.end())
	{
		EntityPlayer* player = dynamic_cast<EntityPlayer*>(*it);
		if (player)
		{
			player->despawn();
		}
		it++;
	}

	int id;
	for (IVector2 spawnPoint : spawnPoints)
	{
		EntityPlayer* player = new EntityPlayer(spawnPoint, id++);
		player->spawn();
	}
}

Map& Map::getMap()
{
	static Map instance;
	return instance;
}
