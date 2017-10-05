#pragma once
#include "DynamicEntity.h"

class Weapon : public StaticEntity
{
private:
	CHAR_INFO m_charInfo;

	char m_leftSkin, m_rightSkin;

	float m_shotSpeed;

	float m_reloadTime;
	float m_nextShotReadyTime;

	bool m_canFire;

public:
	Weapon(IVector2 p, char leftSkin, char rightSkin, int shotReloadTime, float shotSpeed);

	virtual void tick() override;

	virtual void drawEntity(CHAR_INFO* buffer);

	void fire(IVector2 pos, int dir);

	inline char getSkins(bool right = false)
	{
		if (right)
			return m_rightSkin;
		else
			return m_leftSkin;
	}
};

