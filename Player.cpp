#include "Player.h"
#include "Map.h"

Player::Player(IVector2 p, int ID) : DynamicEntity(p)
	, m_direction(1)
	, m_canJump(true)
	, m_canFire(true)
{
	m_charInfos[0].Attributes = m_charInfos[1].Attributes = m_charInfos[2].Attributes = 0x0002;

	m_charInfos[2].Char.AsciiChar = 62;
	m_charInfos[1].Char.AsciiChar = 2;
	m_charInfos[0].Char.AsciiChar = 219;

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

}

void Player::fire()
{
	/*Projectile newProj(IVector2(m_direction, 0), 1);
	newProj.setVelocity(Vector2(m_direction/1000, 0));
	newProj.spawn();*/

	Player player0(IVector2(20, 20), 0);
	player0.spawn();	
}

void Player::update(float delta)
{
	if (GetAsyncKeyState(m_ctrlUp))
	{
		// JUMP
		if(m_canJump)
			addVelocity(Vector2(0, -0.1));

		m_canJump = false;
	}
	/*else if (GetAsyncKeyState(m_ctrlDown))
	{
		setVelocity(Vector2(0, 0.000002));
		m_direction = IVector2(0, 1);
	}*/
	else if (GetAsyncKeyState(m_ctrlLeft))
	{
		setVelocity(Vector2(-0.01, 0));
		m_direction = -1;

		m_charInfos[2].Char.AsciiChar = 60;
	}
	else if (GetAsyncKeyState(m_ctrlRight))
	{
		setVelocity(Vector2(0.01, 0));
		m_direction = 1;

		m_charInfos[2].Char.AsciiChar = 62;
	}

	if (GetAsyncKeyState(m_ctrlFire) && m_canFire)
	{
		m_canFire = false;
		fire();
	}

	DynamicEntity::update(delta);
}

void Player::drawEntity(CHAR_INFO* buffer)
{
	// Check borders
	if (m_pos.x < 0)
		m_realPosition.x = Map::getMap().getMapWidth();
	else if (m_pos.x > Map::getMap().getMapWidth())
		m_realPosition.x = 0;

	if (m_pos.y < 0)
		m_realPosition.y = Map::getMap().getMapHeight();
	else if (m_pos.y > Map::getMap().getMapHeight())
		m_realPosition.y = 0;
		
	buffer[m_pos.x + m_pos.y * Map::getMap().getMapWidth()] = m_charInfos[0];
	buffer[(m_pos.x) + (m_pos.y - 1)* Map::getMap().getMapWidth()] = m_charInfos[1];
	buffer[(m_pos.x + m_direction) + (m_pos.y* Map::getMap().getMapWidth())] = m_charInfos[2];
}
