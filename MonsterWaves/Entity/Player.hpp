#pragma once

#include "Screen/Window.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class Player
{
public:
    explicit Player(const Window* window);

public:
    void update(float dt);
    void draw(Window* window);
    bool isMovingLeft{ false };
    bool isMovingRight{ false };
    bool isMovingUp{ false };
    bool isMovingDown{ false };

private:
    sf::CircleShape m_circleShape;
};