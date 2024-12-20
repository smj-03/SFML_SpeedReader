#include "Button.h"

Button::Button(): m_wasClicked(false) {}

Button::Button(sf::Vector2f size, sf::Color bgColor, sf::Color outColor) {
	m_button.setSize(size);
	m_button.setFillColor(bgColor);
	m_button.setOutlineColor(outColor);
	m_button.setOutlineThickness(-1);

	m_wasClicked = false;
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

bool Button::isClicked(sf::RenderWindow & window, sf::Clock& clock) {
	if (isMouseOver(window) && clock.getElapsedTime().asMilliseconds() > 500) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_wasClicked) {
			clock.restart();
			m_wasClicked = true;
			return true;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_wasClicked = false;
		}
	}
	return false;
}
