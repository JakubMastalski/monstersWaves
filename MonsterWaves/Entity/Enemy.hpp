#pragma once

#include <Screen/Window.hpp>

#include <array>

class Enemy
{
public:
    Enemy(const Window* window, const sf::Vector2f& playerPosition, float speed);

public:
    void update(float dt, const sf::Vector2f& playerPosition);
    void draw(Window* window) const;

private:
    void updateAnimation(float dt);

private:
    sf::CircleShape m_circle;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
private:
    float m_speed;

    float m_animationTimer{ 0.0f };
    int   m_animationDirection{ 1 };

    float m_animationMoveIdleTime{ 0.0f };
   const float m_frameDuration{ 0.07f };

private:
    sf::Texture m_movingTexture;
    sf::Texture m_idleTexture;
    sf::Sprite  m_sprite;
private:
    std::array<sf::IntRect, 9> m_movingRects;
    int  m_currentFrame{ 0 };
private:
    float m_frameTime{ 0.07f };

private:
    void updateMoveAnimation();
    void updateMove(const float dt, const sf::Vector2f& playerPosition);
};