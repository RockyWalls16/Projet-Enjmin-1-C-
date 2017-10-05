#pragma once
#include "DynamicEntity.h"

class Projectile : public DynamicEntity
{
private:
	float m_lifeTime;
	CHAR_INFO m_charInfo;
	int m_direction;

public:
	Projectile(IVector2 p, float lifeTime, int direction);
	~Projectile();

	virtual void tick() override;
	virtual void render(CHAR_INFO* buffer) override;
};

