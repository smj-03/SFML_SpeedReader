#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class TextButton : public Button {
public:

	TextButton();

	TextButton(std::string text, sf::Vector2f size, sf::Color bgColor, sf::Color outColor, sf::Color textColor);

	void setFont(sf::Font& font);

	void setTextColor(sf::Color color);

	void setPosition(sf::Vector2f pos);

	void draw(sf::RenderWindow& window);

protected:

	sf::Text m_text;

	sf::CircleShape dot;
};