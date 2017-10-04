#include "Player.h"
#include "Map.h"

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
	if (GetAsyncKeyState(VK_UP))
	{
		m_charInfos[1].Char.AsciiChar = 'X';
		setVelocity(Vector2(0, -0.000002));
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_charInfos[1].Char.AsciiChar = 'X';
		setVelocity(Vector2(0, 0.000002));
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_charInfos[1].Char.AsciiChar = 'X';
		setVelocity(Vector2(-0.000002, 0));
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_charInfos[1].Char.AsciiChar = 'X';
		setVelocity(Vector2(0.000002, 0));
	}

	DynamicEntity::update(delta);
}

void Player::drawEntity(CHAR_INFO* buffer)
{
	// Check borders
	if (m_posInfos.x < 0)
		m_realPosition.x = Map::getMap().getMapWidth();
	else if (m_posInfos.x > Map::getMap().getMapWidth())
		m_realPosition.x = 0;

	if (m_posInfos.y < 0)
		m_realPosition.y = Map::getMap().getMapHeight();
	else if (m_posInfos.y > Map::getMap().getMapHeight())
		m_realPosition.y = 0;
		
	buffer[m_posInfos.x + m_posInfos.y * Map::getMap().getMapWidth()] = m_charInfos[1];

	if (m_posInfos.y +1 < Map::getMap().getMapHeight() && m_posInfos.y +1 > 0)
		buffer[m_posInfos.x + (m_posInfos.y + 1)* Map::getMap().getMapWidth()] = m_charInfos[0];
}
