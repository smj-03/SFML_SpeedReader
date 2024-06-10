#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:

	Button();

	Button(sf::Vector2f size, sf::Color bgColor, sf::Color outColor);

	void setBackColor(sf::Color color);

	void setPosition(sf::Vector2f pos);

	void draw(sf::RenderWindow& window);

	bool isMouseOver(sf::RenderWindow& window);

	bool isClicked(sf::RenderWindow& window);

protected:

	sf::RectangleShape m_button;

	bool m_wasClicked;

};