#include "include\Projectile.h"

Projectile::Projectile(IVector2 p, float lifeTime) : DynamicEntity(p)
	, m_lifeTime(lifeTime)
{
	m_charInfo.Attributes = FOREGROUND_RED;
	m_charInfo.Char.AsciiChar = '~';
}


Projectile::~Projectile()
{

}

void Projectile::update(float delta)
{
	m_lifeTime -= delta;

	if (m_lifeTime < 0)
		despawn();

	DynamicEntity::update(delta);
}

void Projectile::drawEntity(CHAR_INFO * buffer)
{
	buffer[m_pos.x + m_pos.y * WIDTH] = m_charInfo;
}
