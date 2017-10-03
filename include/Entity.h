/*
* GameObject.h
*
*  Created on: 2 oct. 2017
*      Author: Valentin
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <windows.h>
#include "Vector.h"

class Entity
{
protected:
	IVector2 m_posInfos;
	Vector2 m_realPosition;

public:
	Entity(IVector2 pos);
	virtual ~Entity();

	// Update entity
	virtual void update(float delta);

	virtual void drawEntity(CHAR_INFO* buffer){};

	// Spawn entity
	void spawn();

	// Despawn entity
	void despawn();

	IVector2 getPos()
	{
		return m_posInfos;
	}
};

#endif /* ENTITY_H_ */
