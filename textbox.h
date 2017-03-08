#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

namespace gui
{
	class textbox : public sf::Drawable
	{
	private:
		sf::Font sf_font;
		sf::Text sf_text;
		bool stan;
		std::wstring text;
		sf::RectangleShape background;
		sf::RectangleShape pos;
		size_t amount;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		void scantext(sf::Event &event);

		bool hasFosus();
		void setFocus(sf::Color color = sf::Color::Black);
		void removeFocus();

		std::wstring getstring();
		void textbox::check_box(sf::Vector2i pozycja, bool przycisk, sf::Color color = sf::Color::Black);
		void textbox::check_box(sf::Vector2i pozycja, sf::Color color = sf::Color::Black);
		//Konstruktory, destruktory
		textbox(std::string font, int size, float width, float x = 0, float y = 0, sf::Color color = sf::Color::Black, size_t amount = 10);
		textbox(sf::Font &font, int size, float width, float x = 0, float y = 0, sf::Color color = sf::Color::Black, size_t amount = 10);
		~textbox();

	};
}