#pragma once
#include <SFML/Graphics.hpp>

enum FontStyle {
	ARIAL,
	TIMES,
	COMIC
};

class Settings {

public:

	Settings();

	void loadSettings();

	void saveSettings();

	void incrementDisplayCharSize();

	void decrementDisplayCharSize();

	void incrementWPM();

	void decrementWPM();

	void incrementWPF();

	void decrementWPF();

	int getDisplayCharSize();

	int getWPM();

	int getWPF();

	void setFont(FontStyle font);

private:

	int m_displayCharSize;

	int m_wordsPerMinute; 

	int m_wordsPerFrame;

	FontStyle m_font;

};