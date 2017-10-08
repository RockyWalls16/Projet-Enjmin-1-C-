#pragma once

#include <entities/EntityDynamic.h>
#include <windows.h>

class EntityPlayer;

class EntityProjectile: public EntityDynamic
{
private:
	float m_speed;
	CHAR_INFO m_charInfo;
	int m_direction;
	int m_lifeTime;
	EntityPlayer* shooter;

	virtual void onCollision(Entity* other) override;

public:
	EntityProjectile(IVector2 p, EntityPlayer* shooter, float speed, int direction, float lifeTime);

	virtual void tick() override;
	virtual void render(BufferRenderer* buffer) override;
};

