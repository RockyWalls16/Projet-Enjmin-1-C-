#include "entities/EntityProjectile.h"
#include "Map.h"
#include "entities/EntityWall.h"
#include "utils/TimeManager.h"

EntityProjectile::EntityProjectile(IVector2 p, float speed, int direction,
		float lifeTime) :
		EntityDynamic(p), m_speed(speed), m_direction(direction), m_lifeTime(
				TICK_PER_SECOND * lifeTime)
{
	gravity = 0;
	hitbox = new AABB(p.x, p.y, p.x + 1, p.y + 1);

	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = '*';
}

void EntityProjectile::tick()
{
	m_lifeTime--;

	if (m_lifeTime < 0)
		despawn();

	setVelocity(Vector2(m_direction * m_speed, 0));

	EntityDynamic::tick();
}

void EntityProjectile::render(CHAR_INFO * buffer)
{
	buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfo;
}

void EntityProjectile::onCollision(Entity * other)
{
	if (dynamic_cast<EntityWall*>(other) != nullptr)
		despawn();
	else
	{
		EntityPlayer *p = dynamic_cast<EntityPlayer*>(other);

		if (p != nullptr)
		{
			despawn();
			p->die();
		}
	}
}
