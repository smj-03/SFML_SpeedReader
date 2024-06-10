#include "TextBox.h"

TextBox::TextBox() {}

TextBox::TextBox(int size, sf::Color color, bool selected) {

	m_textbox.setCharacterSize(size);
	m_textbox.setFillColor(color);
	m_isSelected = selected;

	if (selected) {
		m_textbox.setString("_");
	}
	else {
		m_textbox.setString("");
	}
}

void TextBox::setFont(sf::Font& font) {
	m_textbox.setFont(font);
}

void TextBox::setPosition(sf::Vector2f pos) {
	m_textbox.setPosition(pos);
}

void TextBox::setLimit(int limit) {
	m_hasLimit = true;
	m_limit = limit;
}

void TextBox::setSelected(bool sel) {
	m_isSelected = sel;
	if (!sel) {
		std::string t = m_text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		m_textbox.setString(newT);
	}
}

std::string TextBox::getText() {
	return m_text.str();
}

void TextBox::typedOn(sf::Event input) {
	if (m_isSelected) {
		int charTyped = input.text.unicode;
		if (charTyped < 128) {
			if (m_hasLimit) {
				if (m_text.str().length() <= m_limit) {
					inputLogic(charTyped);
				}
				else if (m_text.str().length() > m_limit && charTyped == DELETE_KEY) {
					deleteLastChar();
				}
			}
			else {
				inputLogic(charTyped);
			}
		}
	}
}

void TextBox::draw(sf::RenderWindow& window) {
	window.draw(m_textbox);
}

void TextBox::inputLogic(int charTyped) {
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
		m_text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY) {
		if (m_text.str().length() > 0) {
			deleteLastChar();
		}
	}
	m_textbox.setString(m_text.str() + "_");
}

void TextBox::deleteLastChar() {
	std::string t = m_text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	m_text.str("");
	m_text << newT;

	m_textbox.setString(m_text.str());
}