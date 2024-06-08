#pragma once
#include "API.h"
#include <SFML/Graphics.hpp>

class EXPORT_API Test {
private:

	sf::Window window;
	sf::Event event;

public: 

	void test();
};