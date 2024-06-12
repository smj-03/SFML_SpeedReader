#pragma once
#include <SFML/Graphics.hpp>
#include "ProgramState.h"
#include "TextSplitter.h"
#include "TextDisplay.h"
#include "Settings.h"
#include "Button.h"
#include "SpriteButton.h"
#include "TextButton.h"
#include "TextBox.h"
#include <FileExplorer.h>

class SpeedReader {

public:

	SpeedReader();

	void initialize();

	void loop();

	void loadResources();

	void applySettings();

private:

	Settings m_settings;

	ProgramState m_programState;

	sf::RenderWindow m_window;

	sf::Clock m_timer;

	TextSplitter m_splitter;

	TextDisplay m_display;

	TextBox m_inputBox;

	std::wstring m_text;

	sf::RectangleShape m_mainFrame;

	std::vector<TextButton> m_textButts;
	std::vector<SpriteButton> m_spriteButts;

	std::vector<sf::Text> m_staticTexts;
	std::vector<sf::Text> m_dynamicTexts;

	sf::Color m_lightBgColor;
	sf::Color m_lightOutColor;
	sf::Color m_lightTextColor;

	sf::Font arial;
	sf::Font arialbd;
	sf::Font times;
	sf::Font timesbd;
	sf::Font comic;
	sf::Font comicbd;

	sf::Texture m_resetIcon;
	sf::Texture m_playIcon;
	sf::Texture m_stopIcon;
	sf::Texture m_backIcon;
	sf::Texture m_settIcon;

	sf::Image m_appIcon;

	void highlightButton(Button& button);

	void highlightButton(TextButton& button);

	void highlightButton(SpriteButton& button);

};