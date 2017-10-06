/*
 * Entity.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_

#pragma once
#include "entities/EntityStatic.h"
#include "math/AABB.h"
#include "math/Vector.h"

class EntityDynamic: public EntityStatic
{
protected:
	float gravity;
	Vector2 velocity;
	bool onGround;

	virtual void onCollision(Entity* other)
	{
	}
	;

public:
	EntityDynamic(IVector2 p);

	void addVelocity(Vector2 vel)
	{
		velocity = velocity + vel;
	}

	void setVelocity(Vector2 vel)
	{
		velocity = vel;
	}

	Vector2 getVelocity()
	{
		return velocity;
	}

	virtual void tick() override;
};

#endif /* DYNAMICENTITY_H_ */
