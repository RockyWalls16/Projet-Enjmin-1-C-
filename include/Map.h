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
	CHAR_INFO buffer[HEIGHT][WIDTH];

public:
	Map();
	virtual ~Map();

	void update(float delta);
	void addToBuffer(Entity *e);
	void drawBuffer();
};
