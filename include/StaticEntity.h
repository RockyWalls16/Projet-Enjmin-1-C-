/*
 * StaticEntity.h
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#ifndef INCLUDE_STATICENTITY_H_
#define INCLUDE_STATICENTITY_H_

#include "Entity.h"
#include "AABB.h"

class StaticEntity : public Entity
{
private:
	AABB* hitbox;

public:
	StaticEntity(IVector2 pos);
	virtual ~StaticEntity();
};

#endif /* INCLUDE_STATICENTITY_H_ */
