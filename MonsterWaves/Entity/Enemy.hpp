#pragma once

#include <Screen/Window.hpp>

class Enemy
{
public:
    Enemy(const Window* window, const sf::Vector2f& playerPosition, float speed);

public:
    void update(float dt, const sf::Vector2f& playerPosition);
    void render(sf::RenderWindow& window) const;

private:

    sf::CircleShape m_circle;
    sf::Vector2f  m_position;
    sf::Vector2f  m_direction;
    float  m_speed;
    float  m_animationTimer{ 0.0f };
    int    m_animationDirection{ 1 };
};