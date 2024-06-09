#include "Test.h"
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "TextSplitter.h"

int main() {
	//Test test;
	//test.test();

	std::string text = "raz dwa trzy cztery piec";
	TextSplitter ts = TextSplitter(text);
	wordList words = ts.getWords();
	//for (auto& word : words) {
	//	std::cout << word << std::endl;
	//}
	wordGroups groups = ts.splitText(3);
	for (auto& group : groups) {
		for (auto& word : group) {
			std::cout << word << " ";
		}
		std::cout << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");


	sf::Text sftext;
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "DUPA" << std::endl;
	}
	sftext.setFont(font);
	sftext.setString("Test");
	sftext.setCharacterSize(50);
	sftext.setFillColor(sf::Color::Black);
	sftext.setPosition(350, 270);

	sf::RectangleShape display(sf::Vector2f(600, 300));
	display.setFillColor(sf::Color::Color(220, 220, 220, 100));
	display.setPosition(100, 150);
	display.setOutlineColor(sf::Color::Color(190, 190, 190, 190));
	display.setOutlineThickness(1);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.draw(display);
		window.draw(sftext);
		window.display();
	}

	return 0;
};