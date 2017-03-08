#pragma once
#include "SFML\Graphics.hpp"

class pole : public sf::Sprite
{
public:
	sf::Texture *puste, *kolko, *krzyzyk;
	bool blokada;
	void set(sf::Texture &nic, sf::Texture &jeden, sf::Texture &dwa, float x, float y);
	void change(int stan);
	void reset();
	bool onMouseMove(sf::Vector2i pozycja);
	bool click(sf::RenderWindow &window, sf::Mouse::Button button);
	
	
	pole();
	~pole();
};

