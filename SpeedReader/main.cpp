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
	sftext.setCharacterSize(20);
	sftext.setFillColor(sf::Color::White);
	sftext.move(0,0);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.draw(sftext);
		window.display();
	}

	return 0;
};