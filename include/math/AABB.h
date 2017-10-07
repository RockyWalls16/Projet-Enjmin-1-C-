/*
 * AABB.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef AABB_H_
#define AABB_H_

#include "iostream"

class AABB
{
private:
	float x;
	float y;
	float x2;
	float y2;
	bool blockCollision;
	bool oneSided;

public:
	AABB(float x, float y, float x2, float y2, bool blockCollision = false, bool oneSided = false);

	// Update bounding box position
	void updatePos(float x, float y);

	// Update bounding box position with X axis centered
	void updatePosXCentered(float x, float y);

	// Check two bounding boxes intersects
	bool intersect(AABB& other);

	// Clip velocity to new pos
	void clipX(float* motionX, AABB& other);

	// Return if aabb is on ground
	bool clipY(float* motionY, AABB& other);

	bool isBlockCollision() const
	{
		return blockCollision;
	}

	float getX() const
	{
		return x;
	}

	float getX2() const
	{
		return x2;
	}

	float getY() const
	{
		return y;
	}

	float getY2() const
	{
		return y2;
	}

};

std::ostream& operator<<(std::ostream &strm, AABB const &a);

#endif /* AABB_H_ */
