#include "Klasa.h"
#include <cstdio>
#include <SFML/Graphics.hpp>

int main() {
	Klasa k;
	k.test();

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	return 0;
};