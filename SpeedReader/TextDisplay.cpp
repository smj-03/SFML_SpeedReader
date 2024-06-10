#include "TextDisplay.h"

TextDisplay::TextDisplay() {
	_isPaused = true;
	_wordListSize = 0;
	_currentIndex = 0;
	_wordsPerMinute = 500;

	_background.setSize(sf::Vector2f(750, 350));
	_background.setPosition(25, 25);
	_background.setFillColor(sf::Color::Color(248, 249, 250, 255));
	_background.setOutlineColor(sf::Color::Color(222, 226, 230, 255));
	_background.setOutlineThickness(-1);

	_font.loadFromFile("arial.ttf");
	_word.setFont(_font);
	_word.setCharacterSize(50);
	_word.setFillColor(sf::Color::Color(0, 0, 0, 200));

	_word.setString("Welcome to Speed Reader!");
	centerText();
}

void TextDisplay::centerText() {
	_wordBounds = (sf::Vector2f)((sf::Vector2i)(_word.getGlobalBounds().getSize() / 2.f + _word.getLocalBounds().getPosition()));
	_word.setOrigin(_wordBounds.x, (int)_word.getCharacterSize() * 3 / 4);
	_word.setPosition(400, 200);
}

void TextDisplay::loadText(TextSplitter& splitter) {
	// if size == 0 throw error
	_currentIndex = 0;
	_wordList = splitter.getChunks();
	_wordListSize = _wordList.size();
	_chunkSize = splitter.getChunkSize();
	_word.setString(_wordList[0]);
	centerText();
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

