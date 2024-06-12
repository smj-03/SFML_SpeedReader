#include "TextDisplay.h"

TextDisplay::TextDisplay() {
	_isPaused = true;
	_isLoaded = false;

	_wordListSize = 0;
	_currentIndex = 0;
	_wordsPerMinute = 500;
	
	//_font.loadFromFile("./fonts/times.ttf");
	//_word.setFont(_font);
	_word.setCharacterSize(50);
	_word.setFillColor(sf::Color::Color(0, 0, 0, 120));

	//_word.setString("Welcome to Speed Reader!");
	centerText();
}

void TextDisplay::centerText() {
	_wordBounds = (sf::Vector2f)((sf::Vector2i)(_word.getGlobalBounds().getSize() / 2.f + _word.getLocalBounds().getPosition()));
	_word.setOrigin(_wordBounds.x, (int)_word.getCharacterSize() * 3 / 4);
	_word.setPosition(400, 200);
}

void TextDisplay::loadText(TextSplitter& splitter) {
	// if size == 0 throw error
	_word.setFillColor(sf::Color::Color(0, 0, 0, 200));
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

void TextDisplay::calculateWord(sf::Clock& timer, int wordsPerMinute) {
	_word.setString(_wordList[_currentIndex]);
	centerText();
	if (timer.getElapsedTime().asMilliseconds() >= (60.0 / wordsPerMinute * 1000.0 * _chunkSize) && _currentIndex < (_wordListSize - 1)) {
		_currentIndex++;
		timer.restart();
	}
}

void TextDisplay::setCharacterSize(int size) {
	_word.setCharacterSize(size);
	centerText();
}

bool TextDisplay::isPaused() {
	return _isPaused;
}

void TextDisplay::pause(sf::Clock& timer) {
	_isPaused = true;
	timer.restart();
}

void TextDisplay::unpause(sf::Clock& timer) {
	if (_isLoaded) {
		_isPaused = false;
		timer.restart();
	}
}

void TextDisplay::resetIndex() {
	_currentIndex = 0;
	_word.setString(_wordList[0]);
	centerText();
}

void TextDisplay::setWord(const std::string& text) {
	_word.setString(text);
	centerText();
}

void TextDisplay::setFont(sf::Font& font) {
	_font = font;
	_word.setFont(font);
}
