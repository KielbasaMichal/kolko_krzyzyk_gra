#include "head.h"

extern sf::Font font;

void error(std::string co)
{
	sf::RenderWindow okno(sf::VideoMode(250, 80), "Error", sf::Style::None);

	gui::button exit_button("data/ok.png", 10.f, 10.f);
	sf::Text komunikat;
	komunikat.setCharacterSize(10);
	komunikat.setFont(font);
	komunikat.setPosition(15.f, 50.f);

	komunikat.setString(co);

	sf::RectangleShape ramka;
	ramka.setFillColor(sf::Color::Red);
	ramka.setSize(sf::Vector2f(240.f, 70.f));
	ramka.setPosition(5.f, 5.f);

	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();
			if (event.type == sf::Event::KeyPressed &&  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				okno.close();
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (exit_button.click(sf::Mouse::getPosition(okno)))
				{
					okno.close();
				} // przycisk exit_button
			}
		} //while event
		okno.clear(sf::Color(182, 0, 0));


		okno.draw(ramka);
		okno.draw(komunikat);
		okno.draw(exit_button);
		okno.display();
	}

}