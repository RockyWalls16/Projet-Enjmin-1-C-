#include "Projectile.h"
#include "Map.h"
#include "EntityWall.h"

Projectile::Projectile(IVector2 p, float speed, int direction) : DynamicEntity(p)
	, m_speed(speed)
	, m_direction(direction)
{
	gravity = 0;
	hitbox = new AABB(p.x, p.y, p.x+1, p.y+1, true);

	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = '*';
}

void Projectile::tick()
{
	if (m_pos.x < 0 || m_pos.x > Map::getMap().getMapWidth())
		despawn();

	setVelocity(Vector2(m_direction * m_speed, 0));

	DynamicEntity::tick();
}

void Projectile::render(CHAR_INFO * buffer)
{
	buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfo;
}

void Projectile::onCollision(Entity * other)
{
	EntityWall *w = dynamic_cast<EntityWall*>(other);

	if(w != nullptr)
		despawn();

	/*
	Player *p = dynamic_cast<Player*>(other);

	if (w != nullptr)
	{
		despawn();
		p->despawn();

	}
	*/
}
