#pragma once
#include <SFML/Graphics.hpp>

class  Button {
public:
	Button();

	Button(std::string text, sf::Vector2f size, sf::Color bgColor, sf::Color outColor, sf::Color textColor);

	void setFont(sf::Font& font);

	void setBackColor(sf::Color color);

	void setTextColor(sf::Color color);

	void setPosition(sf::Vector2f pos);

	void draw(sf::RenderWindow& window);

	bool isMouseOver(sf::RenderWindow& window);

	sf::RectangleShape getButton();

private:

	sf::RectangleShape m_button;
	sf::Text m_text;
};