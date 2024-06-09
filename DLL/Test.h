#pragma once
#include "API.h"
#include <SFML/Graphics.hpp>

class EXPORT_API Test {
private:
	sf::RectangleShape m_button;
public: 
	void test();
	sf::RectangleShape getButton();
};