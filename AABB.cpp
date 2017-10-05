/*
 * AABB.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "AABB.h"

AABB::AABB(int x, int y, int x2, int y2, bool blockCollision) : x(x), y(y), x2(x2), y2(y2), blockCollision(blockCollision)
{
}

bool AABB::intersect(AABB& other)
{
	return (x < other.x2 && x2 > other.x) && (y < other.y2 && y2 > other.y);
}

void AABB::updatePos(int nX, int nY)
{
	int sX = x2 - x;
	int sY = y2 - y;

	x = nX;
	y = nY;
	x2 = nX + sX;
	y2 = nY + sY;
}

void AABB::updatePosXCentered(int nX, int nY)
{
	int sX = (x2 - x) / 2;
	int sY = y2 - y;

	x = nX - sX;
	y = nY;
	x2 = nX + sX;
	y2 = nY + sY;
}

void AABB::clipXY(int& motionX, int& motionY, AABB& other)
{
	// Clip X

	// Check Y is in bound
	if (other.y < y2 || other.y2 > y)
	{
		motionX = motionX > 0 ? x - other.x2 : x2 - other.x;
	}

	// Clip Y

	// Check X is in bound
	if(other.x >= x2 || other.x2 <= x)
	{
		motionY = motionY > 0 ? y - other.y2 : y2 - other.y;
	}
}
