﻿#include "SpeedReader.h"
#include <iostream>
#include "TextBox.h"
#include <FileExplorer.h>

SpeedReader::SpeedReader() {
	_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	_programState = ProgramState::MainDisplay;
}

void SpeedReader::initialize() {}

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

	TextBox textBox(24, sf::Color::Color(0, 0, 0, 200), true);
	textBox.setFont(arial);
	textBox.setPosition({ 30, 25 });

	TextButton clearButton = TextButton("CLEAR", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	clearButton.setFont(arial);
	clearButton.setPosition({ 25,400 });

	TextButton loadButton = TextButton("LOAD", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	loadButton.setFont(arial);
	loadButton.setPosition({ 140,400 });

	TextButton saveButton = TextButton("SAVE", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	saveButton.setFont(arial);
	saveButton.setPosition({ 255,400 });

	sf::Texture returnIcon;
	if (!returnIcon.loadFromFile("icons/return-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton returnButton = SpriteButton(returnIcon, { 0.9, 0.9 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	returnButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	returnButton.setPosition({ 750, 400 });

	FileExplorer FE;

	sf::Event event;
	sf::Uint16 lastChar = 0;
	while (_window.isOpen()) {
		while (_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_window.close();
			}

			if (event.type == sf::Event::TextEntered) {
				if (_programState == LoadText) {
					lastChar = event.text.unicode;
				}
			}	

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					if (_programState == MainDisplay)
						_programState = Settings;
					else
						_programState = MainDisplay;
				}

				if (event.key.code == sf::Keyboard::Space) {
					if (_programState == MainDisplay) {
						if (_display.isPaused())
							_display.unpause(_timer);
						else
							_display.pause(_timer);
					}
				}

				if (event.key.code == sf::Keyboard::R) {
					if (_programState == MainDisplay) {
						if (_display.isLoaded()) {
							_display.resetIndex();
							_window.draw(_display.getWord());
							_display.pause(_timer);
						}
					}
				}
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
				_display.unpause(_timer);
			}

			if (sPauseButton.isClicked(_window)) {
				_display.pause(_timer);
			}

			if (sResetButton.isClicked(_window)) {
				if (_display.isLoaded()) {
					_display.resetIndex();
					_window.draw(_display.getWord());
					_display.pause(_timer);
				}
			}

			if (settingsButton.isClicked(_window)) {
				_programState = Settings;
			}


			break;
		case LoadText:

			_window.draw(mainDisplay);
			textBox.draw(_window);
			clearButton.draw(_window);
			saveButton.draw(_window);
			loadButton.draw(_window);
			returnButton.draw(_window);

			if (event.type == sf::Event::MouseMoved) {

				handleButton(textButton);
				handleButton(clearButton);
				handleButton(saveButton);
				handleButton(loadButton);
				handleButton(returnButton);

			}

			if (clearButton.isClicked(_window)) {
				textBox.clearText();
			}

			if (saveButton.isClicked(_window)) {
				FE.SaveFileContent(textBox.getText());
			}

			if (loadButton.isClicked(_window)) {
				std::wstring filePath = FE.OpenTextFileDialog();
				if (filePath.empty()) {
					std::wcerr << L"No file selected." << std::endl;
				}

				std::wstring fileContent = FE.ReadFileContent(filePath);

				_text = fileContent;
				_splitter.setText(_text);
				_splitter.chunkText(1);
				_display.loadText(_splitter);
				_timer.restart();
				_programState = ProgramState::MainDisplay;
			}

			if (returnButton.isClicked(_window)) {
				_programState = ProgramState::MainDisplay;
			}

			if (lastChar != 0)
				textBox.typedOn(lastChar);

			lastChar = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				std::wstring newText = textBox.getText();
				if (!newText.empty()) {
					_text = newText;
					_splitter.setText(_text);
					_splitter.chunkText(1);
					_display.loadText(_splitter);
					_timer.restart();
				}
				_programState = ProgramState::MainDisplay;
			}

			//std::cout << "Loaded" << std::endl;
			//_text = L"Gdzieś jest, lecz nie wiadomo gdzie Świat w ktorym baśń ta dzieje się Maleńka pszczółka mieszka w nim Co wieść chce wsród owadów prym";
			//_splitter.setText(_text);
			//_splitter.chunkText(2);
			//_display.loadText(_splitter);
			//_programState = ProgramState::MainDisplay;

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