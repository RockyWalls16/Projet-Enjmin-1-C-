/*
 * StaticEntity.cpp
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#include "entities/EntityStatic.h"

EntityStatic::EntityStatic(IVector2 pos) :
		Entity(pos), hitbox(nullptr)
{

}

EntityStatic::~EntityStatic()
{
	if (hitbox)
	{
		delete (hitbox);
	}
}
