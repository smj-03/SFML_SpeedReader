#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

enum State
{
    StateDefault,
    StateHovered,
    StatePressed,
    StateFocused
};

class Component : public sf::Drawable {
private:

    State m_state;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    bool m_selectable;

    std::function<void(void)> m_callback;

    sf::Transform m_transform;

public:
    Component();

    void setPosition(const sf::Vector2f& pos);

    const sf::Vector2f& getPosition() const;

    sf::Vector2f getAbsolutePosition() const;

    const sf::Vector2f& getSize() const;

    bool containsPoint(const sf::Vector2f& point) const;

    bool isSelectable() const;

    bool isFocused() const;

    void setCallback(std::function<void(void)> callback);
};