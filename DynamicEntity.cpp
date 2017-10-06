/*
 * Entity.cpp
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#include "DynamicEntity.h"
#include "Map.h"
#include "Utils.h"
#include "TimeManager.h"
#include <iostream>

DynamicEntity::DynamicEntity(IVector2 p)
	: StaticEntity(p)
	, gravity(0)
	, velocity({0.0, 0.0})
	, onGround(false)
{
	
}

void DynamicEntity::tick()
{
	velocity.y += gravity / TICK_PER_SECOND * (1.6F);

	bool isGrounded = false;
	if(hitbox)
	{
		// X Collide
		float xVel = velocity.x;
		for (Entity* entity : Map::getMap().getEntityList())
		{
			AABB* otherEntity = entity->getAABB();
			if (otherEntity && otherEntity->isBlockCollision())
			{
				otherEntity->clipX(&velocity.x, *hitbox);
				
				if (xVel != velocity.x)
					onCollision(entity);
			}
		}

		hitbox->updatePos(m_pos.x + (int) velocity.x, m_pos.y);

		// Y Collide
		float yVel = velocity.y;
		for(Entity* entity : Map::getMap().getEntityList())
		{
			AABB* otherEntity = entity->getAABB();
			if (otherEntity && otherEntity->isBlockCollision())
			{
				isGrounded = isGrounded || otherEntity->clipY(&velocity.y, *hitbox);

				if (yVel != velocity.y)
					onCollision(entity);
			}
		}
	}

	velocity = (velocity * 0.4);

	onGround = isGrounded;
	m_realPosition = m_realPosition + velocity;
	Entity::tick();

	if(hitbox)
	{
		hitbox->updatePos(m_pos.x, m_pos.y);
	}
}
