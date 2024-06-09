#pragma once 
#include <SFML/Graphics.hpp>
#include "TextSplitter.h"

typedef std::vector<std::wstring> wordList;
class TextDisplay {
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

	float _interval;

	int _currentIndex;

	int _wordListSize;

	int _chunkSize;

	bool _isPaused;

	void centerText();

public:

	TextDisplay();

	void loadText(TextSplitter& splitter);

	void calculateWord(sf::Clock& timer);

	sf::Text getWord();

	sf::RectangleShape getBackground();

};