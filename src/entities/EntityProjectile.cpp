#include <map/Map.h>
#include "entities/EntityProjectile.h"
#include "entities/EntityWall.h"
#include "utils/TimeManager.h"

EntityProjectile::EntityProjectile(IVector2 p, EntityPlayer* shooter, float speed, int direction, float lifeTime) :
		EntityDynamic(p), m_speed(speed), m_direction(direction), m_lifeTime(
		TICK_PER_SECOND * lifeTime), shooter(shooter)
{
	gravity = 0;
	hitbox = new AABB(p.x, p.y, p.x + 1, p.y + 1);

	m_charInfo.Attributes = shooter->getPlayerColor();
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

void EntityProjectile::render(BufferRenderer* buffer)
{
	buffer->setCharAt(m_pos.x, m_pos.y, m_charInfo);
}

void EntityProjectile::onCollision(Entity * other)
{
	if (dynamic_cast<EntityWall*>(other) != nullptr)
		despawn();
	else
	{
		EntityPlayer *p = dynamic_cast<EntityPlayer*>(other);

		if (p)
		{
			despawn();
			p->die();
		}
	}
}
