#include "SpeedReader.h"
#include <iostream>

SpeedReader::SpeedReader() {
	_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	_programState = ProgramState::MainDisplay;
}

void SpeedReader::initialize() {

}

void SpeedReader::loop() {

	sf::Font arial;
	arial.loadFromFile("fonts/arialbd.ttf");

	sf::RectangleShape mainDisplay(sf::Vector2f(750, 350));
	mainDisplay.setPosition(25, 25);
	mainDisplay.setFillColor(sf::Color::Color(248, 249, 250, 255));
	mainDisplay.setOutlineColor(sf::Color::Color(222, 226, 230, 255));
	mainDisplay.setOutlineThickness(-1);
	_display.setParent(mainDisplay);

	TextButton textButton = TextButton("TEXT", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	textButton.setFont(arial);
	textButton.setPosition({ 25,400 });

	sf::Texture resetIcon;
	if (!resetIcon.loadFromFile("icons/reset-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton sResetButton = SpriteButton(resetIcon, { 0.55, 0.55 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	sResetButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	sResetButton.setPosition({ 140, 400 });

	sf::Texture playIcon;
	if (!playIcon.loadFromFile("icons/play-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton sPlayButton = SpriteButton(playIcon, { 0.6, 0.6 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	sPlayButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	sPlayButton.setPosition({ 180, 400 });
	//sPlayButton.moveSprite({ 1, 0 });

	sf::Texture pauseIcon;
	if (!pauseIcon.loadFromFile("icons/pause-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton sPauseButton = SpriteButton(pauseIcon, { 0.6, 0.6 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	sPauseButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	sPauseButton.setPosition({ 220, 400 });

	sf::Texture settingsIcon;
	if (!settingsIcon.loadFromFile("icons/setting-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton settingsButton = SpriteButton(settingsIcon, { 0.75, 0.75 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	settingsButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	settingsButton.setPosition({ 750, 400 });


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

			_window.draw(mainDisplay);
			textButton.draw(_window);
			sPlayButton.draw(_window);
			sPauseButton.draw(_window);
			sResetButton.draw(_window);
			settingsButton.draw(_window);

			if (!_display.isPaused())
				_display.calculateWord(_timer);
			_window.draw(_display.getWord());

			if (event.type == sf::Event::MouseMoved) {

				handleButton(textButton);
				handleButton(sResetButton);
				handleButton(sPlayButton);
				handleButton(sPauseButton);
				handleButton(settingsButton);

			}

			if (textButton.isClicked(_window)) {
				_display.pause(_timer);
				_programState = LoadText;
			}

			if (sPlayButton.isClicked(_window)) {
				if(_display.isLoaded())
					_display.unpause(_timer);
			}

			if (sPauseButton.isClicked(_window)) {
				_display.pause(_timer);
			}

			if (sResetButton.isClicked(_window)) {
				if(_display.isLoaded())
					_display.resetIndex();
					_window.draw(_display.getWord());
					_timer.restart();
			}

			if (settingsButton.isClicked(_window)) {
				_programState = Settings;
			}


			break;
		case LoadText:

			_window.draw(mainDisplay);
			std::cout << "Loaded" << std::endl;
			_text = L"Gdzieś jest, lecz nie wiadomo gdzie Świat w ktorym baśń ta dzieje się Maleńka pszczółka mieszka w nim Co wieść chce wsród owadów prym";
			_splitter.setText(_text);
			_splitter.chunkText(2);
			_display.loadText(_splitter);
			_programState = ProgramState::MainDisplay;

			break;
		case Settings:

			break;
		default:
			break;
		}

		_window.display();
	}
}

void SpeedReader::handleButton(Button& button) {
	if (button.isMouseOver(_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
	}
	else {
		button.setBackColor(sf::Color::Color(248, 249, 250, 255));
	}
}

void SpeedReader::handleButton(TextButton& button) {
	if (button.isMouseOver(_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
		button.setTextColor(sf::Color::Color(0, 0, 0, 180));
	}
	else {
		button.setBackColor(sf::Color::Color(248, 249, 250, 255));
		button.setTextColor(sf::Color::Color(0, 0, 0, 160));
	}
}

void SpeedReader::handleButton(SpriteButton& button) {
	if (button.isMouseOver(_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
		button.setSpriteColor(sf::Color::Color(0, 0, 0, 180));
	}
	else {
		button.setBackColor(sf::Color::Color(248, 249, 250, 255));
		button.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	}
}


void SpeedReader::loadResources() {

}