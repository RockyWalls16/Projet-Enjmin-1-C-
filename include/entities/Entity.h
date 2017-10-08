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
	bool m_display;

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

	virtual AABB* getAABB() { return nullptr; }

	void disappear();
	bool isVisible()
	{
		return m_display;
	}
};

#endif /* ENTITY_H_ */
