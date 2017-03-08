#include "head.h"

extern sf::RenderWindow okno;
extern State state;
extern sf::Font font;
extern sf::Texture o, x, nic;
extern std::wstring name1, name2;
extern score* Score;


void finish()
{
	gui::button menu("data/menu.png", 0.f, 403.f);
	gui::button graj_ponownie("data/again.png", 595.f, 403.f);

	sf::Text wynik[2];
	for(int i = 0; i < 2; i++)
	{
		wynik[i].setFont(font);
		wynik[i].setFillColor(sf::Color::Black);
		wynik[i].setCharacterSize(100);
	}
	wynik[0].setString(Score->title);
	wynik[1].setString(*(Score->winner));

	wynik[0].setPosition((WIDTH - wynik[0].getLocalBounds().width) / 2, 40.f);
	wynik[1].setPosition((WIDTH - wynik[1].getLocalBounds().width) / 2, 180.f);
	
	while (state == FINISH)
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				state = END;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				state = END;
			if (menu.click(sf::Mouse::getPosition(okno), sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				state = START;
			}
			if (graj_ponownie.click(sf::Mouse::getPosition(okno), sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				state = PLAY;
			}


		} //while
		okno.clear(sf::Color::Yellow);
		if(Score->isTitle)
		{
			okno.draw(wynik[0]);
		}
		okno.draw(wynik[1]);
		okno.draw(menu);
		okno.draw(graj_ponownie);
		okno.display();
	} //while
}