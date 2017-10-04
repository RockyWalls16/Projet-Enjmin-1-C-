/*
 * Entity.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "DynamicEntity.h"
#include <iostream>

DynamicEntity::DynamicEntity(IVector2 p)
	: Entity(p)
	, hitbox(0, 0, 1, 1)
	, gravity(0)
	, velocity({0.0, 0.0})
{
	
}

DynamicEntity::~DynamicEntity()
{

}

void DynamicEntity::update(float delta)
{
	velocity.y += gravity;
	Vector2 newPos = m_realPosition + velocity * delta;
	m_realPosition = newPos;

	std::cout << (float) delta << std::endl;
	velocity = velocity * 0.65 * delta;

	Entity::update(delta);
}
