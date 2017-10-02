/*
 * Map.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */
#define WIDTH 10
#define HEIGHT 10

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
	CHAR_INFO** buffer;

public:
	Map();
	virtual ~Map();

	// Reset buffer
	void resetBuffer();

	// Update map and all entities
	void update(float delta);

	// Add entity to the map
	void addEntity(Entity *e);

	// Remove entity from the map
	void removeEntity(Entity *e);
	void drawBuffer();

	// Singleton
	static Map& getMap();
};
