#include "head.h"

extern sf::RenderWindow okno;
extern State state;
extern sf::Font font;
extern sf::Texture o, x, nic;
extern std::wstring name1, name2;
extern score* Score;


void start()
{
	gui::textbox name1(font, 40, 290.f, 50.f, 270);
	name1.setFocus();
	gui::textbox name2(font, 40, 290.f, 450.f, 270.f);

	gui::button play("data/play.png", 297.5, 380);

	sf::Texture LOGO_text;
	LOGO_text.loadFromFile("data/logo.png");
	sf::Sprite LOGO;
	LOGO.setTexture(LOGO_text);
	LOGO.setPosition(120.f, 10.f);

	while (state == START)
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				state = END;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				state = END;
			if (event.type == sf::Event::TextEntered)
			{
				name1.scantext(event);
				name2.scantext(event);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
			{
				if (name1.hasFosus())
				{
					name1.removeFocus();
					name2.setFocus();
				}
				else
				{
					name1.setFocus();
					name2.removeFocus();
				}
			}
			name1.check_box(sf::Mouse::getPosition(okno), sf::Mouse::isButtonPressed(sf::Mouse::Left));
			name2.check_box(sf::Mouse::getPosition(okno), sf::Mouse::isButtonPressed(sf::Mouse::Left));
			if (play.click(sf::Mouse::getPosition(okno), sf::Mouse::isButtonPressed(sf::Mouse::Left)))
			{
				::name1 = name1.getstring();
				::name2 = name2.getstring();
				if (::name1 != L"" && ::name2 != L"")
				{
					Score = new score;
					state = PLAY;
				}
				else
				{
					error("Poadaj imona graczy !!!");
				}
			}


		} //while
		okno.clear(sf::Color::Yellow);
		/*
		sf::Time test;
		test = stoper.getElapsedTime();
		std::cout << test.asSeconds() << std::endl;
		*/
		okno.draw(LOGO);
		okno.draw(name1);
		okno.draw(name2);
		okno.draw(play);
		okno.display();
	} //while
}