#include "SpeedReader.h"
#include <iostream>


SpeedReader::SpeedReader() {
	m_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	m_programState = ProgramState::MainDisplay;
}

void SpeedReader::loop() {

	// SETTINGS 

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
	sWPMNum.setString("500");

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
						m_dynamicTexts[0].setString(std::to_string(m_settings.getWPM()));
					}
				}

				if (event.key.code == sf::Keyboard::Down) {
					if (m_programState == MainDisplay) {
						m_settings.decrementWPM();
						m_dynamicTexts[0].setString(std::to_string(m_settings.getWPM()));
					}
				}

				if (event.key.code == sf::Keyboard::Left) {
					if (m_programState == MainDisplay) {
						m_settings.decrementWPF();
						m_dynamicTexts[1].setString(std::to_string(m_settings.getWPF()));
						if (m_display.isLoaded()) {
							m_splitter.chunkText(m_settings.getWPF());
							m_display.loadText(m_splitter);
							m_timer.restart();
						}
					}
				}

				if (event.key.code == sf::Keyboard::Right) {
					if (m_programState == MainDisplay) {
						m_settings.incrementWPF();
						m_dynamicTexts[1].setString(std::to_string(m_settings.getWPF()));
						if (m_display.isLoaded()) {
							m_splitter.chunkText(m_settings.getWPF());
							m_display.loadText(m_splitter);
							m_timer.restart();
						}
					}
				}
			}
		}
		// Add settings for dark mode
		m_window.clear(sf::Color::White);

		switch (m_programState) {
		case MainDisplay:

			m_window.draw(m_mainFrame);
			m_textButts[0].draw(m_window);
			m_spriteButts[0].draw(m_window);
			m_spriteButts[1].draw(m_window);
			m_spriteButts[2].draw(m_window);
			m_spriteButts[3].draw(m_window);

			m_window.draw(m_staticTexts[0]);
			m_window.draw(m_dynamicTexts[0]);

			m_window.draw(m_staticTexts[1]);
			m_window.draw(m_dynamicTexts[1]);

			if (!m_display.isPaused())
				m_display.calculateWord(m_timer, m_settings.getWPM());
			m_window.draw(m_display.getWord());

			if (event.type == sf::Event::MouseMoved) {

				handleButton(m_textButts[0]);
				handleButton(m_spriteButts[0]);
				handleButton(m_spriteButts[1]);
				handleButton(m_spriteButts[2]);
				handleButton(m_spriteButts[3]);

			}

			if (m_textButts[0].isClicked(m_window)) {
				m_display.pause(m_timer);
				m_programState = LoadText;
			}

			if (m_spriteButts[0].isClicked(m_window)) {
				if (m_display.isLoaded()) {
					m_display.resetIndex();
					m_window.draw(m_display.getWord());
					m_display.pause(m_timer);
				}
			}

			if (m_spriteButts[1].isClicked(m_window)) {
				m_display.unpause(m_timer);
			}

			if (m_spriteButts[2].isClicked(m_window)) {
				m_display.pause(m_timer);
			}

			if (m_spriteButts[3].isClicked(m_window)) {
				m_programState = SettingsMenu;
				m_display.pause(m_timer);
			}


			break;
		case LoadText:

			m_window.draw(m_mainFrame);

			m_inputBox.draw(m_window);

			m_textButts[1].draw(m_window);
			m_textButts[2].draw(m_window);
			m_textButts[3].draw(m_window);

			m_spriteButts[4].draw(m_window);

			if (event.type == sf::Event::MouseMoved) {

				handleButton(m_textButts[1]);
				handleButton(m_textButts[2]);
				handleButton(m_textButts[3]);

			}

			if (m_textButts[1].isClicked(m_window)) {
				m_inputBox.clearText();
			}

			if (m_textButts[2].isClicked(m_window)) {
				std::wstring filePath = FE.OpenTextFileDialog();
				if (filePath.empty()) {
					std::wcerr << L"No file selected." << std::endl;
				}

				std::wstring fileContent = FE.ReadFileContent(filePath);

				m_text = fileContent;
				m_splitter.setText(m_text);
				m_splitter.chunkText(m_settings.getWPF());
				m_display.loadText(m_splitter);
				m_timer.restart();
				m_programState = ProgramState::MainDisplay;
			}

			if (m_textButts[3].isClicked(m_window)) {
				FE.SaveFileContent(m_inputBox.getText());
			}

			if (m_spriteButts[4].isClicked(m_window)) {
				m_programState = ProgramState::MainDisplay;
			}

			if (lastChar != 0)
				m_inputBox.typedOn(lastChar);

			lastChar = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				std::wstring newText = m_inputBox.getText();
				if (!newText.empty()) {
					m_text = newText;
					m_splitter.setText(m_text);
					m_splitter.chunkText(m_settings.getWPF());
					m_display.loadText(m_splitter);
					m_timer.restart();
				}
				m_programState = ProgramState::MainDisplay;
			}

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

			m_spriteButts[4].draw(m_window);

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
				handleButton(m_spriteButts[4]);
				//handleButton(sDark);
				handleButton(sLight);

			}

			if (sArial.isClicked(m_window)) {
				m_display.setFont(arial);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			if (sTimes.isClicked(m_window)) {
				m_display.setFont(times);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			if (sComic.isClicked(m_window)) {
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
	m_appIcon.loadFromFile("icons/logo.png");

	m_resetIcon.loadFromFile("icons/reset-icon.png");
	m_playIcon.loadFromFile("icons/play-icon.png");
	m_stopIcon.loadFromFile("icons/pause-icon.png");
	m_backIcon.loadFromFile("icons/return-icon.png");
	m_settIcon.loadFromFile("icons/setting-icon.png");

	arial.loadFromFile("fonts/arial.ttf");
	arialbd.loadFromFile("fonts/arialbd.ttf");

	times.loadFromFile("fonts/times.ttf");
	timesbd.loadFromFile("fonts/timesbd.ttf");

	comic.loadFromFile("fonts/comic.ttf");
	comicbd.loadFromFile("fonts/comicbd.ttf");
}

void SpeedReader::initialize() {
	m_window.setIcon(m_appIcon.getSize().x, m_appIcon.getSize().y, m_appIcon.getPixelsPtr());

	m_lightBgColor = sf::Color::Color(248, 249, 250, 255);
	m_lightOutColor = sf::Color::Color(222, 226, 230, 255);

	m_display.setFont(arial);
	m_display.setWord("Welcome to Speed Reader!");

	m_mainFrame.setSize({ 750, 350 });
	m_mainFrame.setPosition(25, 25);
	m_mainFrame.setFillColor(m_lightBgColor);
	m_mainFrame.setOutlineColor(m_lightOutColor);
	m_mainFrame.setOutlineThickness(-1);

	m_inputBox = TextBox(24, sf::Color::Color(0, 0, 0, 200), true);
	m_inputBox.setFont(arialbd);
	m_inputBox.setPosition({ 30, 25 });

	// MAIN PAGE
	// --------------------------------------------------------------
	// textButts [0]
	TextButton mainTextButt = TextButton("TEXT", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	mainTextButt.setFont(arialbd);
	mainTextButt.setPosition({ 25,400 });
	m_textButts.push_back(mainTextButt);

	// spriteButts [0]
	SpriteButton mainResetButt = SpriteButton(m_resetIcon, { 0.55f, 0.55f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	mainResetButt.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	mainResetButt.setPosition({ 140, 400 });
	m_spriteButts.push_back(mainResetButt);

	// spriteButts [1]
	SpriteButton mainPlayButt = SpriteButton(m_playIcon, { 0.6f, 0.6f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	mainPlayButt.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	mainPlayButt.setPosition({ 180, 400 });
	m_spriteButts.push_back(mainPlayButt);

	// spriteButts [2]
	SpriteButton mainPauseButt = SpriteButton(m_stopIcon, { 0.6f, 0.6f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	mainPauseButt.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	mainPauseButt.setPosition({ 220, 400 });
	m_spriteButts.push_back(mainPauseButt);

	// spriteButts [3]
	SpriteButton mainSettingsButton = SpriteButton(m_settIcon, { 0.75, 0.75 }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	mainSettingsButton.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	mainSettingsButton.setPosition({ 750, 400 });
	m_spriteButts.push_back(mainSettingsButton);

	// dynamicTexts [0]
	sf::Text mainWPMNum;
	mainWPMNum.setFont(arialbd);
	mainWPMNum.setCharacterSize(20);
	mainWPMNum.setFillColor(sf::Color::Color(0, 0, 0, 200));
	mainWPMNum.setPosition({ 575, 400 });
	mainWPMNum.setString(std::to_string(m_settings.getWPM()));
	m_dynamicTexts.push_back(mainWPMNum);

	// staticTexts [0]
	sf::Text mainWPM;
	mainWPM.setFont(arialbd);
	mainWPM.setCharacterSize(20);
	mainWPM.setFillColor(sf::Color::Color(0, 0, 0, 160));
	mainWPM.setPosition({ 613, 400 });
	mainWPM.setString("WPM");
	m_staticTexts.push_back(mainWPM);

	// dynamicTexts [1]
	sf::Text mainWPFNum;
	mainWPFNum.setFont(arialbd);
	mainWPFNum.setCharacterSize(20);
	mainWPFNum.setFillColor(sf::Color::Color(0, 0, 0, 200));
	mainWPFNum.setPosition({ 675, 400 });
	mainWPFNum.setString(std::to_string(m_settings.getWPF()));
	m_dynamicTexts.push_back(mainWPFNum);

	// staticTexts [1]
	sf::Text mainWPF;
	mainWPF.setFont(arialbd);
	mainWPF.setCharacterSize(20);
	mainWPF.setFillColor(sf::Color::Color(0, 0, 0, 160));
	mainWPF.setPosition({ 690, 400 });
	mainWPF.setString("WPF");
	m_staticTexts.push_back(mainWPF);

	// LOAD PAGE
	// --------------------------------------------------------------
	// textButts [1]
	TextButton loadClearButt = TextButton("CLEAR", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	loadClearButt.setFont(arialbd);
	loadClearButt.setPosition({ 25,400 });
	m_textButts.push_back(loadClearButt);

	// textButts [2]
	TextButton loadLoadButt = TextButton("LOAD", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	loadLoadButt.setFont(arialbd);
	loadLoadButt.setPosition({ 140,400 });
	m_textButts.push_back(loadLoadButt);

	// textButts [3]
	TextButton loadSaveButt = TextButton("SAVE", { 100,25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255), sf::Color::Color(0, 0, 0, 160));
	loadSaveButt.setFont(arialbd);
	loadSaveButt.setPosition({ 255,400 });
	m_textButts.push_back(loadSaveButt);

	// spriteButts [4]
	SpriteButton returnButt = SpriteButton(m_backIcon, { 0.9f, 0.9f }, { 25, 25 }, sf::Color::Color(248, 249, 250, 255), sf::Color::Color(222, 226, 230, 255));
	returnButt.setSpriteColor(sf::Color::Color(0, 0, 0, 160));
	returnButt.setPosition({ 750, 400 });
	m_spriteButts.push_back(returnButt);
}
