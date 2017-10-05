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
	void clipXY(int& motionX, int& motionY, AABB& other);
};

#endif /* AABB_H_ */
