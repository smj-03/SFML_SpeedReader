#include "SpeedReader.h"
#include <iostream>


SpeedReader::SpeedReader() {
	m_window.create(sf::VideoMode(800, 450), "Speed Reader", sf::Style::Titlebar | sf::Style::Close);
	m_programState = ProgramState::MainDisplay;
}

void SpeedReader::loop() {

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

				highlightButton(m_textButts[0]);
				highlightButton(m_spriteButts[0]);
				highlightButton(m_spriteButts[1]);
				highlightButton(m_spriteButts[2]);
				highlightButton(m_spriteButts[3]);

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

				highlightButton(m_textButts[1]);
				highlightButton(m_textButts[2]);
				highlightButton(m_textButts[3]);

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
			m_textButts[4].draw(m_window);
			m_textButts[5].draw(m_window);
			m_textButts[6].draw(m_window);
			m_textButts[7].draw(m_window);
			m_textButts[8].draw(m_window);

			m_spriteButts[4].draw(m_window);
			m_spriteButts[5].draw(m_window);
			m_spriteButts[6].draw(m_window);
			m_spriteButts[7].draw(m_window);
			m_spriteButts[8].draw(m_window);

			m_window.draw(m_staticTexts[2]);
			m_window.draw(m_staticTexts[3]);
			m_window.draw(m_staticTexts[4]);
			m_window.draw(m_staticTexts[5]);
			m_window.draw(m_staticTexts[6]);
		


			if (event.type == sf::Event::MouseMoved) {

				highlightButton(m_spriteButts[4]);
				highlightButton(m_textButts[6]);
				highlightButton(m_textButts[7]);
				highlightButton(m_textButts[8]);

			}

			if (m_textButts[6].isClicked(m_window)) {
				m_display.setFont(arial);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			if (m_textButts[7].isClicked(m_window)) {
				m_display.setFont(times);
				m_display.centerText();
				m_programState = MainDisplay;
			}

			if (m_textButts[8].isClicked(m_window)) {
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

void SpeedReader::highlightButton(Button& button) {
	if (button.isMouseOver(m_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
	}
	else {
		button.setBackColor(m_lightBgColor);
	}
}

void SpeedReader::highlightButton(TextButton& button) {
	if (button.isMouseOver(m_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
		button.setTextColor(sf::Color::Color(0, 0, 0, 180));
	}
	else {
		button.setBackColor(m_lightBgColor);
		button.setTextColor(m_lightTextColor);
	}
}

void SpeedReader::highlightButton(SpriteButton& button) {
	if (button.isMouseOver(m_window)) {
		button.setBackColor(sf::Color::Color(240, 241, 242, 255));
		button.setSpriteColor(sf::Color::Color(0, 0, 0, 180));
	}
	else {
		button.setBackColor(m_lightBgColor);
		button.setSpriteColor(m_lightTextColor);
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
	m_lightTextColor = sf::Color::Color(0, 0, 0, 160);

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
	TextButton mainTextButt = TextButton("TEXT", { 100,25 }, m_lightBgColor, sf::Color::Color(222, 226, 230, 255), m_lightTextColor);
	mainTextButt.setFont(arialbd);
	mainTextButt.setPosition({ 25,400 });
	m_textButts.push_back(mainTextButt);

	// spriteButts [0]
	SpriteButton mainResetButt = SpriteButton(m_resetIcon, { 0.55f, 0.55f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	mainResetButt.setSpriteColor(m_lightTextColor);
	mainResetButt.setPosition({ 140, 400 });
	m_spriteButts.push_back(mainResetButt);

	// spriteButts [1]
	SpriteButton mainPlayButt = SpriteButton(m_playIcon, { 0.6f, 0.6f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	mainPlayButt.setSpriteColor(m_lightTextColor);
	mainPlayButt.setPosition({ 180, 400 });
	m_spriteButts.push_back(mainPlayButt);

	// spriteButts [2]
	SpriteButton mainPauseButt = SpriteButton(m_stopIcon, { 0.6f, 0.6f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	mainPauseButt.setSpriteColor(m_lightTextColor);
	mainPauseButt.setPosition({ 220, 400 });
	m_spriteButts.push_back(mainPauseButt);

	// spriteButts [3]
	SpriteButton mainSettingsButton = SpriteButton(m_settIcon, { 0.75, 0.75 }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	mainSettingsButton.setSpriteColor(m_lightTextColor);
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
	mainWPM.setFillColor(m_lightTextColor);
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
	mainWPF.setFillColor(m_lightTextColor);
	mainWPF.setPosition({ 690, 400 });
	mainWPF.setString("WPF");
	m_staticTexts.push_back(mainWPF);

	// LOAD PAGE
	// --------------------------------------------------------------
	// textButts [1]
	TextButton loadClearButt = TextButton("CLEAR", { 100,25 }, m_lightBgColor, m_lightOutColor, m_lightTextColor);
	loadClearButt.setFont(arialbd);
	loadClearButt.setPosition({ 25,400 });
	m_textButts.push_back(loadClearButt);

	// textButts [2]
	TextButton loadLoadButt = TextButton("LOAD", { 100,25 }, m_lightBgColor, m_lightOutColor, m_lightTextColor);
	loadLoadButt.setFont(arialbd);
	loadLoadButt.setPosition({ 140,400 });
	m_textButts.push_back(loadLoadButt);

	// textButts [3]
	TextButton loadSaveButt = TextButton("SAVE", { 100,25 }, m_lightBgColor, m_lightOutColor, m_lightTextColor);
	loadSaveButt.setFont(arialbd);
	loadSaveButt.setPosition({ 255,400 });
	m_textButts.push_back(loadSaveButt);

	// spriteButts [4]
	SpriteButton returnButt = SpriteButton(m_backIcon, { 0.9f, 0.9f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	returnButt.setSpriteColor(m_lightTextColor);
	returnButt.setPosition({ 750, 400 });
	m_spriteButts.push_back(returnButt);

	// SETTINGS
	// --------------------------------------------------------------
	// statTexts [2]
	sf::Text settingsWPM;
	settingsWPM.setFont(arialbd);
	settingsWPM.setCharacterSize(25);
	settingsWPM.setFillColor(sf::Color::Color(0, 0, 0, 200));
	settingsWPM.setPosition({ 75, 75 });
	settingsWPM.setString("WORDS PER MINUTE");
	m_staticTexts.push_back(settingsWPM);

	// spriteButt [5]
	SpriteButton settingsUp(m_playIcon, { 0.6f, 0.6f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	settingsUp.setRotation(-90.f);
	settingsUp.setSpriteColor(m_lightTextColor);
	settingsUp.setPosition({ 340, 79 });
	m_spriteButts.push_back(settingsUp);

	// spriteButt [6]
	SpriteButton settingsDown(m_playIcon, { 0.6f, 0.6f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	settingsDown.setRotation(90.f);
	settingsDown.setSpriteColor(m_lightTextColor);
	settingsDown.setPosition({ 370, 79 });
	m_spriteButts.push_back(settingsDown);

	// statTexts [3]
	sf::Text settingsWPF;
	settingsWPF.setFont(arialbd);
	settingsWPF.setCharacterSize(25);
	settingsWPF.setFillColor(sf::Color::Color(0, 0, 0, 200));
	settingsWPF.setPosition({ 75, 125 });
	settingsWPF.setString("WORDS PER FRAME");
	m_staticTexts.push_back(settingsWPF);

	// spriteButt [7]
	SpriteButton settingsLeft(m_playIcon, { -0.6f, 0.6f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	settingsLeft.setSpriteColor(m_lightTextColor);
	settingsLeft.setPosition({ 334, 129 });
	m_spriteButts.push_back(settingsLeft);

	// spriteButt [8]
	SpriteButton settingsRight(m_playIcon, { 0.6f, 0.6f }, { 25, 25 }, m_lightBgColor, m_lightOutColor);
	settingsRight.setSpriteColor(m_lightTextColor);
	settingsRight.setPosition({ 364, 129 });
	m_spriteButts.push_back(settingsRight);

	// statTexts [4]
	sf::Text settingsCharSize;
	settingsCharSize.setFont(arialbd);
	settingsCharSize.setCharacterSize(25);
	settingsCharSize.setFillColor(sf::Color::Color(0, 0, 0, 200));
	settingsCharSize.setPosition({ 75, 200 });
	settingsCharSize.setString("CHARACTER SIZE");
	m_staticTexts.push_back(settingsCharSize);

	// textButts [4]
	TextButton settingsLBracket("[", { 25, 25 }, m_lightBgColor, m_lightOutColor, m_lightTextColor);
	settingsLBracket.setFont(arialbd);
	settingsLBracket.setPosition({ 304, 204 });
	m_textButts.push_back(settingsLBracket);

	// textButts [5]
	TextButton settingsRBracket("]", { 25, 25 }, m_lightBgColor, m_lightOutColor, m_lightTextColor);
	settingsRBracket.setFont(arialbd);
	settingsRBracket.setPosition({ 334, 204 });
	m_textButts.push_back(settingsRBracket);

	// statTexts [5]
	sf::Text settingsFont;
	settingsFont.setFont(arialbd);
	settingsFont.setCharacterSize(25);
	settingsFont.setFillColor(sf::Color::Color(0, 0, 0, 200));
	settingsFont.setPosition({ 75, 250 });
	settingsFont.setString("FONT");
	m_staticTexts.push_back(settingsFont);

	// textButts [6]
	TextButton sArial("Arial", { 80, 25 }, m_lightBgColor, m_lightOutColor, sf::Color::Color(0, 0, 0, 200));
	sArial.setFont(arialbd);
	sArial.setPosition({ 154, 254 });
	m_textButts.push_back(sArial);

	// textButts [6]
	TextButton sTimes("Times New Roman", { 200, 25 }, m_lightBgColor, m_lightOutColor, sf::Color::Color(0, 0, 0, 200));
	sTimes.setFont(timesbd);
	sTimes.setPosition({ 249, 254 });
	m_textButts.push_back(sTimes);

	// textButts [8]
	TextButton sComic("Comic Sans MS", { 200, 25 }, m_lightBgColor, m_lightOutColor, sf::Color::Color(0, 0, 0, 200));
	sComic.setFont(comicbd);
	sComic.setPosition({ 464, 254 });
	m_textButts.push_back(sComic);

	// statText [6]
	sf::Text credits;
	credits.setFont(arialbd);
	credits.setCharacterSize(25);
	credits.setFillColor(sf::Color::Color(0, 0, 0, 140));
	credits.setPosition({ 75, 325 });
	credits.setString("BY SMJ03");
	m_staticTexts.push_back(credits);
}
