/*
 * Map.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#pragma once
#include <vector>
#include "Player.h"

class Map
{
private:
	std::vector<Entity*> entityList;

	HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
	CHAR_INFO* buffer;
	CHAR_INFO* mapBackground;
	int mapWidth;
	int mapHeight;

	Entity* entityToSpawn;
	Entity* entityToRemove;

public:
	virtual ~Map();

	// Reset buffer
	void resetBuffer(int bufferWidth, int bufferHeight);

	// Update map and all entities
	void tick();

	// Add entity to the map
	void addEntity(Entity *e);
	void prepareSpawnEntity(Entity *e);

	// Remove entity from the map
	void removeEntity(Entity *e);
	void render();

	// Retrieves an index for 2 coords
	int getBufferFlatIndex(int x, int y);
	int getBufferFlatIndex(IVector2 position);

	void initMapBackground(int width, int height);

	void setMapSize(int width, int height);


	// Singleton
	static Map& getMap();

	CHAR_INFO* getMapBackground() const
	{
		return mapBackground;
	}

	CHAR_INFO* getBuffer() const
	{
		return buffer;
	}

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
};
