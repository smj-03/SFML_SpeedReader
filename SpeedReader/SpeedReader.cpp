#include "SpeedReader.h"
#include "Button.h"
#include <iostream>

SpeedReader::SpeedReader() {
	_window.create(sf::VideoMode(800, 450), "SFML", sf::Style::Titlebar | sf::Style::Close);
	//_display.loadText({ L"Welcome to Speed Reader!" });
	//_text = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tincidunt orci ac sem lacinia laoreet. Sed quis aliquet libero. Nam ac tortor in eros condimentum accumsan. Aenean eleifend mi semper, faucibus est id, iaculis libero. Vestibulum laoreet nunc nec elit vehicula, vel varius augue rhoncus. Ut non auctor massa. Nulla.";
	//_splitter.setText(_text);

	// Do zrobienia zeby duze chunki sie miescily
	//_splitter.chunkText(1);
	//_display.loadText(_splitter);
	//_timer.restart();
	_programState = ProgramState::MainDisplay;
}

void SpeedReader::initialize() {

}

void SpeedReader::loop() {

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	Button textButton = Button({ 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	textButton.setPosition({ 25,400 });


	Button playButton = Button({ 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	playButton.setPosition({ 150 ,400 });

	bool textButtonAction = false;
	bool playButtonAction = false;

	while (_window.isOpen()) {
		sf::Event event;
		while (_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}
		// Add settings for dark mode
		_window.clear(sf::Color::White);

		switch (_programState) {
		case MainDisplay:

			_window.draw(_display.getBackground());
			if (!_display.isPaused())
				_display.calculateWord(_timer);
			_window.draw(_display.getWord());
			textButton.draw(_window);
			playButton.draw(_window);

			if (sf::Event::MouseMoved) {
				if (textButton.isMouseOver(_window)) {
					textButton.setBackColor(sf::Color::Color(240, 241, 242, 255));
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !textButtonAction) {
						_programState = LoadText;
						textButtonAction = true;
					}
				}
				else {
					textButton.setBackColor(sf::Color::Color(248, 249, 250, 255));
				}

				if (playButton.isMouseOver(_window)) {
					playButton.setBackColor(sf::Color::Color(240, 241, 242, 255));
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !playButtonAction) {
						_display.pauseUnpause();
						playButtonAction = true;
					}
				}
				else {
					playButton.setBackColor(sf::Color::Color(248, 249, 250, 255));
				}
			}

			break;
		case LoadText:

			std::cout << "DUAPAAAA" << std::endl;
			_text = L"Raz dwa trzy cztery";
			_splitter.setText(_text);
			_splitter.chunkText(1);
			_display.loadText(_splitter);
			_timer.restart();
			_programState = ProgramState::MainDisplay;

			break;
		case Setting:

			break;
		default:
			break;
		}

		//window.draw(point);
		//window.draw(button);
		//window.draw(button2);
		//window.draw(button3);
		//btn1.draw(_window);
		//_window.draw(btn1.getButton());

		_window.display();
	}
}

void SpeedReader::loadResources() {

}