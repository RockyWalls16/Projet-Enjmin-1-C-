#include <map/Map.h>
#include "entities/EntityWeapon.h"

EntityWeapon::EntityWeapon(IVector2 p, char leftSkin, char rightSkin,
		int shotReloadTime, float shotSpeed, float shotLifeTime) :
		EntityStatic(p), m_leftSkin(leftSkin), m_rightSkin(rightSkin), m_shotSpeed(
				shotSpeed), m_shotLifeTime(shotLifeTime), m_reloadTime(
				shotReloadTime), m_nextShotReadyTime(0), m_canFire(true)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = rightSkin;
}

void EntityWeapon::tick()
{
	m_nextShotReadyTime--;

	if (m_nextShotReadyTime < 0)
		m_canFire = true;

	EntityStatic::tick();
}

void EntityWeapon::drawEntity(CHAR_INFO * buffer)
{
	buffer[m_pos.x + m_pos.y * Map::getMap().getMapWidth()] = m_charInfo;
}

void EntityWeapon::fire(IVector2 pos, int dir)
{
	if (m_canFire)
	{
		m_canFire = false;
		m_nextShotReadyTime = m_reloadTime;
		Map::getMap().prepareSpawnEntity(
				new EntityProjectile(pos, m_shotSpeed, dir, m_shotLifeTime));
	}
}
