#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox {

public:

	TextBox();

	TextBox(int size, sf::Color color, bool selected);

	void setFont(sf::Font& font);

	void setPosition(sf::Vector2f pos);

	void setLimit(int limit);

	void setSelected(bool sel);

	std::string getText();

	void typedOn(sf::Event input);

	void draw(sf::RenderWindow& window);

private:

	sf::Text m_textbox;

	std::ostringstream m_text;

	bool m_isSelected = false;

	bool m_hasLimit = false;

	int m_limit;

	void inputLogic(int charTyped);
	
	void deleteLastChar();
};