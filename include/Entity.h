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
#include "Vector.h"
#include "AABB.h"

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

	virtual void render(CHAR_INFO* buffer){};

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
