#include "SpriteButton.h"

SpriteButton::SpriteButton() {}

SpriteButton::SpriteButton(sf::Texture& texture, sf::Vector2f spriteScale, sf::Vector2f size, sf::Color bgColor, sf::Color outColor) : Button(size, bgColor, outColor) {

	texture.setSmooth(true);
	m_sprite.setTexture(texture);
	m_sprite.setScale(spriteScale);
}

void SpriteButton::setTexture(sf::Texture& texture) {
	m_sprite.setTexture(texture);
}

void SpriteButton::setPosition(sf::Vector2f pos) {
	m_button.setPosition(pos);

	int xPos = pos.x + (m_button.getGlobalBounds().width / 2);
	int yPos = pos.y + (m_button.getGlobalBounds().height / 2);

	m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2.f, m_sprite.getTexture()->getSize().y / 2.f);
	m_sprite.setPosition({ (float)xPos, (float)yPos });
}

void SpriteButton::setScale(sf::Vector2f scale) {
	m_sprite.setScale(scale);
}

void SpriteButton::setRotation(float angle) {
	m_sprite.setRotation(angle);
}

void SpriteButton::setSpriteColor(sf::Color color) {
	m_sprite.setColor(color);
}

void SpriteButton::moveSprite(sf::Vector2f coords) {
	m_sprite.move(coords);
}

void SpriteButton::draw(sf::RenderWindow& window) {
	window.draw(m_button);
	window.draw(m_sprite);
}
