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

	sf::RenderWindow window(sf::VideoMode(800, 450), "SFML");

	sf::RectangleShape display(sf::Vector2f(750, 350));
	display.setPosition(25, 25);
	display.setFillColor(sf::Color::Color(220, 220, 220, 100));
	display.setOutlineColor(sf::Color::Color(190, 190, 190, 190));
	display.setOutlineThickness(-1);

	sf::Text sfText;
	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "DUPA" << std::endl;
	}
	sfText.setFont(font);
	sfText.setString("Test12425125125125");
	sfText.setCharacterSize(50);
	sfText.setFillColor(sf::Color::Black);

	//casting to int to make text look sharp
	sfText.setOrigin((sf::Vector2f)((sf::Vector2i)(sfText.getGlobalBounds().getSize() / 2.f + sfText.getLocalBounds().getPosition())));
	auto displayPos = display.getPosition() + (display.getSize() / 2.f);
	sf::Vector2i intDisplayPos = (sf::Vector2i)displayPos;
	sfText.setPosition((sf::Vector2f)intDisplayPos);

	sf::RectangleShape button(sf::Vector2f(100, 25));
	button.setPosition(25, 400);
	button.setFillColor(sf::Color::Color(220, 220, 220, 100));
	button.setOutlineColor(sf::Color::Color(190, 190, 190, 190));
	button.setOutlineThickness(-1);

	sf::RectangleShape button2(sf::Vector2f(500, 25));
	button2.setPosition(150, 400);
	button2.setFillColor(sf::Color::Color(220, 220, 220, 100));
	button2.setOutlineColor(sf::Color::Color(190, 190, 190, 190));
	button2.setOutlineThickness(-1);

	sf::RectangleShape button3(sf::Vector2f(100, 25));
	button3.setPosition(675, 400);
	button3.setFillColor(sf::Color::Color(220, 220, 220, 100));
	button3.setOutlineColor(sf::Color::Color(190, 190, 190, 190));
	button3.setOutlineThickness(-1);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.draw(display);
		window.draw(button);
		window.draw(button2);
		window.draw(button3);
		window.draw(sfText);
		window.display();
	}

	return 0;
};