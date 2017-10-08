/*
 * EntityWall.h
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#ifndef INCLUDE_ENTITYWALL_H_
#define INCLUDE_ENTITYWALL_H_

#include "entities/EntityStatic.h"
#include "math/AABB.h"

class EntityWall: public EntityStatic
{
public:
	EntityWall(IVector2 pos, AABB* aabb);
	virtual ~EntityWall();
};

#endif /* INCLUDE_ENTITYWALL_H_ */
