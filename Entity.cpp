/*
 * GameObject.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "Entity.h"
#include "Map.h"

Entity::Entity(IVector2 pos)
	: m_posInfos(pos)
	, m_realPosition(0.0F, 0.0F)
{

}

Entity::~Entity()
{
	despawn();
}

void Entity::update(float delta)
{
	m_posInfos = m_realPosition.asIVector2();
}

void Entity::spawn()
{
	Map::getMap().addEntity(this);
}

void Entity::despawn()
{
	Map::getMap().removeEntity(this);
}
