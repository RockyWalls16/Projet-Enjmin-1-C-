#include "Weapon.h"
#include "Map.h"

Weapon::Weapon(IVector2 p, char leftSkin, char rightSkin, int shotReloadTime, float shotSpeed) : StaticEntity(p)
	, m_leftSkin(leftSkin)
	, m_rightSkin(rightSkin)
	, m_shotSpeed(shotSpeed)
	, m_reloadTime(shotReloadTime)
	, m_nextShotReadyTime(0)
	, m_canFire(true)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = rightSkin;
}

void Weapon::tick()
{
	m_nextShotReadyTime--;

	if (m_nextShotReadyTime < 0)
		m_canFire = true;

	StaticEntity::tick();
}

void Weapon::drawEntity(CHAR_INFO * buffer)
{
	buffer[m_pos.x + m_pos.y * Map::getMap().getMapWidth()] = m_charInfo;
}

void Weapon::fire(IVector2 pos, int dir)
{
	if (m_canFire)
	{
		m_canFire = false;
		m_nextShotReadyTime = m_reloadTime;
		Map::getMap().prepareSpawnEntity(new Projectile(pos, m_shotSpeed, dir));
	}
}
