#pragma once
#include "SFML/Graphics.hpp"
#include <string>


namespace gui
{
	class button : public sf::Sprite
	{
	private:
		sf::Texture img_1;
		sf::Texture img_2;
		bool stan;

	public:
		bool onMouseMove(sf::Vector2i pozycja);						//Pozycja wzgledem okna programu
		bool onMouseMove(float x, float y);

		bool click(sf::Vector2i pozycja, bool przycisk);			//Pozycja wzgledem okna programu
		bool click(float x, float y, bool przycisk);

		bool click(sf::Vector2i pozycja);
		bool click(float x, float y);

		void changeimg(bool stan);
		void changePosition(float x, float y);

		//Konstruktory, destruktory
		button(std::string img1, float x = 0, float y = 0, std::string img2 = "");
		~button();
	};
}