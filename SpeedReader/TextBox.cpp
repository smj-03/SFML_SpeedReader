#include "TextBox.h"
#include <iostream>

TextBox::TextBox() {}

TextBox::TextBox(int size, sf::Color color, bool selected) {

	m_textbox.setCharacterSize(size);
	m_textbox.setFillColor(color);
	m_isSelected = selected;

	if (selected) {
		m_textbox.setString(L"_");
	}
	else {
		m_textbox.setString(L"");
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
		std::wstring t = m_text.str();
		std::wstring newT = L"";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		m_textbox.setString(newT);
	}
}

std::wstring TextBox::getText() {
	return m_text.str();
}

void TextBox::typedOn(sf::Uint16 charTyped) {
	std::cout << charTyped << std::endl;
	if (m_isSelected) {
		if (charTyped < 128 || charTyped > 210) {
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

void TextBox::typedOn(sf::Event event) {
	if (m_isSelected) {
		int charTyped = event.text.unicode;
		if (charTyped < 128 || charTyped > 210) {
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
		switch (charTyped)
		{
		case 211:
			m_text << L"Ó";
			break;
		case 243:
			m_text << L"ó";
			break;
		case 260:
			m_text << L"Ą";
			break;
		case 261:
			m_text << L"ą";
			break;
		case 346:
			m_text << L"Ś";
			break;
		case 347:
			m_text << L"ś";
			break;
		case 280:
			m_text << L"Ę";
			break;
		case 281:
			m_text << L"ę";
			break;
		case 321:
			m_text << L"Ł";
			break;
		case 322:
			m_text << L"ł";
			break;
		case 379:
			m_text << L"Ż";
			break;
		case 380:
			m_text << L"ż";
			break;
		case 377:
			m_text << L"Ź";
			break;
		case 378:
			m_text << L"ź";
			break;
		case 262:
			m_text << L"Ć";
			break;
		case 263:
			m_text << L"ć";
			break;
		case 323:
			m_text << L"Ń";
			break;
		case 324:
			m_text << L"ń";
			break;
		default:
			m_text << static_cast<char>(charTyped);
			break;
		}
	}
	else if (charTyped == DELETE_KEY) {
		if (m_text.str().length() > 0) {
			deleteLastChar();
		}
	}
	m_textbox.setString(m_text.str() + L"_");
}

void TextBox::deleteLastChar() {
	std::wstring t = m_text.str();
	std::wstring newT = L"";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	m_text.str(L"");
	m_text << newT;

	m_textbox.setString(m_text.str());
}