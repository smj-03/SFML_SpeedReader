#include "SpeedReader.h"
#include <iostream>
#include "TextBox.h"
#include <FileExplorer.h>

SpeedReader::SpeedReader() {
	m_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	m_programState = ProgramState::MainDisplay;

	sf::Image icon;
	icon.loadFromFile("icons/logo.png");
	m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

}

void SpeedReader::initialize() {}

void SpeedReader::loop() {

	m_display.setFont(arial);
	m_display.setWord("Welcome to Speed Reader!");

	sf::RectangleShape mainDisplay(sf::Vector2f(750, 350));
	mainDisplay.setPosition(25, 25);
	mainDisplay.setFillColor(sf::Color::Color(248, 249, 250, 255));
	mainDisplay.setOutlineColor(sf::Color::Color(222, 226, 230, 255));
	mainDisplay.setOutlineThickness(-1);

	TextButton textButton = TextButton("TEXT", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	textButton.setFont(arialbd);
	textButton.setPosition({ 25,400 });

	sf::Texture resetIcon;
	if (!resetIcon.loadFromFile("icons/reset-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton sResetButton = SpriteButton(resetIcon, { 0.55f, 0.55f}, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	sResetButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	sResetButton.setPosition({ 140, 400 });

	sf::Texture playIcon;
	if (!playIcon.loadFromFile("icons/play-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton sPlayButton = SpriteButton(playIcon, { 0.6f, 0.6f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	sPlayButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	sPlayButton.setPosition({ 180, 400 });
	//sPlayButton.moveSprite({ 1, 0 });

	sf::Texture pauseIcon;
	if (!pauseIcon.loadFromFile("icons/pause-icon.png")) {
		std::cout << "pupa";
	}
	SpriteButton sPauseButton = SpriteButton(pauseIcon, { 0.6f, 0.6f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
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
	SpriteButton returnButton = SpriteButton(returnIcon, { 0.9f, 0.9f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	returnButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	returnButton.setPosition({ 750, 400 });

	sf::Text mWPMNum;
	mWPMNum.setFont(arialbd);
	mWPMNum.setCharacterSize(20);
	mWPMNum.setFillColor(sf::Color::Color(0, 0, 0, 200));
	mWPMNum.setPosition({ 652, 400 });
	mWPMNum.setString(std::to_string(m_settings.getWPM()));

	sf::Text mWPM;
	mWPM.setFont(arialbd);
	mWPM.setCharacterSize(20);
	mWPM.setFillColor(sf::Color::Color(0, 0, 0, 160));
	mWPM.setPosition({ 690, 400 });
	mWPM.setString("WPM");


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

	TextButton sArial("Arial", { 100, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sArial.setFont(arialbd);
	sArial.setPosition({ 170, 254 });

	TextButton sTimes("Times New Roman", { 200, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sTimes.setFont(timesbd);
	sTimes.setPosition({ 290, 254 });

	TextButton sComic("Comic Sans MS", { 200, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 200));
	sComic.setFont(comicbd);
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
	while (m_window.isOpen()) {
		while (m_window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				m_window.close();
			}

			if (event.type == sf::Event::TextEntered) {
				if (m_programState == LoadText) {
					lastChar = event.text.unicode;
				}
			}

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape) {
					if (m_programState == MainDisplay) {
						m_programState = SettingsMenu;
						m_display.pause(m_timer);
					}
					else
						m_programState = MainDisplay;
				}

				if (event.key.code == sf::Keyboard::Space) {
					if (m_programState == MainDisplay) {
						if (m_display.isPaused())
							m_display.unpause(m_timer);
						else
							m_display.pause(m_timer);
					}
				}

				if (event.key.code == sf::Keyboard::R) {
					if (m_programState == MainDisplay) {
						if (m_display.isLoaded()) {
							m_display.resetIndex();
							m_window.draw(m_display.getWord());
							m_display.pause(m_timer);
						}
					}
				}

				if (event.key.code == sf::Keyboard::RBracket) {
					if (m_programState == MainDisplay) {
						m_settings.incrementDisplayCharSize();
						m_display.setCharacterSize(m_settings.getDisplayCharSize());

					}
				}

				if (event.key.code == sf::Keyboard::LBracket) {
					if (m_programState == MainDisplay) {
						m_settings.decrementDisplayCharSize();
						m_display.setCharacterSize(m_settings.getDisplayCharSize());
					}
				}

				if (event.key.code == sf::Keyboard::Up) {
					if (m_programState == MainDisplay) {
						m_settings.incrementWPM();
						mWPMNum.setString(std::to_string(m_settings.getWPM()));
					}
				}

				if (event.key.code == sf::Keyboard::Down) {
					if (m_programState == MainDisplay) {
						m_settings.decrementWMP();
						mWPMNum.setString(std::to_string(m_settings.getWPM()));
					}
				}
			}
		}
		// Add settings for dark mode
		m_window.clear(sf::Color::White);

		switch (m_programState) {
		case MainDisplay:

			m_window.draw(mainDisplay);
			textButton.draw(m_window);
			sPlayButton.draw(m_window);
			sPauseButton.draw(m_window);
			sResetButton.draw(m_window);
			settingsButton.draw(m_window);

			m_window.draw(mWPM);
			m_window.draw(mWPMNum);

			if (!m_display.isPaused())
				m_display.calculateWord(m_timer, m_settings.getWPM());
			m_window.draw(m_display.getWord());

			if (event.type == sf::Event::MouseMoved) {

				handleButton(textButton);
				handleButton(sResetButton);
				handleButton(sPlayButton);
				handleButton(sPauseButton);
				handleButton(settingsButton);

			}

			if (textButton.isClicked(m_window)) {
				m_display.pause(m_timer);
				m_programState = LoadText;
			}

			if (sPlayButton.isClicked(m_window)) {
				m_display.unpause(m_timer);
			}

			if (sPauseButton.isClicked(m_window)) {
				m_display.pause(m_timer);
			}

			if (sResetButton.isClicked(m_window)) {
				if (m_display.isLoaded()) {
					m_display.resetIndex();
					m_window.draw(m_display.getWord());
					m_display.pause(m_timer);
				}
			}

			if (settingsButton.isClicked(m_window)) {
				m_programState = SettingsMenu;
				m_display.pause(m_timer);
			}


			break;
		case LoadText:

			m_window.draw(mainDisplay);
			textBox.draw(m_window);
			clearButton.draw(m_window);
			saveButton.draw(m_window);
			loadButton.draw(m_window);
			returnButton.draw(m_window);

			if (event.type == sf::Event::MouseMoved) {

				handleButton(textButton);
				handleButton(clearButton);
				handleButton(saveButton);
				handleButton(loadButton);
				handleButton(returnButton);

			}

			if (clearButton.isClicked(m_window)) {
				textBox.clearText();
			}

			if (saveButton.isClicked(m_window)) {
				FE.SaveFileContent(textBox.getText());
			}

			if (loadButton.isClicked(m_window)) {
				std::wstring filePath = FE.OpenTextFileDialog();
				if (filePath.empty()) {
					std::wcerr << L"No file selected." << std::endl;
				}

				std::wstring fileContent = FE.ReadFileContent(filePath);

				m_text = fileContent;
				m_splitter.setText(m_text);
				m_splitter.chunkText(2);
				m_display.loadText(m_splitter);
				m_timer.restart();
				m_programState = ProgramState::MainDisplay;
			}

			if (returnButton.isClicked(m_window)) {
				m_programState = ProgramState::MainDisplay;
			}

			if (lastChar != 0)
				textBox.typedOn(lastChar);

			lastChar = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				std::wstring newText = textBox.getText();
				if (!newText.empty()) {
					m_text = newText;
					m_splitter.setText(m_text);
					m_splitter.chunkText(1);
					m_display.loadText(m_splitter);
					m_timer.restart();
				}
				m_programState = ProgramState::MainDisplay;
			}

			//std::cout << "Loaded" << std::endl;
			//m_text = L"Gdzieś jest, lecz nie wiadomo gdzie Świat w ktorym baśń ta dzieje się Maleńka pszczółka mieszka w nim Co wieść chce wsród owadów prym";
			//m_splitter.setText(m_text);
			//m_splitter.chunkText(2);
			//m_display.loadText(m_splitter);
			//m_programState = ProgramState::MainDisplay;

			break;
		case SettingsMenu:

			tempButt1.draw(m_window);
			tempButt2.draw(m_window);
			tempButt3.draw(m_window);
			tempButt4.draw(m_window);
			tempButt5.draw(m_window);
			tempButt6.draw(m_window);

			sArial.draw(m_window);
			sTimes.draw(m_window);
			sComic.draw(m_window);

			sLight.draw(m_window);
			sDark.draw(m_window);

			m_window.draw(sWPMNum);
			m_window.draw(sWPM);

			m_window.draw(sChunks);
			m_window.draw(sChunksNum);

			m_window.draw(sCharSize);
			m_window.draw(sCharSizeNum);
			m_window.draw(sFont);
			m_window.draw(sMode);

			returnButton.draw(m_window);

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

			if(sArial.isClicked(m_window)) {
				m_display.setFont(arial);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			if(sTimes.isClicked(m_window)) {
				m_display.setFont(times);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			if(sComic.isClicked(m_window)) {
				m_display.setFont(comic);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			break;
		default:
			break;
		}
		m_window.display();
	}
}

void SpeedReader::handleButton(Button& button) {
	if (button.isMouseOver(m_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
	}
	else {
		button.setBackColor(sf::Color::Color(248, 249, 250, 255));
	}
}

void SpeedReader::handleButton(TextButton& button) {
	if (button.isMouseOver(m_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
		button.setTextColor(sf::Color::Color(0, 0, 0, 180));
	}
	else {
		button.setBackColor(sf::Color::Color(248, 249, 250, 255));
		button.setTextColor(sf::Color::Color(0, 0, 0, 160));
	}
}

void SpeedReader::handleButton(SpriteButton& button) {
	if (button.isMouseOver(m_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
		button.setSpriteColor(sf::Color::Color(0, 0, 0, 180));
	}
	else {
		button.setBackColor(sf::Color::Color(248, 249, 250, 255));
		button.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	}
}

void SpeedReader::applySettings() {
	m_display.setCharacterSize(m_settings.getDisplayCharSize());
}

void SpeedReader::loadResources() {
	// DO ERROR HANDLING
	arial.loadFromFile("fonts/arial.ttf");
	arialbd.loadFromFile("fonts/arialbd.ttf");

	times.loadFromFile("fonts/times.ttf");
	timesbd.loadFromFile("fonts/timesbd.ttf");

	comic.loadFromFile("fonts/comic.ttf");
	comicbd.loadFromFile("fonts/comicbd.ttf");
}