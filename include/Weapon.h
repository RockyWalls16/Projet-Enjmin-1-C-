#pragma once
#include "DynamicEntity.h"

class Weapon : public StaticEntity
{
private:
	CHAR_INFO m_charInfo;

	char m_leftSkin, m_rightSkin;
	int m_shotReloadTime, m_shotSpeed;

public:
	Weapon(IVector2 p, char leftSkin, char rightSkin, int shotReloadTime, int shotSpeed);
	~Weapon();

	virtual void drawEntity(CHAR_INFO* buffer);

	inline char getSkins(bool right = false)
	{
		if (right)
			return m_rightSkin;
		else
			return m_leftSkin;
	}

	inline int getShotReloadTime()
	{
		return m_shotReloadTime;
	}

	inline int getshotSpeed()
	{
		return m_shotSpeed;
	}
};

