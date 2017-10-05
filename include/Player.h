#pragma once
#include "DynamicEntity.h"
#include "Projectile.h"
#include "Weapon.h"

class Player : public DynamicEntity
{
private:
	CHAR_INFO m_charInfos[3];
	int m_direction;
	bool m_canJump;
	bool m_canFire;

	int m_ctrlUp, m_ctrlDown, m_ctrlLeft, m_ctrlRight, m_ctrlFire;

	Weapon* m_weapon;

public:
	Player(IVector2 p, int ID);
	~Player();

	void equip(Weapon *newWeapon);

	virtual void tick() override;
	virtual void render(CHAR_INFO* buffer) override;
};

