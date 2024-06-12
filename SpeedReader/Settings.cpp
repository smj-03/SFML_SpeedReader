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

int Settings::getDisplayCharSize() {
	return m_displayCharSize;
}

void Settings::incrementWPM() {
	if (m_wordsPerMinute < 995) 
		m_wordsPerMinute += 5;
}

void Settings::decrementWMP() {
	if (m_wordsPerMinute > 100)
		m_wordsPerMinute -= 5;
}

void Settings::incrementWPF() {
	if (m_wordsPerFrame < 995)
		m_wordsPerMinute += 5;
}

void Settings::decrementWMF() {
	if (m_wordsPerFrame > 100)
		m_wordsPerMinute -= 5;
}

void Settings::setFont(FontStyle font) {
	m_font = font;
}