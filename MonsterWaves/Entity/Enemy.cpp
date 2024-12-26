#include "Enemy.hpp"
#include "Utils/RandomGenerator.hpp"

Enemy::Enemy(const Window* window, const sf::Vector2f& playerPosition, const float speed)
    : m_speed(speed)
{
    RandomNumber randomGenerator;

    const int side = randomGenerator.getNumber(0, 1) == 0 ? -1 : 1;
    const float startX = side == -1
        ? -20.0f
        : static_cast<float>(window->getSize().x) + 20.0f;

    const float startY = static_cast<float>(
        randomGenerator.getNumber(0, static_cast<int>(window->getSize().y))
        );

    m_position = sf::Vector2f{ startX, startY };

    const sf::Vector2f direction = playerPosition - m_position;
    const float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    m_direction = direction / length;

    m_movingTexture.loadFromFile("res/images/EnemyRun.png");
    m_deadTexture.loadFromFile("res/images/EnemyDead.png");
    m_attackTexture.loadFromFile("res/images/EnemyAttack.png");

    m_sprite.setTexture(m_movingTexture);


    m_sprite.setPosition(m_position);

    for (int i = 0; i < m_movingRects.size(); ++i)
    {
        m_movingRects[i] = sf::IntRect{ i * 80, 0, 80, 80 };
    }

    for (int i = 0; i < m_deadRects.size(); ++i)
    {
        m_deadRects[i] = sf::IntRect{ i * 80, 0, 80, 80 };
    }

    for (int i = 0; i < m_attackRects.size(); ++i)
    {
        m_attackRects[i] = sf::IntRect{ i * 80, 0, 80, 80 };
    }

    m_sprite.setTextureRect(m_movingRects[m_currentFrame]);
    m_sprite.setScale(1.5f, 1.5f);
}

void Enemy::update(float dt, const sf::Vector2f& playerPosition, const sf::Vector2f& playerSize)
{
    switch (enemyState)
    {
    case EnemyState::EnemyMoving:

        updateMove(dt, playerPosition,playerSize);
        updateMoveAnimation(dt);

        break;
    case EnemyState::EnemyAttacking:
        updateAttackAnimation(dt, playerPosition, playerSize);

        break;
    case EnemyState::EnemyDead:
        updateDeadAnimation(dt);

        break;
    default:
        break;
    }
}

void Enemy::updateMove(const float dt, const sf::Vector2f& playerPosition, const sf::Vector2f& playerSize)
{
    const sf::Vector2f playerCenter = playerPosition + playerSize * 0.5f;

    const sf::Vector2f newDirection = playerCenter - m_position;
    const float length = std::sqrt(newDirection.x * newDirection.x + newDirection.y * newDirection.y);

    if (length > 40.0f)
    {
        const sf::Vector2f normalizedDirection = newDirection / length;

        m_direction = m_direction + (normalizedDirection - m_direction) * 0.1f;

        m_position += m_direction * m_speed * dt;

        m_sprite.setPosition(m_position);
    }
    else
    {
        enemyState = EnemyAttacking;
        m_sprite.setTexture(m_attackTexture);
    }
}
void Enemy::updateMoveAnimation(const float dt)
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

        if (m_direction.x < 0)
        {
            m_sprite.setScale(-1.5f, 1.5f);
            m_sprite.setOrigin(80.0f, 0.0f);
        }
}

void Enemy::updateAttackAnimation(const float dt,const sf::Vector2f& playerPosition, const sf::Vector2f& playerSize)
{
    const sf::Vector2f playerCenter = playerPosition + playerSize * 0.5f;

    const sf::Vector2f newDirection = playerCenter - m_position;
    const float length = std::sqrt(newDirection.x * newDirection.x + newDirection.y * newDirection.y);
         
    if (length > 80)
    {
        enemyState = EnemyState::EnemyMoving;
        m_sprite.setTexture(m_movingTexture);
        return;
    }

    m_animationTimer += dt;
    if (m_animationTimer >= m_frameDuration)
    {
        m_animationTimer = 0.0f;
        ++m_currentFrame;

        if (m_currentFrame >= m_attackRects.size())
        {
            m_currentFrame = 0;

        }

        m_sprite.setTextureRect(m_attackRects[m_currentFrame]);
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

bool Enemy::checkCollisionWithPlayer(const sf::Sprite& player) const
{
    const sf::FloatRect enemyBounds = m_sprite.getGlobalBounds();
    const sf::FloatRect playerBounds = player.getGlobalBounds();
    return enemyBounds.intersects(playerBounds);
}

bool Enemy::checkCollisionWithPlayerAttack(const sf::Sprite& player) const
{
    const sf::FloatRect enemyBounds = m_sprite.getGlobalBounds();
    const sf::FloatRect playerAttackBounds = player.getGlobalBounds();
    return enemyBounds.intersects(playerAttackBounds);
}

void Enemy::enemyDie()
{
    enemyState = EnemyState::EnemyDead;
    m_currentFrame = 0;
    m_sprite.setTexture(m_deadTexture);
}