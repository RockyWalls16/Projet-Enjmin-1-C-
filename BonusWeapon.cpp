#pragma once
#include "BonusWeapon.h"
#include "Map.h";

BonusWeapon::BonusWeapon(IVector2 p, char leftSkin, char rightSkin) : StaticEntity(p)
	, m_leftSkin(leftSkin)
	, m_rightSkin(rightSkin)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = rightSkin;
}

BonusWeapon::~BonusWeapon()
{

}

void BonusWeapon::drawEntity(CHAR_INFO * buffer)
{
	buffer[m_pos.x + m_pos.y * Map::getMap().getMapWidth()] = m_charInfo;
}

char* BonusWeapon::getSkins()
{
	return new char[2]
	{
		m_leftSkin,
		m_rightSkin
	};
}
