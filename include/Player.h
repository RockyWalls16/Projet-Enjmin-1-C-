#pragma once
#include "DynamicEntity.h"
#include "include\Projectile.h"

class Player : public DynamicEntity
{
private:
	CHAR_INFO m_charInfos[3];
	int m_direction;
	bool m_canJump;
	bool m_canFire;

	int m_ctrlUp, m_ctrlDown, m_ctrlLeft, m_ctrlRight, m_ctrlFire;

public:
	Player(IVector2 p, int ID);
	~Player();

	void fire();

	virtual void update(float delta) override;
	virtual void drawEntity(CHAR_INFO* buffer) override;
};

