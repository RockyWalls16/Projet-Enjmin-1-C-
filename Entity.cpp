/*
 * GameObject.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "Entity.h"

Entity::Entity() : realPosition(0.0F, 0.0F)
{

}

Entity::~Entity()
{

}

void Entity::update(float delta)
{
	position = realPosition.asIVector2();
}
