#include "Player.h"
#include "Map.h"

Player::Player(IVector2 p, int ID) : DynamicEntity(p)
	, m_direction(1)
	, m_canFire(true)
	, m_nextShotReadyTime(1)
{
	gravity = 4.5F;
	hitbox = new AABB(p.x, p.y, p.x + 1, p.y + 2);
	m_charInfos[0].Attributes = m_charInfos[1].Attributes = m_charInfos[2].Attributes = 0x0002;

	m_charInfos[2].Char.AsciiChar = 62;
	m_charInfos[1].Char.AsciiChar = 2;
	m_charInfos[0].Char.AsciiChar = 219;

	m_reloadTime = 1;

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
	Map::getMap().prepareSpawnEntity(new Projectile(IVector2(m_pos.x + m_direction, m_pos.y),1000, m_direction));
}

void Player::tick()
{
	m_nextShotReadyTime--;

	if(m_nextShotReadyTime < 0)
		m_canFire = true;

	if (GetAsyncKeyState(m_ctrlUp) && onGround)
	{
		// JUMP
		addVelocity(Vector2(0, -4));
	}
	/*else if (GetAsyncKeyState(m_ctrlDown))
	{
		setVelocity(Vector2(0, 0.000002));
		m_direction = IVector2(0, 1);
	}*/
	else if (GetAsyncKeyState(m_ctrlLeft))
	{
		setVelocity(Vector2(-0.8, 0));
		m_direction = -1;

		m_charInfos[2].Char.AsciiChar = 60;
	}
	else if (GetAsyncKeyState(m_ctrlRight))
	{
		setVelocity(Vector2(0.8, 0));
		m_direction = 1;

		m_charInfos[2].Char.AsciiChar = 62;
	}

	if (GetAsyncKeyState(m_ctrlFire) && m_canFire)
	{
		m_canFire = false;
		m_nextShotReadyTime = m_reloadTime;
		fire();
	}

	DynamicEntity::tick();
}

void Player::render(CHAR_INFO* buffer)
{
	// Check borders
	if (m_pos.x < 0)
		m_realPosition.x = Map::getMap().getMapWidth();
	else if (m_pos.x > Map::getMap().getMapWidth())
		m_realPosition.x = 0;

	if (m_pos.y < 0)
		m_realPosition.y = Map::getMap().getMapHeight() - 1;
	else if (m_pos.y > Map::getMap().getMapHeight())
		m_realPosition.y = 0;
		
	buffer[Map::getMap().getBufferFlatIndex(m_pos.x, m_pos.y + 1)] = m_charInfos[0];
	buffer[Map::getMap().getBufferFlatIndex(m_pos)] = m_charInfos[1];
	buffer[Map::getMap().getBufferFlatIndex(m_pos.x + m_direction, m_pos.y + 1)] = m_charInfos[2];
}
