/*
 * AABB.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "math/AABB.h"
#include "utils/Utils.h"
#include "utils/TimeManager.h"
#include <iostream>

AABB::AABB(float x, float y, float x2, float y2, bool blockCollision, bool oneSided) :
		x(x), y(y), x2(x2), y2(y2), blockCollision(blockCollision), oneSided(oneSided)
{
}

bool AABB::intersect(AABB& other)
{
	return (x < other.x2 && x2 > other.x) && (y < other.y2 && y2 > other.y);
}

void AABB::updatePos(float nX, float nY)
{
	float sX = x2 - x;
	float sY = y2 - y;

	x = nX;
	y = nY;
	x2 = nX + sX;
	y2 = nY + sY;
}

void AABB::updatePosXCentered(float nX, float nY)
{
	float sX = (x2 - x) / 2;
	float sY = y2 - y;

	x = nX - sX;
	y = nY;
	x2 = nX + sX;
	y2 = nY + sY;
}

void AABB::clipX(float* motionX, AABB& other)
{
	// Clip X

	// Check Y is in bound
	if (!(other.y2 <= y || other.y >= y2) && !oneSided)
	{
		if (*motionX >= 0 && other.x2 <= x)
		{
			float distance = x - other.x2;
			*motionX = distance < *motionX ? distance : *motionX;
		}
		else if (*motionX <= 0 && other.x >= x2)
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
	if (!(other.x2 <= x || other.x >= x2))
	{
		if (*motionY >= 0 && other.y2 <= y)
		{
			float distance = y - other.y2;
			*motionY = distance < *motionY ? distance : *motionY;

			return *motionY == 0;
		}
		else if (*motionY <= 0 && other.y >= y2 && !oneSided)
		{
			float distance = y2 - other.y;
			*motionY = distance > *motionY ? distance : *motionY;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream &strm, AABB const &a)
{
	return strm << "[" << a.getX() << "," << a.getY() << "->" << a.getX2() << "," << a.getY2() << "]";
}
