#include "button.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

// Funkcje klasy *******************************************************

bool gui::button::onMouseMove(sf::Vector2i pozycja)
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

bool gui::button::onMouseMove(float x, float y)
{
	if (getGlobalBounds().contains(sf::Vector2f(x, y)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void gui::button::changeimg(bool stan)
{
	if (stan && stan != button::stan)
	{
		setTexture(img_1);
	}
	else if (!stan != button::stan)
	{
		setTexture(img_1);
	}

}

bool gui::button::click(sf::Vector2i pozycja, bool przycisk)
{
	if (onMouseMove(pozycja))
	{
		if (przycisk)				// sprawdzenie czy zostal wcisniety odpowiedni klawisz
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}

bool gui::button::click(float x, float y, bool przycisk)
{
	if (onMouseMove(x, y))
	{
		if (przycisk)				// sprawdzenie czy zostal wcisniety odpowiedni klawisz
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}

bool gui::button::click(sf::Vector2i pozycja)
{
	if (onMouseMove(pozycja))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool gui::button::click(float x, float y)
{
	if (onMouseMove(x, y))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void gui::button::changePosition(float x, float y)
{
	setPosition(x, y);
}

// Konstruktor, Destruktor *************************************************

gui::button::button(std::string img1, float x, float y, std::string img2) : stan(false)
{
	img_1.loadFromFile(img1);

	if (img2 == "") img2 = img1;
		img_2.loadFromFile(img2);

	setTexture(img_1);
	setPosition(sf::Vector2f(x, y));
}

gui::button::~button()
{
}

// **************************************************************************
