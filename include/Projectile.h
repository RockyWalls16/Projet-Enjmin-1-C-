#pragma once
#include "DynamicEntity.h"

class Projectile : public DynamicEntity
{
private:
	float m_speed;
	CHAR_INFO m_charInfo;
	int m_direction;

public:
	Projectile(IVector2 p, float m_speed, int direction);

	virtual void tick() override;
	virtual void render(CHAR_INFO* buffer) override;
};

