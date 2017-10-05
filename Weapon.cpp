#pragma once
#include "BonusWeapon.h"
#include "Map.h";

Weapon::Weapon(IVector2 p, char leftSkin, char rightSkin, int shotReloadTime, int shotSpeed) : StaticEntity(p)
	, m_leftSkin(leftSkin)
	, m_rightSkin(rightSkin)
	, m_shotReloadTime(shotReloadTime)
	, m_shotSpeed(shotSpeed)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = rightSkin;
}

Weapon::~Weapon()
{

}

void Weapon::drawEntity(CHAR_INFO * buffer)
{
	buffer[m_pos.x + m_pos.y * Map::getMap().getMapWidth()] = m_charInfo;
}