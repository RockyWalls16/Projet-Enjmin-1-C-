/*
 * EntityWall.cpp
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#include <EntityWall.h>

EntityWall::EntityWall(IVector2 pos, AABB* aabb) : StaticEntity(pos)
{
	hitbox = aabb;
}

EntityWall::~EntityWall()
{

}

