#include "Player.h"

Player::Player(IVector2 p) : DynamicEntity(p)
{
	m_charInfos[0].Attributes = m_charInfos[1].Attributes = 0x0002;

	m_charInfos[1].Char.AsciiChar = 'P';
	m_charInfos[0].Char.UnicodeChar = 'I';
}


Player::~Player()
{}

void Player::update(float delta)
{
	if (GetAsyncKeyState(VK_TAB))
	{
		m_charInfos[1].Char.AsciiChar = 'X';
		setVelocity(Vector2(1,1));
	}

	DynamicEntity::update(delta);
}

void Player::drawEntity(CHAR_INFO* buffer)
{
	if (m_posInfos.x >= 0 && m_posInfos.x < WIDTH)
		if (m_posInfos.y >= 0 && m_posInfos.y < HEIGHT)
		{
			buffer[m_posInfos.x + (m_posInfos.y + 1)* WIDTH] = m_charInfos[0];
			buffer[m_posInfos.x + m_posInfos.y * WIDTH] = m_charInfos[1];
		}
	
}
