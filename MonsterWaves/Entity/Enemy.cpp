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
    m_deadTexture.loadFromFile("res/images/EnemyDead.png");

    m_sprite.setTexture(m_movingTexture);


    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(20.0f, 20.0f);

    for (int i = 0; i < m_movingRects.size(); ++i)
    {
        m_movingRects[i] = sf::IntRect{ i * 80, 0, 80, 80 };
    }

    for (int i = 0; i < m_deadRects.size(); ++i)
    {
        m_deadRects[i] = sf::IntRect{ i * 80, 0, 80, 80 };
    }

    m_sprite.setTextureRect(m_movingRects[m_currentFrame]);
    m_sprite.setScale(1.5f, 1.5f);
}

void Enemy::update(const float dt, const sf::Vector2f& playerPosition)
{
    if (enemyDead)
    {
        updateDeadAnimation(dt); 
    }
    else
    {
        updateMove(dt, playerPosition);
        updateMoveAnimation(dt);
    }
}

void Enemy::updateMove(const float dt, const sf::Vector2f& playerPosition)
{
    const sf::Vector2f direction = playerPosition - m_position;
    const float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length < 1.0f) 
    {
        enemyDead = true; 
        m_currentFrame = 0; 
        m_sprite.setTexture(m_deadTexture);
        return;
    }
    
    if (!enemyDead)
    {
        m_direction = direction / length;
        m_position += m_direction * m_speed * dt;
        m_sprite.setPosition(m_position);
    }
}
void Enemy::updateMoveAnimation(const float dt)
{
    if (!enemyDead)
    {
        m_animationTimer += dt;

        if (m_animationTimer >= m_frameDuration)
        {
            m_animationTimer = 0.0f;
            ++m_currentFrame;

            if (m_currentFrame >= m_movingRects.size())
            {
                m_currentFrame = 0;
            }
            m_sprite.setTextureRect(m_movingRects[m_currentFrame]);
        }

        if (m_direction.x > 0)
        {
            m_sprite.setScale(1.5f, 1.5f);
            m_sprite.setOrigin(0.0f, 0.0f);
        }
        else if (m_direction.x < 0)
        {
            m_sprite.setScale(-1.5f, 1.5f);
            m_sprite.setOrigin(80.0f, 0.0f);
        }
    }
}

void Enemy::updateDeadAnimation(const float dt)
{
    m_animationTimer += dt;

    if (m_animationTimer >= m_frameDuration)
    {
        m_animationTimer = 0.0f;
        ++m_currentFrame;

        if (m_currentFrame >= m_deadRects.size())
        {
            m_currentFrame = m_deadRects.size() - 1;
        }
        m_sprite.setTextureRect(m_deadRects[m_currentFrame]);
    }
}

void Enemy::draw(Window* window) const
{
    window->draw(m_sprite);
}