#pragma once
#include "DynamicEntity.h"

class Player : public DynamicEntity
{
private:
	CHAR_INFO m_charInfos[2];

public:
	Player(IVector2 p);
	~Player();

	virtual void update(float delta) override;

	virtual void drawEntity(CHAR_INFO* buffer) override;
};

