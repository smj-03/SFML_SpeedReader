#pragma once 
#include <SFML/Graphics.hpp>
#include "TextSplitter.h"

typedef std::vector<std::wstring> wordList;
class TextDisplay {

public:

	TextDisplay();

	void loadText(TextSplitter& splitter);

	void calculateWord(sf::Clock& timer);

	sf::Text getWord();

	sf::RectangleShape getBackground();

	bool isPaused();

	void pause(sf::Clock& timer);

	void unpause(sf::Clock& timer);

private:

	// To create BOX class
	sf::RectangleShape _background;

	wordList _wordList;

	// To create WORD class
	sf::Text _word;

	// To create OPTION class
	sf::Font _font;

	sf::Vector2f _wordBounds;

	int _wordsPerMinute;

	int _currentIndex;

	int _wordListSize;

	int _chunkSize = 1;

	bool _isPaused;

	void centerText();
};