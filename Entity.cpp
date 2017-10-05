/*
 * GameObject.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "Entity.h"
#include "Map.h"

Entity::Entity(IVector2 pos)
	: m_pos(pos)
	, m_realPosition(pos.x, pos.y)
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
	Map::getMap().addEntity(this);
}

void Entity::despawn()
{
	Map::getMap().removeEntity(this);
}
