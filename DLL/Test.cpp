#include "Test.h"
#include <iostream>

void Test::test() {
	window.create(sf::VideoMode(800, 600), "SFML");


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}