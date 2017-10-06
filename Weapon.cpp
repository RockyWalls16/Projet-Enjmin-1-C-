#include "Weapon.h"
#include "Map.h"

Weapon::Weapon(IVector2 p, char leftSkin, char rightSkin, int shotReloadTime, float shotSpeed, float shotLifeTime) : StaticEntity(p)
	, m_leftSkin(leftSkin)
	, m_rightSkin(rightSkin)
	, m_shotSpeed(shotSpeed)
	, m_shotLifeTime(shotLifeTime)
	, m_reloadTime(shotReloadTime)
	, m_nextShotReadyTime(0)
	, m_canFire(true)
{
	m_charInfo.Attributes = FOREGROUND_INTENSITY;
	m_charInfo.Char.AsciiChar = rightSkin;

	hitbox = new AABB(p.x, p.y, p.x + 1, p.y + 1, true);
}

void Weapon::tick()
{
	m_nextShotReadyTime--;

	if (m_nextShotReadyTime < 0)
		m_canFire = true;

	StaticEntity::tick();
}

void Weapon::render(CHAR_INFO * buffer)
{
	if(m_display)
		buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfo;
}

void Weapon::fire(IVector2 pos, int dir)
{
	if (m_canFire)
	{
		m_canFire = false;
		m_nextShotReadyTime = m_reloadTime;
		Map::getMap().prepareSpawnEntity(new Projectile(pos, m_shotSpeed, dir, m_shotLifeTime));
	}
}
