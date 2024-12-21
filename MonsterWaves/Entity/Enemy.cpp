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

    m_movingTexture.loadFromFile("res/images/EnemyRun.png");
    m_sprite.setTexture(m_movingTexture);


    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(20.0f, 20.0f);

    for (int i = 0; i < m_movingRects.size(); ++i)
    {
        m_movingRects[i] = sf::IntRect{ i * 80, 0, 80, 80 };
    }

    m_sprite.setTextureRect(m_movingRects[m_currentFrame]);
    m_sprite.setScale(1.5f, 1.5f);
}

void Enemy::update(const float dt, const sf::Vector2f& playerPosition)
{
    updateMove(dt, playerPosition);
    updateMoveAnimation();
}

void Enemy::updateMove(const float dt, const sf::Vector2f& playerPosition)
{
    const sf::Vector2f direction = playerPosition - m_position;
    const float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        m_direction = direction / length;
    }

    m_position += m_direction * m_speed * dt;
    m_sprite.setPosition(m_position);

    m_animationTimer += dt;

    if (m_animationTimer >= 0.07f)
    {
        m_animationTimer = 0.40f;

        m_sprite.setTexture(m_movingTexture);
    }
}
void Enemy::updateMoveAnimation()
{
    
}

void Enemy::draw(Window* window) const
{
    window->draw(m_sprite);
}