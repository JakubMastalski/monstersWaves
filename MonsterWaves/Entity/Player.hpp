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
    void stopAttack();
    void draw(Window* window) const;

public:
    void setDirection(Direction direction, float dt);

    void moveLeft(float dt);
    void moveRight(float dt);
    void moveUp(float dt);
    void moveDown(float dt);
    void stopMoving();
    void attack();

    void moveDiagonaly_UpRight(float dt);
    void moveDiagonaly_UpLeft(float dt);
    void moveDiagonaly_DownRight(float dt);
    void moveDiagonaly_DownLeft(float dt);

public:
    sf::FloatRect getBounds() const;

private:
    void updateMoveAnimation(const float dt);
    void updateAttackAnimation(const float dt);

private:
    sf::Texture m_movingTexture;
    sf::Texture m_idleTexture;
    sf::Texture m_attackTexture;
    sf::Sprite  m_sprite;

private:
    std::array< sf::IntRect, 8 >    m_movingRects;
    std::array< sf::IntRect, 10 >   m_idleRects;
    std::array< sf::IntRect, 7 >    m_attackRects;
    int                             m_currentFrame{ 0 };

private:
    float m_attackAnimationTime{ 0.0f };
    float m_animationMoveIdleTime{ 0.0f };
    float m_frameDuration{ 0.07f };

private:
    bool m_isMovingLeft{ false };
    bool m_isMovingRight{ false };
    bool m_isMovingUp{ false };
    bool m_isMovingDown{ false };
    bool m_isIdle{ true };
    bool m_isAttacking{ false };

    bool m_moveDiagonaly_UpRight{ false };
    bool m_moveDiagonaly_UpLeft{ false };
    bool m_moveDiagonaly_DownRight{ false };
    bool m_moveDiagonaly_DownLeft{ false };

    Direction m_lastDirection{ Direction::None };
};
