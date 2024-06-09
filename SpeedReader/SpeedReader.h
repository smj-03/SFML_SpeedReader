#pragma once
#include <SFML/Graphics.hpp>
#include "ProgramState.h"
#include "TextSplitter.h"
#include "TextDisplay.h"

class SpeedReader {

private:

	ProgramState _programState;

	sf::RenderWindow _window;

	sf::Clock _timer;

	TextSplitter _splitter;

	TextDisplay _display;

	std::wstring _text;

public:

	SpeedReader();

	void initialize();

	void loop();

	void loadResources();

};