/*
 * Entity.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_

#pragma once
#include "Entity.h"
#include "AABB.h"
#include "Vector.h"

class DynamicEntity : public Entity
{
private:
	AABB hitbox;
	float gravity;
	Vector2 velocity;

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
	virtual void update(float delta) override;
};

#endif /* DYNAMICENTITY_H_ */
