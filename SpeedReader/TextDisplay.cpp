#include "TextDisplay.h"

TextDisplay::TextDisplay() {
	_isPaused = true;
	_wordListSize = 0;
	_currentIndex = 0;
	_wordsPerMinute = 500;
	_isLoaded = false;

	_font.loadFromFile("fonts/arial.ttf");
	_word.setFont(_font);
	_word.setCharacterSize(50);
	_word.setFillColor(sf::Color::Color(0, 0, 0, 200));

	_word.setString("Welcome to Speed Reader!");
	centerText();
}

void TextDisplay::setParent(sf::RectangleShape& parent){
	_background = parent;
}

void TextDisplay::centerText() {
	_wordBounds = (sf::Vector2f)((sf::Vector2i)(_word.getGlobalBounds().getSize() / 2.f + _word.getLocalBounds().getPosition()));
	_word.setOrigin(_wordBounds.x, (int)_word.getCharacterSize() * 3 / 4);
	_word.setPosition(400, 200);
}

void TextDisplay::loadText(TextSplitter& splitter) {
	// if size == 0 throw error
	_isLoaded = true;
	_currentIndex = 0;
	_wordList = splitter.getChunks();
	_wordListSize = _wordList.size();
	_chunkSize = splitter.getChunkSize();
	_word.setString(_wordList[0]);
	centerText();
}

bool TextDisplay::isLoaded() {
	return _isLoaded;
}

sf::Text TextDisplay::getWord() {
	return _word;
}

sf::RectangleShape TextDisplay::getBackground() {
	return _background;
}

void TextDisplay::calculateWord(sf::Clock& timer) {
	_word.setString(_wordList[_currentIndex]);
	centerText();
	if (timer.getElapsedTime().asMilliseconds() >= (60.0 / _wordsPerMinute * 1000.0 * _chunkSize) && _currentIndex < (_wordListSize - 1)) {
		_currentIndex++;
		timer.restart();
	}
}

bool TextDisplay::isPaused() {
	return _isPaused;
}

void TextDisplay::pause(sf::Clock& timer) {
	_isPaused = true;
	timer.restart();
}

void TextDisplay::unpause(sf::Clock& timer) {
	_isPaused = false;
	timer.restart();
}

void TextDisplay::resetIndex() {
	_currentIndex = 0;
	_word.setString(_wordList[0]);
	centerText();
}

