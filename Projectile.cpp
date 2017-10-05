#include "Projectile.h"
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

void Projectile::tick()
{
	m_lifeTime--;

	if (m_lifeTime < 0 ||
		m_pos.x < 0 || m_pos.x > Map::getMap().getMapWidth())
		despawn();

	setVelocity(Vector2(m_direction * 0.05F, 0));

	DynamicEntity::tick();
}

void Projectile::render(CHAR_INFO * buffer)
{
	buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfo;
}
