/*
 * AABB.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef AABB_H_
#define AABB_H_

class AABB
{
private:
	int x;
	int y;
	int x2;
	int y2;
	bool blockCollision;

public:
	AABB(int x, int y, int x2, int y2, bool blockCollision = false);

	// Update bounding box position
	void updatePos(int x, int y);

	// Update bounding box position with X axis centered
	void updatePosXCentered(int x, int y);

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

	int getX() const
	{
		return x;
	}

	int getX2() const
	{
		return x2;
	}

	int getY() const
	{
		return y;
	}

	int getY2() const
	{
		return y2;
	}
};

#endif /* AABB_H_ */
