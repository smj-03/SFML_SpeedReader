#include <iostream>
#include <locale.h>
#include "SpeedReader.h"
#include <SFML/Graphics.hpp>
#include "TextSplitter.h"

int main() {
	
	text text = L"raz dwa trzy";
	TextSplitter splitter(text);
	splitter.chunkText(3);
	auto chunks = splitter.getChunks();
	for (auto& word : chunks) {
		std::wcout << word << std::endl;
	}
	std::cout << chunks.size();

	SpeedReader SR;
	SR.loop();

	//Test test;
	//test.test();

	//auto gray = sf::Color::Color(248, 249, 250, 255);
	//auto gray_accent = sf::Color::Color(222, 226, 230, 255);


	//std::locale::global(std::locale("en_US.UTF-8"));
	//SetConsoleOutputCP(CP_UTF8);

	//std::wstring text = L"Welcome to spreeder! To begin, you can paste the contents of what you'd like to read here, or just click the spreed! button to try it out on this. Click the settings link to change things like wpm (how fast words are flashed), chunk size(number of words flashed at";
	//TextSplitter ts = TextSplitter(text);
	//wordList wordss = ts.getWords();
	//wordList words;

	//int wwsize = wordss.size();
	//std::cout << wwsize;


	//wordGroups groups = ts.splitText(1);
	//int wsize = groups.size();
	//std::cout << wsize;
	//for (auto& group : groups) {
	//	std::wstring concat = L"";
	//	int i = 0;
	//	for (auto& word : group) {
	//		concat += word;
	//		i++;
	//		if (i < group.size())
	//			concat += L" ";
	//	}
	//	words.push_back(concat);
	//	std::wcout << concat << std::endl;
	//}

	//int size = words.size();
	//std::cout << size;


	//sf::RenderWindow window(sf::VideoMode(800, 450), "SFML", sf::Style::Titlebar | sf::Style::Close);

	//sf::RectangleShape display(sf::Vector2f(750, 350));
	//display.setPosition(25, 25);
	//display.setFillColor(sf::Color::Color(220, 220, 220, 100));
	//display.setOutlineColor(sf::Color::Color(190, 190, 190, 190));
	//display.setOutlineThickness(-1);

	//sf::Text sfText;
	//sf::Font font;

	//if (!font.loadFromFile("arial.ttf"))
	//{
	//	std::cout << "DUPA" << std::endl;
	//}
	//sfText.setFont(font);
	//sfText.setCharacterSize(50);
	//sfText.setFillColor(sf::Color::Black);


	//auto textBounds = (sf::Vector2f)((sf::Vector2i)(sfText.getGlobalBounds().getSize() / 2.f + sfText.getLocalBounds().getPosition()));
	//int height = sfText.getCharacterSize() * 3 / 4;
	//sfText.setOrigin(textBounds.x, height);
	//auto displayPos = display.getPosition() + (display.getSize() / 2.f);
	//sf::Vector2i intDisplayPos = (sf::Vector2i)displayPos;
	//sfText.setPosition((sf::Vector2f)intDisplayPos);

	//sf::CircleShape point(2, 10);
	////point.setPosition((sf::Vector2f)intDisplayPos);
	//point.setFillColor(sf::Color::Color(190, 190, 190, 190));

	//sf::RectangleShape button(sf::Vector2f(100, 25));
	//button.setPosition(25, 400);
	//button.setFillColor(gray);
	//button.setOutlineColor(gray_accent);
	//button.setOutlineThickness(-1);

	//sf::RectangleShape button2(sf::Vector2f(500, 25));
	//button2.setPosition(150, 400);
	//button2.setFillColor(gray);
	//button2.setOutlineColor(gray_accent);
	//button2.setOutlineThickness(-1);

	//sf::RectangleShape button3(sf::Vector2f(100, 25));
	//button3.setPosition(675, 400);
	//button3.setFillColor(gray);
	//button3.setOutlineColor(gray_accent);
	//button3.setOutlineThickness(-1);

	//sf::Clock timer;
	//int i = 0;

	//TextDisplay display;
	//display.loadText(words);

	//while (window.isOpen()) {
	//	sf::Event event;
	//	while (window.pollEvent(event)) {
	//		if (event.type == sf::Event::Closed) {
	//			window.close();
	//		}
	//	}

	//	window.clear(sf::Color::White);


		//if (timer.getElapsedTime().asMilliseconds() >= 1500) {
		//	if (i == size)
		//		i = 0;
		//	sfText.setString(words[i]);
		//	auto textBounds = (sf::Vector2f)((sf::Vector2i)(sfText.getGlobalBounds().getSize() / 2.f + sfText.getLocalBounds().getPosition()));
		//	sfText.setOrigin(textBounds.x, height);
		//	sfText.setPosition((sf::Vector2f)intDisplayPos);
		//	i += 1;
		//	timer.restart();
		//}
	//	if (!display.isTextLoaded())
	//		display.loadText({ L"Welcome to Speed Reader!" });
	//	
	//	window.draw(display.getBackground());

	//	display.calculateWord(timer);
	//	window.draw(display.getWord());
	//	window.draw(point);
	//	window.draw(button);
	//	window.draw(button2);
	//	window.draw(button3);
	//	window.display();
	//}
	//std::cout << (std::string)display.getWord().getString();

	return 0;
};