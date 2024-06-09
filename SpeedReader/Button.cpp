#include "Button.h"

Button::Button() {}

Button::Button(std::string text, sf::Vector2f size, sf::Color bgColor, sf::Color outColor, sf::Color textColor) {

	m_text.setString(text);
	m_text.setFillColor(textColor);
	m_text.setCharacterSize(30);

	m_button.setSize(size);
	m_button.setFillColor(bgColor);

}

void Button::setFont(sf::Font& font) {
	m_text.setFont(font);
}

void Button::setBackColor(sf::Color color) {
	m_button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	m_text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {
	m_button.setPosition(pos);

	float xPos = (pos.x + (m_button.getGlobalBounds().width / 2) - (m_text.getGlobalBounds().width / 2));
	float yPos = (pos.y + (m_button.getGlobalBounds().height / 2) - (m_text.getGlobalBounds().height / 2));

	m_text.setPosition({  xPos, yPos});
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(m_button);
	window.draw(m_text);
}

sf::RectangleShape Button::getButton() {
	return m_button;
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