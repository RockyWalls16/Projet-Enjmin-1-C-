#pragma once
#include "entities/EntityDynamic.h"
#include "entities/EntityProjectile.h"
#include "entities/EntityWeapon.h"
#include <windows.h>
#include "utils/Colors.h"

class EntityPlayer: public EntityDynamic
{
private:
	static WORD playerColors[4];

	int id;
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
	
	virtual void onCollision(Entity* other) override;

	WORD getPlayerColor()
	{
		return playerColors[id];
	}
};

