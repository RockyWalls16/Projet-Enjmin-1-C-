#pragma once
#include "DynamicEntity.h"

class Player : public DynamicEntity
{
private:
	CHAR_INFO m_charInfos[2];

	int m_ctrlUp, m_ctrlDown, m_ctrlLeft, m_ctrlRight, m_ctrlFire;

public:
	Player(IVector2 p, int ID);
	~Player();

	virtual void update(float delta) override;

	virtual void drawEntity(CHAR_INFO* buffer) override;
};

