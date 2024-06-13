#pragma once 
#include <SFML/Graphics.hpp>
#include <exception>
#include "TextSplitter.h"
#include "Settings.h"

typedef std::vector<std::wstring> wordList;
class TextDisplay {

public:

	TextDisplay();

	void resetIndex();

	void loadText(TextSplitter& splitter);

	void calculateWord(sf::Clock& timer, int wordsPerMinute);

	sf::Text getWord();

	void setCharacterSize(int size);

	void setWord(const std::string& text);

	void setFont(sf::Font& font);

	void pause(sf::Clock& timer);

	void unpause(sf::Clock& timer);

	bool isLoaded();

	bool isPaused();

	void centerText();

private:

	wordList _wordList;

	// To create WORD class
	sf::Text _word;

	sf::Vector2f _wordBounds;

	int _wordsPerMinute;

	int _currentIndex;

	int _wordListSize;

	int _chunkSize = 1;

	bool _isPaused;

	bool _isLoaded;

};