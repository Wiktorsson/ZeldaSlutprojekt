#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "tilemap.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
	std::vector<int>vect;
	std::ifstream file;
	file.open("maps\\map1_1-1.txt");
	std::string output;
	

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> output;
			std::cout << output;
			std::stringstream ss(output);

			int i;

			while (ss >> i)
			{
				vect.push_back(i);

				if (ss.peek() == ',')
					ss.ignore();
			}
		}
	}
	sf::Music gameMusic;
	gameMusic.openFromFile("guile.ogg");
	//gameMusic.play();
	sf::SoundBuffer doorBuffer;
	doorBuffer.loadFromFile("door.ogg");
	sf::Sound coinSound, doorSound;
	doorSound.setBuffer(doorBuffer);
	sf::Texture skor, husUte, husInne, weed, kanna;
	kanna.loadFromFile("vattenkanna.png");
	husInne.loadFromFile("hus.png");
	husUte.loadFromFile("houseSprite.png");
	skor.loadFromFile("skor.png");
	weed.loadFromFile("weed.png");
	sf::Sprite spriteSkor, spriteHus, spriteInne, weedTile, spriteCan;
	spriteCan.setTexture(kanna);
	spriteInne.setTexture(husInne);
	spriteHus.setTexture(husUte);
	spriteInne.setTextureRect(sf::IntRect(0, 0, 610, 480));
	spriteHus.setTextureRect(sf::IntRect(0, 0, 610, 480));
	spriteSkor.setTexture(skor);
	spriteSkor.setTextureRect(sf::IntRect(0, 0, 80, 80));
	weedTile.setTexture(weed);
	weedTile.setTextureRect(sf::IntRect(0, 0, 80, 80));
	spriteInne.setPosition(750, 320);
	weedTile.setPosition(640, 320);
	spriteHus.setPosition(750, 320);
	spriteSkor.setPosition(1260, 310);
	spriteCan.setPosition(1100, 310);
	bool skorEquipped = false, isPlanted = false, seedsPicked = false, vattenKanna = false;
	int environment = 1;
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Tilemap", sf::Style::Fullscreen);

	CPlayer hero((int)window.getSize().x, (int)window.getSize().y);
	

	
	int *currentTilemap = &vect[0];

	int *level2 = &vect[400];

	int *level3 = &vect[800];

	
	TileMap map;
	if (!map.load("tilemap.png", sf::Vector2u(80, 80), currentTilemap, 20, 20))
		return -1;
	TileMap map2;
	if (!map2.load("tilemap2.png", sf::Vector2u(80, 80), level2, 20, 20))
		return -1;
	TileMap map3;
	if (!map3.load("skor.png", sf::Vector2u(80, 80), level3, 20, 20))
		return -1;
		
	file.close();

	while (window.isOpen())
	{
		int xTile = (int)(hero.getPosX() / 80);
		int yTile = (int)(hero.getPosY() / 80);
		int heroTile = yTile * 20 + xTile;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			std::cout << "din tile" <<currentTilemap[heroTile] << std::endl;
			//hero.heroAttack();
			if (hero.skorOn == true)
			{
				skorEquipped = true;
			}
			std::cout << "y = " << (int)hero.getPosY() << " x =" << (int)hero.getPosX() << std::endl;
			std::cout << yTile * 20 + xTile << std::endl;
			std::cout << currentTilemap[heroTile];
			hero.skor();
			std::cout << "din x poss = " << hero.getPosX() << std::endl;
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			heroTile = (hero.getPosY() + 42) / 80 * 20 + hero.getPosX() / 80;
			if (currentTilemap[heroTile] != 1 && level2[heroTile] != 1 && level2[heroTile] != 2 && level2[heroTile] != 3 && currentTilemap[heroTile] != 5 && level2[heroTile] != 8)
			{
				hero.moveDown();

			}
			else if (currentTilemap[heroTile] == 1 && skorEquipped == true)
			{
				hero.moveDown();
			}
			if (level3[heroTile] == 2)
			{
				hero.skorEquip();
				spriteSkor.setPosition(10101010, 101010);
			}
			if (currentTilemap[heroTile] == 8)
			{
				environment = 2;
			}
			if (currentTilemap[heroTile] == 9)
			{
				environment = 1;
			}


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

			heroTile = (hero.getPosY() - 42) / 80 * 20 + hero.getPosX() / 80;
			if (currentTilemap[heroTile] != 1 && level2[heroTile] != 1 && level2[heroTile] != 2 && level2[heroTile] != 3 && currentTilemap[heroTile] != 5 && level2[heroTile] != 8 && level2[heroTile] != 5)
			{
				hero.moveUp();

			}
			else if (currentTilemap[heroTile] == 1 && skorEquipped == true)
			{
				hero.moveUp();
			}
			if (level3[heroTile] == 2)
			{
				hero.skorEquip();
				spriteSkor.setPosition(10101010, 101010);
			}
			if (currentTilemap[heroTile] == 8)
			{
				environment = 2;
				//doorSound.play();
			}
			if (currentTilemap[heroTile] == 9)
			{
				environment = 1;
			}
			if (level3[heroTile] == 3)
			{
				vattenKanna = true;
				spriteCan.setPosition(10101010, 101010);
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

			heroTile = hero.getPosY() / 80 * 20 + (hero.getPosX() - 42) / 80;
			if (currentTilemap[heroTile] != 1 && level2[heroTile] != 1 && level2[heroTile] != 2 && level2[heroTile] != 3 && currentTilemap[heroTile] != 5 && level2[heroTile] != 8)
			{
				hero.moveLeft();

			}
			else if (currentTilemap[heroTile] == 1 && skorEquipped == true)
			{
				hero.moveLeft();
			}
			if (level3[heroTile] == 2)
			{
				hero.skorEquip();
				spriteSkor.setPosition(10101010, 101010);
			}
			if (currentTilemap[heroTile] == 8)
			{
				environment = 2;
			}
			if (currentTilemap[heroTile] == 9)
			{
				environment = 1;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			heroTile = hero.getPosY() / 80 * 20 + (hero.getPosX() + 42) / 80;
			if (currentTilemap[heroTile] != 1 && level2[heroTile] != 1 && level2[heroTile] != 2 && level2[heroTile] != 3 && currentTilemap[heroTile] != 5 && level2[heroTile] != 8)
			{
				hero.moveRight();


			}
			else if (currentTilemap[heroTile] == 1 && skorEquipped == true)
			{
				hero.moveRight();
			}
			if (level3[heroTile] == 2)
			{
				hero.skorEquip();
				spriteSkor.setPosition(10101010, 101010);
			}
			
			if (currentTilemap[heroTile] == 8)
			{
				environment = 2;
			}
			if (currentTilemap[heroTile] == 9)
			{
				environment = 1;
			}
		}
		if (level2[heroTile] == 6 && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			seedsPicked = true;
		}
		if (currentTilemap[heroTile] == 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && isPlanted == false && seedsPicked == true)
		{
			
			weedTile.setTextureRect(sf::IntRect(160, 0, 80, 80));
			isPlanted = true;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isPlanted == true && vattenKanna == true)
		{
			weedTile.setTextureRect(sf::IntRect(80, 0, 80, 80));
		}
			
		
		// draw the map
		if (environment == 1)
		{
			
			hero.speedUp();
			window.clear();
			window.draw(map);
			window.draw(map3);
			window.draw(spriteHus);
			window.draw(hero.draw());
			window.draw(map2);
			window.draw(weedTile);
			window.display();

		}

		else if (environment == 2)
		{
			hero.speedDown();
			window.clear();
			window.draw(map3);
			window.draw(spriteInne);
			window.draw(spriteSkor);
			window.draw(spriteCan);
			window.draw(hero.draw());
			window.display();
		}


		
	}

	return 0;
}