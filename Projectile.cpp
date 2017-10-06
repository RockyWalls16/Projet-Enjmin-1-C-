#include "Projectile.h"
#include "Map.h"
#include "EntityWall.h"
#include "TimeManager.h"

Projectile::Projectile(IVector2 p, float speed, int direction, float lifeTime) : DynamicEntity(p)
	, m_speed(speed)
	, m_direction(direction)
	, m_lifeTime(TICK_PER_SECOND * lifeTime)
{
	gravity = 0;
	hitbox = new AABB(p.x, p.y, p.x+1, p.y+1);

	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = '*';
}

void Projectile::tick()
{
	m_lifeTime--;

	if (m_lifeTime < 0)
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
	if(dynamic_cast<EntityWall*>(other) != nullptr)
		despawn();
	else
	{
		Player *p = dynamic_cast<Player*>(other);

		if (p != nullptr)
		{
			despawn();
			p->die();
		}
	}
}
