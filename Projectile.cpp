#include "Projectile.h"
#include "Map.h"

Projectile::Projectile(IVector2 p, float speed, int direction) : DynamicEntity(p)
	, m_speed(speed)
	, m_direction(direction)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = '*';

	setVelocity(Vector2((float)m_direction * m_speed, 0));
}

void Projectile::tick()
{
	if (m_pos.x < 0 || m_pos.x > Map::getMap().getMapWidth())
		despawn();

	DynamicEntity::tick();
}

void Projectile::render(CHAR_INFO * buffer)
{
	buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfo;
}