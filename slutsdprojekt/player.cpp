#include "Player.h"
#include <SFML\Graphics.hpp>



CPlayer::CPlayer(int x, int y)
{
	m_playerText.loadFromFile("zelda.png");
	m_playerText2.loadFromFile("zelda2.png");
	m_player.setTexture(m_playerText);
	m_player.setTextureRect(sf::IntRect(0, 0, 80, 80));
	
	m_counter = 0;
	m_Ccounter = 0;
	m_spd;
	yCount = 0;
	m_player.setPosition(480, 53);
	skorOn = false;

}

CPlayer::~CPlayer()
{

}
sf::Sprite CPlayer::draw()
{
	return m_player;
}
void CPlayer::moveUp()
{
	yCount = 6;
	m_player.setTextureRect(sf::IntRect(m_counter * 80, yCount * 80, 80, 80));
	m_player.move(0, -m_spd);
	m_Ccounter++;
	if (m_Ccounter == 30)
	{
		m_counter++;
		m_Ccounter = 0;
		if (m_counter == 10)
		{
			m_counter = 0;
		}
	}
}
void CPlayer::moveDown()
{
	yCount = 4;
	m_player.setTextureRect(sf::IntRect(m_counter * 80, yCount * 80, 80, 80));
	m_player.move(0, m_spd);
	m_Ccounter++;
	if (m_Ccounter == 30)
	{
		m_counter++;
		m_Ccounter = 0;
		if (m_counter == 10)
		{
			m_counter = 0;
		}
	}
}
void CPlayer::moveLeft()
{
	yCount = 5;
	m_player.setTextureRect(sf::IntRect(m_counter * 80, yCount * 80, 80, 80));
	m_player.move(-m_spd, 0);

	m_Ccounter++;
	if (m_Ccounter == 30)
	{
		m_counter++;
		m_Ccounter = 0;
		if (m_counter == 10)
			m_counter = 0;
	}

}
void CPlayer::moveRight()
{
	yCount = 7;
	m_player.setTextureRect(sf::IntRect(m_counter * 80, yCount * 80, 80, 80));
	m_player.move(m_spd, 0);
	m_Ccounter++;
	if (m_Ccounter == 30)
	{
		m_counter++;
		m_Ccounter = 0;
		if (m_counter == 10)
		{
			m_counter = 0;

		}
	}

}

void CPlayer::heroIdle()
{
	m_player.setTextureRect(sf::IntRect(0, 80, 80, 80));
}
int CPlayer::getPosX()
{
	return m_player.getPosition().x + 40;
}
int CPlayer::getPosY()
{
	return	m_player.getPosition().y + 40;
}
void CPlayer::heroAttack()
{
	if (yCount == 7)
	{
		m_player.move(m_spd, 0);
		m_player.setTextureRect(sf::IntRect(m_counter * 80, 8 * 80, 80, 80));
		m_Ccounter++;
		if (m_Ccounter == 20)
		{
			m_counter++;
			m_Ccounter = 0;
		}
		if (m_counter >= 3)
		{
			m_counter = 0;
		}
	}
	if (yCount == 5)
	{
		m_player.move(-m_spd, 0);
	}
	if (yCount == 4)
	{
		m_player.move(0, m_spd);
	}
	if (yCount == 6)
	{
		m_player.move(0, -m_spd);
	}
}
int CPlayer::skor()
{
	if (skorOn == true)
	{
		m_player.setTexture(m_playerText2);
		m_spd = 4;
		m_player.setTextureRect(sf::IntRect(0, yCount * 80, 80, 80));
	}
	return skorOn;
}
int CPlayer::skorEquip()
{
	skorOn = true;
	return skorOn;
}
void CPlayer::speedDown()
{
	m_spd = 0.5;
}
void CPlayer::speedUp()
{
	m_spd = 1;
}
void CPlayer::heroTeleport()
{
	m_player.setPosition(518, 114);
}
