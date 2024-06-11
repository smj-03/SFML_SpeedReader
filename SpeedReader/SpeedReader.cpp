#include "SpeedReader.h"
#include <iostream>
#include "TextBox.h"
#include <FileExplorer.h>

SpeedReader::SpeedReader() {
	_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	_programState = ProgramState::MainDisplay;
}

void SpeedReader::initialize() {}

void SpeedReader::loop() {

	sf::Font arialbd;
	arialbd.loadFromFile("fonts/arialbd.ttf");

	sf::RectangleShape mainDisplay(sf::Vector2f(750, 350));
	mainDisplay.setPosition(25, 25);
	mainDisplay.setFillColor(sf::Color::Color(248, 249, 250, 255));
	mainDisplay.setOutlineColor(sf::Color::Color(222, 226, 230, 255));
	mainDisplay.setOutlineThickness(-1);
	_display.setParent(mainDisplay);

	TextButton textButton = TextButton("TEXT", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	textButton.setFont(arialbd);
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
	textBox.setFont(arialbd);
	textBox.setPosition({ 30, 25 });

	TextButton clearButton = TextButton("CLEAR", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	clearButton.setFont(arialbd);
	clearButton.setPosition({ 25,400 });

	TextButton loadButton = TextButton("LOAD", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	loadButton.setFont(arialbd);
	loadButton.setPosition({ 140,400 });

	TextButton saveButton = TextButton("SAVE", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	saveButton.setFont(arialbd);
	saveButton.setPosition({ 255,400 });

	sf::Texture returnIcon;
	if (!returnIcon.loadFromFile("icons/return-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton returnButton = SpriteButton(returnIcon, { 0.9, 0.9 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	returnButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	returnButton.setPosition({ 750, 400 });


	// SETTINGS 
	// zrobic klase QuickText : sf::Text

	// WPM

	sf::Text sWPM;
	sWPM.setFont(arialbd);
	sWPM.setCharacterSize(25);
	sWPM.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sWPM.setPosition({ 75, 75 });
	sWPM.setString("WORDS PER MINUTE:");

	sf::Text sWPMNum;
	sWPMNum.setFont(arialbd);
	sWPMNum.setCharacterSize(25);
	sWPMNum.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sWPMNum.setPosition({ 350, 75 });
	sWPMNum.setString("400");

	Button tempButt1({ 25, 12 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	tempButt1.setPosition({ 400 , 78 });

	Button tempButt2({ 25, 12 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	tempButt2.setPosition({ 400 , 91 });

	// CHUNKS

	sf::Text sChunks;
	sChunks.setFont(arialbd);
	sChunks.setCharacterSize(25);
	sChunks.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sChunks.setPosition({ 75, 125 });
	sChunks.setString("CHUNKS:");

	sf::Text sChunksNum;
	sChunksNum.setFont(arialbd);
	sChunksNum.setCharacterSize(25);
	sChunksNum.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sChunksNum.setPosition({ 200, 125 });
	sChunksNum.setString("2");

	Button tempButt3({ 25, 12 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	tempButt3.setPosition({ 225, 128 });

	Button tempButt4({ 25, 12 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	tempButt4.setPosition({ 225, 141 });

	// CHAR SIZE

	sf::Text sCharSize;
	sCharSize.setFont(arialbd);
	sCharSize.setCharacterSize(25);
	sCharSize.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sCharSize.setPosition({ 75, 200 });
	sCharSize.setString("CHARACTER SIZE:");

	sf::Text sCharSizeNum;
	sCharSizeNum.setFont(arialbd);
	sCharSizeNum.setCharacterSize(25);
	sCharSizeNum.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sCharSizeNum.setPosition({ 310, 200 });
	sCharSizeNum.setString("24");

	Button tempButt5({ 25, 12 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	tempButt5.setPosition({ 350, 203 });

	Button tempButt6({ 25, 12 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	tempButt6.setPosition({ 350, 216 });

	// FONT

	sf::Text sFont;
	sFont.setFont(arialbd);
	sFont.setCharacterSize(25);
	sFont.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sFont.setPosition({ 75, 250 });
	sFont.setString("FONT:");

	sf::Font arial;
	arial.loadFromFile("./fonts/arial.ttf");
	TextButton sArial("Arial", {100, 25}, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sArial.setFont(arialbd);
	sArial.setPosition({ 170, 254 });

	sf::Font times;
	times.loadFromFile("./fonts/timesbd.ttf");
	TextButton sTimes("Times New Roman", { 200, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sTimes.setFont(times);
	sTimes.setPosition({ 290, 254 });


	sf::Font comic;
	comic.loadFromFile("./fonts/comicbd.ttf");
	TextButton sComic("Comic Sans MS", { 200, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sComic.setFont(comic);
	sComic.setPosition({ 510, 254 });


	// MODE
	sf::Text sMode;
	sMode.setFont(arialbd);
	sMode.setCharacterSize(25);
	sMode.setFillColor(sf::Color::Color(0, 0, 0, 200));
	sMode.setPosition({ 75, 325 });
	sMode.setString("MODE:");

	TextButton sLight("LIGHT", { 100, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sLight.setFont(arialbd);
	sLight.setPosition({ 180, 329 });

	TextButton sDark("DARK", { 100, 25 }, sf::Color::Color(0, 0, 0, 215), sf::Color::Color(0, 0, 0, 240), sf::Color::Color(255, 255, 255, 230));
	sDark.setFont(arialbd);
	sDark.setPosition({ 290, 329 });

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
				_splitter.chunkText(2);
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

			tempButt1.draw(_window);
			tempButt2.draw(_window);
			tempButt3.draw(_window);
			tempButt4.draw(_window);
			tempButt5.draw(_window);
			tempButt6.draw(_window);

			sArial.draw(_window);
			sTimes.draw(_window);
			sComic.draw(_window);

			sLight.draw(_window);
			sDark.draw(_window);

			if (event.type == sf::Event::MouseMoved) {

				handleButton(tempButt1);
				handleButton(tempButt2);
				handleButton(tempButt3);
				handleButton(tempButt4);
				handleButton(tempButt5);
				handleButton(tempButt6);
				handleButton(sArial);
				handleButton(sTimes);
				handleButton(sComic);
				handleButton(returnButton);
				//handleButton(sDark);
				handleButton(sLight);

			}

			_window.draw(sWPMNum);
			_window.draw(sWPM);

			_window.draw(sChunks);
			_window.draw(sChunksNum);

			_window.draw(sCharSize);
			_window.draw(sCharSizeNum);
			_window.draw(sFont);
			_window.draw(sMode);
			
			returnButton.draw(_window);

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