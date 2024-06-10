#include "TextButton.h"
#include <iostream>

TextButton::TextButton() {};

TextButton::TextButton(std::string text, sf::Vector2f size, sf::Color bgColor, sf::Color outColor, sf::Color textColor) : Button(size, bgColor, outColor) {

	m_text.setString(text);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(20);
	m_text.setLetterSpacing(1.5);

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

	sf::Vector2f textBounds = (sf::Vector2f)((sf::Vector2i)(m_text.getGlobalBounds().getSize() / 2.f + m_text.getGlobalBounds().getPosition() / 2.f));
	m_text.setOrigin(textBounds);
	m_text.setPosition({ (float)xPos,(float)yPos - 2});
}

void TextButton::draw(sf::RenderWindow& window) {
	window.draw(m_button);
	window.draw(m_text);
}
