/*
 * GameObject.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "Entity.h"

Entity::Entity(IVector2 p, CHAR_INFO c)
	: m_charInfo(c)
	, m_posInfos(p)
	, m_realPosition(0.0F, 0.0F)
{

}

Entity::~Entity()
{

}

void Entity::update(float delta)
{
	m_posInfos = m_realPosition.asIVector2();
}
