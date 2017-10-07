#pragma once
#include "entities/EntityDynamic.h"
#include "entities/EntityProjectile.h"
#include "entities/EntityWeapon.h"

class EntityPlayer: public EntityDynamic
{
private:
	CHAR_INFO m_charInfos[3];
	int m_direction;
	bool m_alive;
	bool m_canJump;

	int m_ctrlUp, m_ctrlDown, m_ctrlLeft, m_ctrlRight, m_ctrlFire;

	EntityWeapon* m_weapon;

public:
	EntityPlayer(IVector2 p, int ID);
	~EntityPlayer();

	void equip(EntityWeapon *newWeapon);
	void die();

	virtual void tick() override;
	virtual void render(BufferRenderer* buffer) override;
};

