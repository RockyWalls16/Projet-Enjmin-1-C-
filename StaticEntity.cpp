/*
 * StaticEntity.cpp
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#include <StaticEntity.h>

StaticEntity::StaticEntity(IVector2 pos) : Entity(pos), hitbox(nullptr)
{

}

StaticEntity::~StaticEntity()
{
	if(hitbox)
	{
		delete(hitbox);
	}
}
