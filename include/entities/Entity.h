/*
 * GameObject.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#pragma once
#include <windows.h>
#include "math/Vector.h"
#include "math/AABB.h"
#include "BufferRenderer.h"

class Entity
{
protected:
	IVector2 m_pos;
	Vector2 m_realPosition;

public:
	Entity(IVector2 pos);
	virtual ~Entity();

	// Update entity
	virtual void tick();

	virtual void render(BufferRenderer* bufferRenderer){};

	// Spawn entity
	void spawn();

	// Despawn entity
	void despawn();

	IVector2 getPos()
	{
		return m_pos;
	}

	virtual AABB* getAABB()
	{
		return nullptr;
	}
};

#endif /* ENTITY_H_ */
