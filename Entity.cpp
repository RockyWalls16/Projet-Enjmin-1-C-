/*
 * GameObject.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "Entity.h"

Entity::Entity(IVector2 pos, CHAR_INFO info)
	: m_charInfo(info)
	, m_posInfos(pos)
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
