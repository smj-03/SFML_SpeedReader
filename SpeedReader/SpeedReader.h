#pragma once
#include <SFML/Graphics.hpp>
#include "ProgramState.h"
#include "TextSplitter.h"
#include "TextDisplay.h"
#include "Settings.h"
#include "Button.h"
#include "SpriteButton.h"
#include "TextButton.h"

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

	std::wstring m_text;

	void handleButton(Button& button);

	void handleButton(TextButton& button);

	void handleButton(SpriteButton& button);

};