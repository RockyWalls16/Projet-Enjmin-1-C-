#include "Player.h"
#include "Map.h"

Player::Player(IVector2 p, int ID) : DynamicEntity(p)
	, m_direction(1)
	, m_alive(true)
	, m_canJump(true)
{
	gravity = 8.5F;
	hitbox = new AABB(p.x, p.y, p.x + 1, p.y + 2, true);
	m_charInfos[0].Attributes = m_charInfos[1].Attributes = m_charInfos[2].Attributes = 0x0002;

	m_charInfos[1].Char.AsciiChar = 2;
	m_charInfos[0].Char.AsciiChar = 31;

	equip(new Weapon(IVector2(0, 0), '<', '>', 10, 0.5));

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

Player::~Player()
{
	delete(m_weapon);
}

void Player::equip(Weapon *newWeapon)
{
	m_weapon = newWeapon;

	// Update weapon direction
	m_charInfos[2].Char.AsciiChar = m_weapon->getSkins(m_direction == 1);
}

void Player::die()
{
	m_charInfos[1].Char.AsciiChar = 'X';
	m_charInfos[0].Char.AsciiChar = 16;

	m_alive = false;
}

void Player::tick()
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
			setVelocity(Vector2(-0.8, 0));
			m_direction = -1;

			m_charInfos[2].Char.AsciiChar = m_weapon->getSkins(false);
		}
		else if (GetAsyncKeyState(m_ctrlRight))
		{
			setVelocity(Vector2(0.8, 0));
			m_direction = 1;

			m_charInfos[2].Char.AsciiChar = m_weapon->getSkins(true);
		}

		if (GetAsyncKeyState(m_ctrlUp) && m_canJump && onGround)
		{
			// JUMP
			addVelocity(Vector2(0, -4));
			m_canJump = false;
		}
		else if (!GetAsyncKeyState(m_ctrlUp))
		{
			m_canJump = true;
		}

		if (GetAsyncKeyState(m_ctrlFire))
			m_weapon->fire(IVector2(m_pos.x + m_direction * 2, m_pos.y + 1), m_direction);

		m_weapon->tick();

		// Check borders
		int tpOffset = 0;

		if (m_pos.x < 0)
		{
			m_realPosition.x = Map::getMap().getMapWidth();
			m_realPosition.y += 1;
		}
		else if (m_pos.x > Map::getMap().getMapWidth())
		{
			m_realPosition.x = 0;
			m_realPosition.y -= 1;
		}

		if (m_pos.y < 0)
			m_realPosition.y = Map::getMap().getMapHeight() - 1;
		else if (m_pos.y > Map::getMap().getMapHeight())
			m_realPosition.y = 0;
	}
	
	DynamicEntity::tick();
}

void Player::render(CHAR_INFO* buffer)
{
	if (m_alive)
	{
		buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfos[1];
		buffer[Map::getMap().getBufferFlatIndex(m_pos.x + m_direction, m_pos.y + 1)] = m_charInfos[2];
	}
	else
		buffer[Map::getMap().getBufferFlatIndex(m_pos.x - 1, m_pos.y + 1)] = m_charInfos[1];

	buffer[Map::getMap().getBufferFlatIndex(m_pos.x, m_pos.y + 1)] = m_charInfos[0];
}
