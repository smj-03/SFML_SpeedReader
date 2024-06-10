#pragma once
#include <SFML/Graphics.hpp>
#include "ProgramState.h"
#include "TextSplitter.h"
#include "TextDisplay.h"
#include "Button.h"
#include "SpriteButton.h"
#include "TextButton.h"

class SpeedReader {

private:

	ProgramState _programState;

	sf::RenderWindow _window;

	sf::Clock _timer;

	TextSplitter _splitter;

	TextDisplay _display;

	std::wstring _text;

	void handleButton(Button& button);

	void handleButton(TextButton& button);

	void handleButton(SpriteButton& button);

public:

	SpeedReader();

	void initialize();

	void loop();

	void loadResources();

};