/*
 * StaticEntity.h
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#ifndef INCLUDE_STATICENTITY_H_
#define INCLUDE_STATICENTITY_H_

#include "entities/Entity.h"
#include "math/AABB.h"

class EntityStatic: public Entity
{
protected:
	AABB* hitbox;

public:
	EntityStatic(IVector2 pos);
	virtual ~EntityStatic();

	virtual AABB* getAABB()
	{
		return hitbox;
	}
};

#endif /* INCLUDE_STATICENTITY_H_ */
