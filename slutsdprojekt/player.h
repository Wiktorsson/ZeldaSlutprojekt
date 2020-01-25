#pragma once
#include <SFML\Graphics.hpp>

class CPlayer
{


public:
	CPlayer(int, int);
	sf::Sprite draw();
	float bottom, top, left, right;
	int  yCount, skor(), skorEquip();
	bool skorOn;
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void heroIdle();
	void speedUp();
	void speedDown();
	void heroTeleport();
	int getPosX();
	int getPosY();
	void heroAttack();



	~CPlayer();
private:
	float m_spriteX, m_spriteY, m_counter, m_Ccounter, m_spd;
	sf::Texture m_playerText;
	sf::Sprite m_player;
	sf::IntRect rectHero;
	sf::Texture m_playerText2;


};





