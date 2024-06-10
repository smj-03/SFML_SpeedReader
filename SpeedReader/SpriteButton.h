#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class SpriteButton : public Button {

public:

	SpriteButton();

	SpriteButton(sf::Texture& texture, sf::Vector2f spriteScale, sf::Vector2f size, sf::Color bgColor, sf::Color outColor);

	void setTexture(sf::Texture& texture);

	void setPosition(sf::Vector2f pos);
	
	void setScale(sf::Vector2f scale);

	void setSpriteColor(sf::Color color);

	void moveSprite(sf::Vector2f coords);

	void draw(sf::RenderWindow& window);

protected:

	sf::Sprite m_sprite;

};