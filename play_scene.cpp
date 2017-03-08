#include "head.h"

extern sf::RenderWindow okno;
extern State state;
extern sf::Font font;
extern sf::Texture o, x, nic;
extern std::wstring name1, name2;
extern score *Score;

sf::Text vs[3];
sf::Text scoreT[3];

void setupVS();
void setupScore();

void play()
{
	int tab_odp_1[8] = { 0x20820, 0x8208, 0x2082, 0x2A000, 0xA80, 0x2A, 0x20202, 0x2220 };
	int tab_odp_2[8] = { 0x10410, 0x4104, 0x1041, 0x15000, 0x540, 0x15, 0x10101, 0x1110 };
	gui::button back("data/back.png", 0.f, 439.f);

	setupVS();
	setupScore();

	int ktory_zawodnik = 1;			//1 - zaczyna zawodnik po lewej, 2 - zaczyna zawodnik po prawej
	int co_zaznaczone = -1;
	int wynik = 0x0;				//zaznaczenia graczy
	int czy_koniec = 0x1;			//Znacznik koñca kiedy osi¹gnie wartoœæ 512 gra siê zakoñczy (9 przesuniêæ)

	sf::RectangleShape rectangle[4];
	for (int i = 0; i < 2; i++)
	{
		rectangle[i].setSize(sf::Vector2f(300, 0));
		rectangle[i].setOutlineColor(sf::Color::Black);
		rectangle[i].setOutlineThickness(4);
		rectangle[i].setPosition(250.f, 250.f + i * 100);
	}
	for (int i = 2; i < 4; i++)
	{
		rectangle[i].setSize(sf::Vector2f(0, 300));
		rectangle[i].setOutlineColor(sf::Color::Black);
		rectangle[i].setOutlineThickness(4);
		rectangle[i].setPosition(350.f + (i - 2) * 100, 150.f);
	}
	pole pole[9];
	for (int i = 0, a = 0; i < 9; i++)
	{
		pole[i].set(nic, o, x, 250.f + i % 3 * 100, 150.f + a * 100);
		if (i == 2 || i == 5 || i == 8) a++;
	}

	while (state == PLAY)
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				state = END;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				state = END;
			if (back.click(sf::Mouse::getPosition(okno), sf::Mouse::isButtonPressed(sf::Mouse::Left)))
				state = START;
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				for (int i = 0; i < 9; i++)
				{
					if (pole[i].click(okno, sf::Mouse::Left) && !pole[i].blokada)
					{
						pole[i].change(ktory_zawodnik);
						std::cout << "Pyk zaznaczono !!! \n";
						co_zaznaczone = i;

						//Sprawdzenie stanu gry i logika :D
						pole[co_zaznaczone].blokada = 1;
						if (ktory_zawodnik == 1)	wynik |= (0x20000 >> co_zaznaczone * 2);
						if (ktory_zawodnik == 2)	wynik |= (0x10000 >> co_zaznaczone * 2);

						for (int i = 0; i < 8; i++)
						{
							if ((wynik & tab_odp_1[i]) == tab_odp_1[i])
							{
								state = FINISH;
								Score->winner = &name1;
								Score->isTitle = true;
								Score->point1 += 1;
								return;
							}
						}

						for (int i = 0; i < 8; i++)
						{
							if ((wynik & tab_odp_2[i]) == tab_odp_2[i])
							{
								state = FINISH;
								Score->winner = &name2;
								Score->isTitle = true;
								Score->point2 += 1;
								return;
							}
						}

						czy_koniec <<= 1;
						if (czy_koniec == 512)
						{
							state = FINISH;
							Score->winner = new std::wstring(L"REMIS");
							Score->isTitle = false;
							return;
						}

						if (ktory_zawodnik == 1) ktory_zawodnik = 2;
						else ktory_zawodnik = 1;
					}
				}
			}

		} //while
		okno.clear(sf::Color::Yellow);

		if (ktory_zawodnik == 1) {
			vs[0].setFillColor(sf::Color::Red);
			vs[0].setStyle(sf::Text::Underlined);
			vs[2].setFillColor(sf::Color::Black);
			vs[2].setStyle(sf::Text::Regular);
		}
		else
		{
			vs[0].setFillColor(sf::Color::Black);
			vs[0].setStyle(sf::Text::Regular);
			vs[2].setFillColor(sf::Color::Red);
			vs[2].setStyle(sf::Text::Underlined);
		}

		for (int i = 0; i < 9; i++)
		{
			okno.draw(pole[i]);
		}
		for (int i = 0; i < 4; i++)
		{
			okno.draw(rectangle[i]);
		}
		for (int i = 0; i < 3; i++) 
		{
			okno.draw(vs[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			okno.draw(scoreT[i]);
		}
		okno.draw(back);
		okno.display();
	} //while
}

void setupVS()
{
	for (int i = 0; i < 3; i++)
	{
		vs[i].setFont(font);
		vs[i].setCharacterSize(50);
		vs[i].setFillColor(sf::Color::Black);
	}

	vs[0].setString(name1);
	vs[1].setString(" vs ");
	vs[2].setString(name2);

	float text_x = (WIDTH - vs[1].getLocalBounds().width) / 2;
	vs[0].setPosition(text_x - vs[0].getLocalBounds().width, 10.f);
	vs[1].setPosition(text_x, 10.f);
	vs[2].setPosition(text_x + vs[1].getLocalBounds().width, 10.f);
}

void setupScore()
{
	for (int i = 0; i < 3; i++)
	{
		scoreT[i].setFont(font);
		scoreT[i].setCharacterSize(50);
		scoreT[i].setFillColor(sf::Color::Black);
	}

	scoreT[0].setString(std::to_string(Score->point1));
	scoreT[1].setString("     :     ");
	scoreT[2].setString(std::to_string(Score->point2));

	float text_x = (WIDTH - scoreT[1].getLocalBounds().width) / 2;
	scoreT[0].setPosition(text_x - scoreT[0].getLocalBounds().width, 65.f);
	scoreT[1].setPosition(text_x, 65.f);
	scoreT[2].setPosition(text_x + scoreT[1].getLocalBounds().width, 65.f);
}
