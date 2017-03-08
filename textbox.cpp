#include "textbox.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

// Funkcje klasy ****************************************************************

void gui::textbox::scantext(sf::Event &event)		//Event danego okna uruchamiany w: if (event.type == sf::Event::TextEntered)
{
	if (!stan)
		return;
	wchar_t letter = event.text.unicode;
	if (letter == 8 || letter == 32 || letter == 322 || (letter >= 48 && letter <= 57) || (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
	{
		if (letter == 8)
		{
			if (text.empty())
				return;
			text.erase(text.size()-1,1);
		}
		else
		{
			if(text.size() + 1 <= amount){
				text += letter;
			}
		}
		sf_text.setString(text);
		sf::Vector2f poz = sf_text.findCharacterPos(text.size());
		pos.setPosition(poz.x, poz.y + sf_text.getCharacterSize() - 2);
	}		
	std::cout << (int)letter << std::endl;
	return;
}


bool gui::textbox::hasFosus() 
{
	return stan;
}

void gui::textbox::setFocus(sf::Color color)
{
	stan = true;
	background.setOutlineColor(color);
}

void gui::textbox::removeFocus()
{
	stan = false;
	background.setOutlineColor(background.getFillColor());
}

std::wstring gui::textbox::getstring()
{
	return text;
}

void gui::textbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(sf_text);
	if (stan)
		target.draw(pos);
}

void gui::textbox::check_box(sf::Vector2i pozycja, bool przycisk, sf::Color color)
{
	if (background.getGlobalBounds().contains((sf::Vector2f) pozycja))
	{
		if (przycisk)
		{
			stan = true;
			background.setOutlineColor(color);
		}
	}
	else
	{
		if (przycisk)
		{
			stan = false;
			background.setOutlineColor(background.getFillColor());
		}
	}

}

void gui::textbox::check_box(sf::Vector2i pozycja, sf::Color color)
{
	if (background.getGlobalBounds().contains((sf::Vector2f) pozycja))
	{
		stan = true;
		background.setOutlineColor(color);
	}
	else
	{
		stan = false;
		background.setOutlineColor(background.getFillColor());
	}

}

//Konstruktory,destruktory ********************************************************

gui::textbox::textbox(std::string font, int size, float width, float x, float y, sf::Color textColor, size_t amount)
{
	stan = false;
	gui::textbox::amount = amount;
	sf_font.loadFromFile(font);
	sf_text.setFont(sf_font);
	
	sf_text.setFillColor(textColor);
	pos.setFillColor(textColor);
	background.setFillColor(sf::Color::White);
	background.setOutlineThickness(4.f);
	
	sf_text.setCharacterSize(size);
	background.setSize(sf::Vector2f( width, size * 1.25f));
	pos.setSize(sf::Vector2f(8.f, 4.f));
	
	background.setPosition(x-size/6, y);
	sf_text.setPosition(x, y);
	sf::Vector2f poz = sf_text.findCharacterPos(text.size());
	pos.setPosition(poz.x, poz.y + size - 2);
}

gui::textbox::textbox(sf::Font &font, int size, float width, float x, float y, sf::Color color, size_t amount)
{
	stan = false;
	gui::textbox::amount = amount;
	sf_font = font;
	sf_text.setFont(sf_font);

	sf_text.setFillColor(color);
	pos.setFillColor(color); 
	background.setFillColor(sf::Color::White);
	background.setOutlineThickness(4.f);

	sf_text.setCharacterSize(size);
	background.setSize(sf::Vector2f(width, size * 1.25f));
	pos.setSize(sf::Vector2f(8.f, 4.f));

	background.setPosition(x - size / 6, y);
	sf_text.setPosition(x, y);
	sf::Vector2f poz = sf_text.findCharacterPos(text.size());
	pos.setPosition(poz.x, poz.y + size - 2);
}
gui::textbox::~textbox()
{
	
}