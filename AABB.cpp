/*
 * AABB.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "AABB.h"
#include "Utils.h"
#include "TimeManager.h"
#include <iostream>

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

void AABB::clipX(float* motionX, AABB& other)
{
	// Clip X

	// Check Y is in bound
	if (!(other.y2 <= y || other.y >= y2))
	{
		if(*motionX > 0 && other.x2 <= x)
		{
			float distance = x - other.x2;
			*motionX = distance < *motionX ? distance : *motionX;
		}
		else if(*motionX < 0 && other.x >= x2)
		{
			float distance = x2 - other.x;
			*motionX = distance > *motionX ? distance : *motionX;
		}
	}
}

bool AABB::clipY(float* motionY, AABB& other)
{
	// Clip Y

	// Check X is in bound
	if(!(other.x2 <= x || other.x >= x2))
	{
		if(*motionY > 0 && other.y2 <= y)
		{
			float distance = y - other.y2;
			*motionY = distance < *motionY ? distance : *motionY;

			return *motionY == 0;
		}
		else if(*motionY < 0 && other.y >= y2)
		{
			float distance = y2 - other.y;
			*motionY = distance > *motionY ? distance : *motionY;
		}
	}
	return false;
}
