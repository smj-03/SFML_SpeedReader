#include "SpeedReader.h"

SpeedReader::SpeedReader(){
	_window.create(sf::VideoMode(800, 450), "SFML", sf::Style::Titlebar | sf::Style::Close);
	//_display.loadText({ L"Welcome to Speed Reader!" });
	_text = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tincidunt orci ac sem lacinia laoreet. Sed quis aliquet libero. Nam ac tortor in eros condimentum accumsan. Aenean eleifend mi semper, faucibus est id, iaculis libero. Vestibulum laoreet nunc nec elit vehicula, vel varius augue rhoncus. Ut non auctor massa. Nulla.";
	_splitter.setText(_text);
	_splitter.chunkText(1);
	_display.loadText(_splitter.getChunks());
	_timer.restart();
	_programState = ProgramState::MainDisplay;
}

void SpeedReader::initialize() {

}

void SpeedReader::loop() {
	while (_window.isOpen()) {

		sf::Event event;
		while (_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}
		// Add settings for dark mode
		_window.clear(sf::Color::White);

		switch (_programState)
		{
		case MainDisplay:

			_window.draw(_display.getBackground());
			_display.calculateWord(_timer);
			_window.draw(_display.getWord());

			break;
		case LoadText:

			_text = L"Dupa dupa dupa";
			_splitter.setText(_text);
			_splitter.chunkText(1);
			_display.loadText(_splitter.getChunks());
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

		_window.display();
	}
}

void SpeedReader::loadResources() {

}