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

void Button::setPosition(sf::Vector2f pos) {
	m_button.setPosition(pos);
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(m_button);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = m_button.getPosition().x;
	float btnPosY = m_button.getPosition().y;

	float btnxPosWidth = m_button.getPosition().x + m_button.getLocalBounds().width;
	float btnyPosHeight = m_button.getPosition().y + m_button.getLocalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
		return true;
	}
	else {
		return false;
	}
}