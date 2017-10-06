/*
 * EntityWall.cpp
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#include "entities/EntityWall.h"

EntityWall::EntityWall(IVector2 pos, AABB* aabb) :
		EntityStatic(pos)
{
	hitbox = aabb;
}

EntityWall::~EntityWall()
{

}

