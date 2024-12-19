#include "Player.hpp"

Player::Player(const Window* window)
{
    m_movingTexture.loadFromFile("C:/Users/USER/Desktop/monstersWaves/res/images/Run.png");
    m_idleTexture.loadFromFile("C:/Users/USER/Desktop/monstersWaves/res/images/Idle.png");
    m_attackTexture.loadFromFile("C:/Users/USER/Desktop/monstersWaves/res/images/Attack1.png");

    m_sprite.setTexture(m_idleTexture);
    m_sprite.setPosition(
        static_cast<float>(window->getSize().x) * 0.5f - 162 * 0.5f,
        static_cast<float>(window->getSize().y) * 0.5f - 162 * 0.5f
    );

    for (int i = 0; i < m_idleRects.size(); ++i)
    {
        m_idleRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }
    for (int i = 0; i < m_moveLeftRects.size(); ++i)
    {
        m_moveLeftRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
        m_moveRightRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    for (int i = 0; i < m_moveUpRects.size(); ++i)
    {
        m_moveUpRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }
    for (int i = 0; i < m_moveDownRects.size(); ++i)
    {
        m_moveDownRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    m_sprite.setTextureRect(m_idleRects[m_currentFrame]);
}

void Player::update(const float dt)
{
    updateAnimation(dt);
}

void Player::draw(Window* window)
{
    window->draw(m_sprite);
}

void Player::setDirection(const Direction direction, const float dt)
{
    if (direction == Direction::Left)
    {
        moveLeft(dt);
    }
    else if (direction == Direction::Right)
    {
        moveRight(dt);
    }
    else if (direction == Direction::Up)
    {
        moveUp(dt);
    }
    else if (direction == Direction::Down)
    {
        moveDown(dt);
    }
    else
    {
        stopMoving();
    }
}

void Player::moveLeft(float dt)
{
    m_sprite.move(-100 * dt, 0);
    if (!m_isMovingLeft)
    {
        m_isMovingLeft = true;
        m_isMovingRight = false;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);
        m_lastDirection = Direction::Left;

        m_sprite.setScale(-1.0f, 1.0f);
        m_sprite.setOrigin(162.0f, 0.0f);
    }
}

void Player::moveRight(float dt)
{
    m_sprite.move(100 * dt, 0);
    if (!m_isMovingRight)
    {
        m_isMovingRight = true;
        m_isMovingLeft = false;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);
        m_lastDirection = Direction::Right;

        m_sprite.setScale(1.0f, 1.0f);
        m_sprite.setOrigin(0.0f, 0.0f);
    }
}

void Player::moveUp(float dt)
{
    m_sprite.move(0, -100 * dt); 
    if (!m_isMovingUp)
    {
        m_isMovingUp = true;
        m_isMovingDown = false;
        m_isMovingLeft = false;
        m_isMovingRight = false;
        m_isIdle = false;

        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture); 
        m_lastDirection = Direction::Up; 
    }
}

void Player::moveDown(float dt)
{
    m_sprite.move(0, 100 * dt); 
    if (!m_isMovingDown)
    {
        m_isMovingDown = true;
        m_isMovingUp = false;
        m_isMovingLeft = false;
        m_isMovingRight = false;
        m_isIdle = false;

        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);
        m_lastDirection = Direction::Down;
    }
}

void Player::stopMoving()
{
    if (!m_isIdle)
    {
        m_isIdle = true;
        m_isMovingLeft = false;
        m_isMovingRight = false;
        m_isMovingUp = false;
        m_isMovingDown = false;

        m_sprite.setTexture(m_idleTexture);
        m_currentFrame = 0;
    }

    if (m_lastDirection == Direction::Left)
    {
        m_sprite.setScale(-1.0f, 1.0f);
        m_sprite.setOrigin(162.0f, 0.0f);
    }
    else if (m_lastDirection == Direction::Right)
    {
        m_sprite.setScale(1.0f, 1.0f);
        m_sprite.setOrigin(0.0f, 0.0f);
    }
}

void Player::attack()
{
}

sf::FloatRect Player::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

void Player::updateAnimation(const float dt)
{
    m_animationTime += dt;

    if (m_animationTime >= m_frameDuration)
    {
        m_animationTime = 0.0f;

        if (m_isMovingRight)
        {
            m_sprite.setTextureRect(m_moveRightRects[m_currentFrame]);
        }
        else if (m_isMovingLeft)
        {
            m_sprite.setTextureRect(m_moveLeftRects[m_currentFrame]);
        }
        else if (m_isMovingUp)
        {
            m_sprite.setTextureRect(m_moveUpRects[m_currentFrame]);
        }
        else if (m_isMovingDown)
        {
            m_sprite.setTextureRect(m_moveDownRects[m_currentFrame]);
        }
        else if (m_isIdle)
        {
            m_sprite.setTextureRect(m_idleRects[m_currentFrame]);
        }

        ++m_currentFrame;
        if (m_currentFrame >= m_moveRightRects.size())
        {
            m_currentFrame = 0;
        }
    }
}
