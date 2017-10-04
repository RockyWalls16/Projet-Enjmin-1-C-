#pragma once
#include "include\Projectile.h"
#include "Map.h"

Projectile::Projectile(IVector2 p, float lifeTime, int direction) : DynamicEntity(p)
	, m_lifeTime(lifeTime)
	, m_direction(direction)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = '*';
}


Projectile::~Projectile()
{

}

void Projectile::update(float delta)
{
	m_lifeTime -= delta;

	if (m_lifeTime < 0 ||
		m_pos.x < 0 || m_pos.x > Map::getMap().getMapWidth())
		despawn();

	setVelocity(Vector2(m_direction, 0));

	DynamicEntity::update(delta);
}

void Projectile::drawEntity(CHAR_INFO * buffer)
{
	buffer[m_pos.x + m_pos.y * Map::getMap().getMapWidth()] = m_charInfo;
}
