/*
 * Map.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include <algorithm>
#include <iostream>
#include <string>
#include "map/Map.h"
#include "utils/Utils.h"

Map::Map(int width, int height, BufferRenderer* mapBackground) : mapBackground(mapBackground)
{
	setMapSize(width, height);
}

Map::~Map()
{
	delete(mapBackground);
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
		entityList.erase(std::remove(entityList.begin(), entityList.end(), despawned), entityList.end());
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

void Map::render(BufferRenderer* bufferRenderer)
{
	for (Entity *e : entityList)
	{
		e->render(bufferRenderer);
	}
}

void Map::setMapSize(int width, int height)
{
	mapWidth = width;
	mapHeight = height;
}

void Map::spawnPlayers()
{
	// Remove every players
	int id;
	for (IVector2 spawnPoint : spawnPoints)
	{
		EntityPlayer* player = new EntityPlayer(spawnPoint, id++);
		player->spawn();
	}
}
