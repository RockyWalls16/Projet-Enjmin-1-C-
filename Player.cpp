#include "Player.h"

Player::Player(IVector2 p, int ID) : DynamicEntity(p)
	, m_direction(0, 0)
{
	m_charInfos[0].Attributes = m_charInfos[1].Attributes = m_charInfos[2].Attributes = 0x0002;

	m_charInfos[2].Char.AsciiChar = 0;
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

void Player::update(float delta)
{
	// TODO : Rotate dans la bonne direction

	if (GetAsyncKeyState(m_ctrlUp))
	{
		/*setVelocity(Vector2(0, -0.000002));
		m_direction = IVector2(0, -1);*/

		// JUMP
	}
	/*else if (GetAsyncKeyState(m_ctrlDown))
	{
		setVelocity(Vector2(0, 0.000002));
		m_direction = IVector2(0, 1);
	}*/
	else if (GetAsyncKeyState(m_ctrlLeft))
	{
		setVelocity(Vector2(-0.01, 0));
		m_direction = IVector2(-1, 0);

		m_charInfos[2].Char.AsciiChar = 60;
	}
	else if (GetAsyncKeyState(m_ctrlRight))
	{
		setVelocity(Vector2(0.01, 0));
		m_direction = IVector2(1, 0);

		m_charInfos[2].Char.AsciiChar = 62;
	}
	else if (GetAsyncKeyState(m_ctrlFire))
	{
		// Fire
	}

	DynamicEntity::update(delta);
}

void Player::drawEntity(CHAR_INFO* buffer)
{
	// Check borders
	if (m_posInfos.x < 0)
		m_realPosition.x = WIDTH;
	else if (m_posInfos.x > WIDTH)
		m_realPosition.x = 0;

	if (m_posInfos.y < 0)
		m_realPosition.y = HEIGHT;
	else if (m_posInfos.y > HEIGHT)
		m_realPosition.y = 0;
		
	buffer[m_posInfos.x + m_posInfos.y * WIDTH] = m_charInfos[0];
	buffer[(m_posInfos.x) + (m_posInfos.y - 1)* WIDTH] = m_charInfos[1];

	if(m_direction.x == 1)
		buffer[(m_posInfos.x + 1) + (m_posInfos.y* WIDTH)] = m_charInfos[2];
	else if(m_direction.x == -1)
		buffer[(m_posInfos.x - 1) + (m_posInfos.y* WIDTH)] = m_charInfos[2];
}
