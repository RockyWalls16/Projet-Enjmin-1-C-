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
	Vector2 m_realPosition;
	CHAR_INFO m_charInfo;
	IVector2 m_posInfos;

public:
	Entity(IVector2 pos, CHAR_INFO info);
	virtual ~Entity();

	virtual void update(float delta);

	CHAR_INFO getInfos()
	{
		return m_charInfo;
	}

	IVector2 getPos()
	{
		return m_posInfos;
	}
};

#endif /* ENTITY_H_ */
