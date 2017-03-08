#include "pole.h"
#include "SFML\Graphics.hpp"
#include <iostream>


void pole::set(sf::Texture &nic, sf::Texture &jeden, sf::Texture &dwa, float x, float y)
{
	puste =& nic;
	kolko =& jeden;
	krzyzyk =& dwa;

	setTexture(*puste);
	setPosition(x, y);
}

void pole::change(int stan)
{
	if (stan == 0) setTexture(*puste);
	if (stan == 1) setTexture(*kolko);
	if (stan == 2) setTexture(*krzyzyk);
}

void pole::reset()
{
	if (blokada) return;
	setTexture(*puste);
}

bool pole::onMouseMove(sf::Vector2i pozycja)
{
	if (getGlobalBounds().contains((sf::Vector2f) pozycja))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool pole::click(sf::RenderWindow &window, sf::Mouse::Button button)
{
	if (sf::Mouse::isButtonPressed(button) && onMouseMove(sf::Mouse::getPosition(window)))				// sprawdzenie czy zostal wcisniety odpowiedni klawisz i czy w³aœnie nad danym polem
	{
		while (sf::Mouse::isButtonPressed(button)) { }			//czekamy az klawisz zostanie puszczony
		if (onMouseMove(sf::Mouse::getPosition(window)))
		{
			return 1;
		}
	}
	
	return 0;
}

// Konstruktor, destruktor
pole::pole()
{
	blokada = 0;
}

pole::~pole()
{
}
