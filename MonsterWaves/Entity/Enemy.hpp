#pragma once

#include "Entity/EnemyState.cpp"
#include <Screen/Window.hpp>

#include <array>

class Enemy
{
public:
    Enemy(const Window* window, const sf::Vector2f& playerPosition, float speed);

public:
    void update(float dt, const sf::Vector2f& playerPosition, const sf::Vector2f& playerSize);
    void draw(Window* window) const;

private:
    sf::CircleShape m_circle;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
private:
    float m_speed;

    float m_animationTimer{ 0.0f };
    int   m_animationDirection{ 1 };

    float m_animationMoveIdleTime{ 0.0f };
    float m_frameDuration{ 0.07f };

public:
    sf::Texture m_movingTexture;
    sf::Texture m_deadTexture;
    sf::Texture m_attackTexture;
public:
    sf::Sprite  m_sprite;
private:
    std::array<sf::IntRect, 5> m_movingRects;
    std::array<sf::IntRect, 12> m_attackRects;
    std::array<sf::IntRect, 23> m_deadRects;

private:
    float m_frameTime{ 0.07f };
    int  m_currentFrame{ 0 };
private:
    void updateMoveAnimation(const float dt);
    void updateDeadAnimation(const float dt);
    void updateAttackAnimation(const float dt, const sf::Vector2f& playerPosition, const sf::Vector2f& playerSize);
    void updateMove(const float dt, const sf::Vector2f& playerPosition, const sf::Vector2f& playerSize);
public:
    bool checkCollisionWithPlayerAttack(const sf::Sprite& player) const;
    bool checkCollisionWithPlayer(const sf::Sprite& player) const;
    
    bool enemyisDead = { false };
    void enemyDie();
    EnemyState enemyState = EnemyState::EnemyMoving;
};