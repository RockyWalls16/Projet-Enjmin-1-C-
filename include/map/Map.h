/*
 * Map.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#pragma once
#include <vector>
#include "entities/EntityPlayer.h"
#include "math/Vector.h"
#include "utils/Colors.h"
#include "BufferRenderer.h"

class Map
{
private:
	int mapWidth;
	int mapHeight;
	BufferRenderer* mapBackground;

	std::vector<Entity*> entityList;
	std::vector<Entity*> entityToSpawn;
	std::vector<Entity*> entityToRemove;
	std::vector<IVector2> spawnPoints;

public:
	Map(int width, int height);
	virtual ~Map();

	// Update map and all entities
	void tick();

	// Add entity to the map
	void addEntity(Entity *e);
	void prepareSpawnEntity(Entity *e);

	// Remove entity from the map
	void removeEntity(Entity *e);
	void render(BufferRenderer* bufferRenderer);

	void setMapSize(int width, int height);
	void spawnPlayers();

	int getMapHeight() const
	{
		return mapHeight;
	}

	int getMapWidth() const
	{
		return mapWidth;
	}

	const std::vector<Entity*>& getEntityList() const
	{
		return entityList;
	}

	std::vector<IVector2>& getSpawnPoints()
	{
		return spawnPoints;
	}

	BufferRenderer* getMapBackground() const
	{
		return mapBackground;
	}
};
