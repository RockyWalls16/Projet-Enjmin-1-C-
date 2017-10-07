/*
 * GameObject.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "GameController.h"
#include "entities/Entity.h"
#include <iostream>

Entity::Entity(IVector2 pos) : m_pos(pos), m_realPosition(pos.x, pos.y)
{

}

Entity::~Entity()
{
	despawn();
}

void Entity::tick()
{
	m_pos = m_realPosition.asIVector2();
}

void Entity::spawn()
{
	GameController::getInstance().getCurrentMap()->prepareSpawnEntity(this);
}

void Entity::despawn()
{
	GameController::getInstance().getCurrentMap()->removeEntity(this);
}
