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

DynamicEntity::~DynamicEntity()
{

}

void DynamicEntity::tick()
{
	velocity.y += gravity / TICK_PER_SECOND * (1.6F);

	bool isGrounded = false;
	if(hitbox)
	{
		// X Collide
		for(Entity* entity : Map::getMap().getEntityList())
		{
			AABB* otherEntity = entity->getAABB();
			if(otherEntity != nullptr)
				if(otherEntity->isBlockCollision())
					otherEntity->clipX(&velocity.x, *hitbox);
		}

		hitbox->updatePos(m_pos.x + (int) velocity.x, m_pos.y);

		// Y Collide
		for(Entity* entity : Map::getMap().getEntityList())
		{
			AABB* otherEntity = entity->getAABB();
			if (otherEntity != nullptr)
				if(otherEntity->isBlockCollision())
					isGrounded = isGrounded || otherEntity->clipY(&velocity.y, *hitbox);
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
