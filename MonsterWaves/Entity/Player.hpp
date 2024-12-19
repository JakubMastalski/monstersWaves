#pragma once

#include "Entity/Direction.cpp"
#include "Screen/Window.hpp"

#include <array>

class Player
{
public:
    explicit Player(const Window* window);

public:
    void update(float dt);
    void draw(Window* window);

public:
    void setDirection(Direction direction, float dt);

    void moveLeft(float dt);
    void moveRight(float dt);
    void stopMoving();
    void attack();

public:
    sf::FloatRect getBounds() const;

private:
    void updateAnimation(float dt);

private:
    sf::Texture m_movingTexture;
    sf::Texture m_idleTexture;
    sf::Texture m_attackTexture;
    sf::Sprite  m_sprite;

private:
    std::array< sf::IntRect, 8 >    m_moveLeftRects;
    std::array< sf::IntRect, 8 >    m_moveRightRects;
    std::array< sf::IntRect, 10 >   m_idleRects;
    std::array< sf::IntRect, 7 >    m_attackLeftRects;
    std::array< sf::IntRect, 7 >    m_attackRightRects;
    int                             m_currentFrame{ 0 };

private:
    float m_animationTime{ 0.0f };
    float m_frameDuration{ 0.07f };

private:
    bool m_isMovingLeft{ false };
    bool m_isMovingRight{ false };
    bool m_isIdle{ true };
    bool m_isAttacking{ false };

    Direction m_lastDirection{ Direction::None };
};
