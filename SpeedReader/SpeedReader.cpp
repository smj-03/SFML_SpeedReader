#include "SpeedReader.h"
#include "Button.h"
#include <iostream>

SpeedReader::SpeedReader() {
	_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	_programState = ProgramState::MainDisplay;
}

void SpeedReader::initialize() {

}

void SpeedReader::loop() {

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	Button firstButton = Button({ 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	firstButton.setPosition({ 25,400 });


	Button secondButton = Button({ 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	secondButton.setPosition({ 150 ,400 });

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
			firstButton.draw(_window);
			secondButton.draw(_window);

			if (firstButton.isMouseOver(_window)) 
				firstButton.setBackColor(sf::Color::Color(240, 241, 242, 255));
			else
				firstButton.setBackColor(sf::Color::Color(248, 249, 250, 255));
		

			if (secondButton.isMouseOver(_window)) 
				secondButton.setBackColor(sf::Color::Color(240, 241, 242, 255));
			else 
				secondButton.setBackColor(sf::Color::Color(248, 249, 250, 255));
			

			if (firstButton.isClicked(_window)) {
				_display.pause(_timer);
				_programState = LoadText;
			}

			if (secondButton.isClicked(_window)) {
				_display.unpause(_timer);
			}

			break;
		case LoadText:

			std::cout << "Loaded" << std::endl;
			_text = L"Gdzieś jest, lecz nie wiadomo gdzie Świat w ktorym baśń ta dzieje się Maleńka pszczółka mieszka w nim Co wieść chce wsród owadów prym";
			_splitter.setText(_text);
			_splitter.chunkText(2);
			_display.loadText(_splitter);
			_programState = ProgramState::MainDisplay;

			break;
		case Setting:

			break;
		default:
			break;
		}

		_window.display();
	}
}

void SpeedReader::loadResources() {

}