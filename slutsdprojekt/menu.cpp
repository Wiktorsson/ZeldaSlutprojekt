#include "menu.h"



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("rsfont.ttf"))
	{

	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) / 4 * 1));
	
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Yellow);
	menu[1].setString("Option");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) / 4 * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Yellow);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) / 4 * 3));
		
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (seclectedItemIndex - 1 >= 0)
	{
		menu[seclectedItemIndex].setColor(sf::Color::Yellow);
		seclectedItemIndex--;
		menu[seclectedItemIndex].setColor(sf::Color::Red);
	}
}
void Menu::moveDown()
{
	if (seclectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[seclectedItemIndex].setColor(sf::Color::Yellow);
		seclectedItemIndex++;
		menu[seclectedItemIndex].setColor(sf::Color::Red);
	}
}