#pragma once
#include "DynamicEntity.h"

class Projectile : public DynamicEntity
{
private:
	float m_lifeTime;
	CHAR_INFO m_charInfo;

public:
	Projectile(IVector2 p, float lifeTime);
	~Projectile();

	virtual void update(float delta) override;
	virtual void drawEntity(CHAR_INFO* buffer) override;
};

