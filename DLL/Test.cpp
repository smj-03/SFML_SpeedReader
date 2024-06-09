#include "Test.h"
#include <iostream>

void Test::test() {
	m_button.setSize({ 100,25 });
	m_button.setFillColor(sf::Color::Black);
	m_button.setPosition({ 25,400 });
}

sf::RectangleShape Test::getButton() {
	return m_button;
}