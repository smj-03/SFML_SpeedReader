#include "TextButton.h"
#include <iostream>

TextButton::TextButton() {};

TextButton::TextButton(std::string text, sf::Vector2f size, sf::Color bgColor, sf::Color outColor, sf::Color textColor) {

	m_text.setString(text);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(24);

	m_button.setSize(size);
	m_button.setFillColor(bgColor);
	m_button.setOutlineColor(outColor);
	m_button.setOutlineThickness(-1);

	dot.setRadius(1);
	dot.setPointCount(30);
	dot.setFillColor(textColor);
}

void TextButton::setFont(sf::Font& font) {
	m_text.setFont(font);
}

void TextButton::setTextColor(sf::Color color) {
	m_text.setFillColor(color);
}

void TextButton::setPosition(sf::Vector2f pos) {
	m_button.setPosition(pos);

	int xPos = pos.x + (m_button.getGlobalBounds().width / 2);
	int yPos = pos.y + (m_button.getGlobalBounds().height / 2);

	//sf::Vector2f textBounds = (sf::Vector2f)((sf::Vector2i)(m_text.getGlobalBounds().getSize() / 2.f + m_text.getLocalBounds().getPosition()));
	sf::Vector2f textBounds = m_text.getGlobalBounds().getSize();
	std::cout << "Bounds: " << textBounds.x << " " << textBounds.y << std::endl;
	m_text.setOrigin(textBounds);
	m_text.setPosition({ (float)xPos,(float)yPos });

	dot.setPosition({ (float)xPos,(float)yPos });
}

void TextButton::draw(sf::RenderWindow& window) {
	window.draw(m_button);
	window.draw(m_text);
	window.draw(dot);
}
