/*
 * Entity.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "DynamicEntity.h"
#include <iostream>

DynamicEntity::DynamicEntity(IVector2 p)
	: StaticEntity(p)
	, gravity(0)
	, velocity({0.0, 0.0})
{
	
}

DynamicEntity::~DynamicEntity()
{

}

void DynamicEntity::tick()
{
	velocity.y += gravity;
	Vector2 newPos = m_realPosition + velocity;
	m_realPosition = newPos;

	velocity = velocity * 0.02;

	Entity::tick();
}
