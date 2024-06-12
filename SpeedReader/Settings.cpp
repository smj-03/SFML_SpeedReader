#include "Settings.h"

Settings::Settings() {
	m_displayCharSize = 50;
	m_wordsPerMinute = 500;
	m_wordsPerFrame = 1;
	m_font = ARIAL;
}

void Settings::incrementDisplayCharSize() {
	if (m_displayCharSize < 60)
		m_displayCharSize++;
}

void Settings::decrementDisplayCharSize() {
	if (m_displayCharSize > 24)
		m_displayCharSize--;
}

int Settings::getWPM() {
	return m_wordsPerMinute;
}

int Settings::getWPF() {
	return m_wordsPerFrame;
}

int Settings::getDisplayCharSize() {
	return m_displayCharSize;
}

void Settings::incrementWPM() {
	if (m_wordsPerMinute < 900) 
		m_wordsPerMinute += 5;
}

void Settings::decrementWPM() {
	if (m_wordsPerMinute > 100)
		m_wordsPerMinute -= 5;
}

void Settings::incrementWPF() {
	if (m_wordsPerFrame < 3)
		m_wordsPerFrame++;
}

void Settings::decrementWPF() {
	if (m_wordsPerFrame > 1)
		m_wordsPerFrame--;
}

void Settings::setFont(FontStyle font) {
	m_font = font;
}
