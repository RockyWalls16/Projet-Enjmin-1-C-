/*
 * GameObject.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Vector.h"

class Entity
{
protected:
	IVector2 position;
	Vector2 realPosition;

public:
	Entity();
	virtual ~Entity();
	virtual void update(float delta);
};

#endif /* ENTITY_H_ */
