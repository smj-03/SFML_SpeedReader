#include "Button.h"

Button::Button() {}

Button::Button(sf::Vector2f size, sf::Color bgColor, sf::Color outColor) {
	m_button.setSize(size);
	m_button.setFillColor(bgColor);
	m_button.setOutlineColor(outColor);
	m_button.setOutlineThickness(-1);
}

void Button::setBackColor(sf::Color color) {
	m_button.setFillColor(color);
}


void Button::draw(sf::RenderWindow& window) {
	window.draw(m_button);
}

void Button::setPosition(sf::Vector2f pos) {
	m_button.setPosition(pos);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::FloatRect buttonBounds = m_button.getGlobalBounds();
	return buttonBounds.contains(static_cast<sf::Vector2f>(mousePos));
}