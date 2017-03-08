#include "SFML/Graphics.hpp"
#include "head.h"


sf::RenderWindow okno(sf::VideoMode(WIDTH, HEIGHT), "Kó³ko i Krzy¿yk");
State state = START;
sf::Font font;
sf::Texture o, x, nic;

std::wstring name1, name2;

score* Score;

int main()
{
	sf::Clock stoper;
	nic.loadFromFile("data/nic.png");
	o.loadFromFile("data/o.png");
	x.loadFromFile("data/x.png");
	font.loadFromFile("data/arial.ttf");


	while (state != END)
	{
		switch (state)
		{
		case START:
			start();
			break;
		case PLAY:
			play();
			break;
		case FINISH:
			finish();
			break;
		}
	}
	

}