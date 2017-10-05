/*
 * Entity.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_

#pragma once
#include "StaticEntity.h"
#include "AABB.h"
#include "Vector.h"

class DynamicEntity : public StaticEntity
{
protected:
	float gravity;
	Vector2 velocity;
	bool onGround;

public:
	DynamicEntity(IVector2 p);

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

	virtual ~DynamicEntity();
	virtual void tick() override;
};

#endif /* DYNAMICENTITY_H_ */
