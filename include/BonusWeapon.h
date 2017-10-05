#pragma once
#include "DynamicEntity.h"

class BonusWeapon : public StaticEntity
{
private:
	CHAR_INFO m_charInfo;

	char m_leftSkin, m_rightSkin;

public:
	BonusWeapon(IVector2 p, char leftSkin, char rightSkin);
	~BonusWeapon();

	virtual void drawEntity(CHAR_INFO* buffer);

	char* getSkins();
};

