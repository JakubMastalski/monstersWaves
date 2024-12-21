#include "Enemy.hpp"

#include "Utils/RandomGenerator.hpp"

Enemy::Enemy(const Window* window, const sf::Vector2f& playerPosition, const float speed)
    : m_speed(speed)
{
    RandomNumber randomGenerator;

    const float startX = static_cast<float>(
        randomGenerator.getNumber(0, static_cast<int>(window->getSize().x))
        );
    const float startY = static_cast<float>(
        randomGenerator.getNumber(0, static_cast<int>(window->getSize().y))
        );
    m_position = sf::Vector2f{ startX, startY };

    const sf::Vector2f direction = playerPosition - m_position;
    const float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    m_direction = direction / length;

    m_circle.setRadius(20.0f);
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
    m_circle.setPosition(m_position);
    m_circle.setFillColor(sf::Color::Red);
}

void Enemy::update(const float dt, const sf::Vector2f& playerPosition)
{
    m_position += m_direction * m_speed * dt;

    const sf::Vector2f newDirection = playerPosition - m_position;
    const float length = std::sqrt(newDirection.x * newDirection.x + newDirection.y * newDirection.y);
    if (length != 0)
    {
        m_direction = newDirection / length;
    }

    m_animationTimer += dt;
    if (m_animationTimer >= 0.07f)
    {
        m_animationTimer = 0.0f;

        float radius = m_circle.getRadius();
        if (m_animationDirection > 0 && radius >= 22.0f)
        {
            m_animationDirection = -1;
        }
        else if (m_animationDirection < 0 && radius <= 18.0f)
        {
            m_animationDirection = 1;
        }
        m_circle.setRadius(radius + static_cast<float>(m_animationDirection));
        m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
    }

    m_circle.setPosition(m_position);
}

void Enemy::draw(Window* window) const
{
    window->draw(m_circle);
}
