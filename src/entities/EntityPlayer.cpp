#include <map/Map.h>
#include "entities/EntityPlayer.h"
#include "utils/Utils.h"

EntityPlayer::EntityPlayer(IVector2 p, int ID) :
		EntityDynamic(p), m_direction(1), m_alive(true), m_canJump(true)
{
	gravity = 8.5F;
	hitbox = new AABB(p.x, p.y, p.x + 1, p.y + 2, true);
	m_charInfos[0].Attributes = m_charInfos[1].Attributes =
			m_charInfos[2].Attributes = 0x0002;

	m_charInfos[1].Char.AsciiChar = 2;
	m_charInfos[0].Char.AsciiChar = 31;

	equip(new EntityWeapon(IVector2(0, 0), '<', '>', 10, 0.5, 3));

	// Manage controls
	if (ID == 0)
	{
		m_ctrlUp = VK_UP;
		m_ctrlDown = VK_DOWN;
		m_ctrlLeft = VK_LEFT;
		m_ctrlRight = VK_RIGHT;
		m_ctrlFire = VK_DELETE;
	}
	else if (ID == 1)
	{
		m_ctrlUp = 'W';
		m_ctrlDown = 'S';
		m_ctrlLeft = 'A';
		m_ctrlRight = 'D';
		m_ctrlFire = VK_SPACE;
	}
}

EntityPlayer::~EntityPlayer()
{
	delete (m_weapon);
}

void EntityPlayer::equip(EntityWeapon *newWeapon)
{
	m_weapon = newWeapon;

	// Update weapon direction
	m_charInfos[2].Char.AsciiChar = m_weapon->getSkins(m_direction == 1);
}

void EntityPlayer::die()
{
	m_charInfos[1].Char.AsciiChar = 'X';
	m_charInfos[0].Char.AsciiChar = 16;

	m_alive = false;
}

void EntityPlayer::tick()
{
	if (m_alive)
	{
		/*else if (GetAsyncKeyState(m_ctrlDown))
		 {
		 setVelocity(Vector2(0, 0.000002));
		 m_direction = IVector2(0, 1);
		 }*/
		if (GetAsyncKeyState(m_ctrlLeft))
		{
			velocity.x = -0.8;
			m_direction = -1;

			m_charInfos[2].Char.AsciiChar = m_weapon->getSkins(false);
		}
		else if (GetAsyncKeyState(m_ctrlRight))
		{
			velocity.x = 0.8;
			m_direction = 1;

			m_charInfos[2].Char.AsciiChar = m_weapon->getSkins(true);
		}

		if (GetAsyncKeyState(m_ctrlUp) && m_canJump && onGround)
		{
			// JUMP
			velocity.y = -4;
			m_canJump = false;
		}
		else if (!GetAsyncKeyState(m_ctrlUp))
		{
			m_canJump = true;
		}

		if (GetAsyncKeyState(m_ctrlFire))
			m_weapon->fire(IVector2(m_pos.x + m_direction * 2, m_pos.y + 1),
					m_direction);

		m_weapon->tick();
	}

	EntityDynamic::tick();
}

void EntityPlayer::render(CHAR_INFO* buffer)
{
	if (m_alive)
	{
		buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfos[1];
		buffer[Map::getMap().getBufferFlatIndex(m_pos.x + m_direction,
				m_pos.y + 1)] = m_charInfos[2];
	}
	else
		buffer[Map::getMap().getBufferFlatIndex(m_pos.x - 1, m_pos.y + 1)] =
				m_charInfos[1];

	buffer[Map::getMap().getBufferFlatIndex(m_pos.x, m_pos.y + 1)] =
			m_charInfos[0];
}
