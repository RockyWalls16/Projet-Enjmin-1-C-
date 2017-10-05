/*
 * StaticEntity.cpp
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#include <StaticEntity.h>

StaticEntity::StaticEntity(IVector2 pos) : Entity(pos)
{

}

StaticEntity::~StaticEntity()
{
	delete(hitbox);
}
