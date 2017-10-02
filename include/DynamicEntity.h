/*
 * Entity.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef DYNAMICENTITY_H_
#define DYNAMICENTITY_H_

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
	DynamicEntity(IVector2 p, CHAR_INFO c);
	virtual ~DynamicEntity();
	virtual void update(float delta) override;

};

#endif /* DYNAMICENTITY_H_ */