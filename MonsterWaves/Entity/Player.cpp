#include "Player.hpp"

Player::Player(const Window* window)
{
    m_movingTexture.loadFromFile("res/images/Run.png");
    m_idleTexture.loadFromFile("res/images/Idle.png");
    m_attackTexture.loadFromFile("res/images/Attack1.png");

    m_sprite.setTexture(m_idleTexture);
    m_sprite.setPosition(
        static_cast<float>(window->getSize().x) * 0.5f,
        static_cast<float>(window->getSize().y) * 0.5f
    );

    for (int i = 0; i < m_idleRects.size(); ++i)
    {
        m_idleRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }
}

void Player::update(const float dt)
{
    updateAnimation(dt);

    // if( !m_isMovingLeft && !m_isMovingRight )
    // {
    //     m_isIdle = true;
    // }
    // if( m_isMovingLeft )
    // {
    //     m_circleShape.move( -100 * dt, 0 );
    // }
    // else if( m_isMovingRight )
    // {
    //     m_circleShape.move( 100 * dt, 0 );
    // }
}

void Player::draw(Window* window)
{
    window->draw(m_sprite);
}

void Player::moveLeft(float dt)
{
}

void Player::moveRight(float dt)
{
}

void Player::stopMoving()
{
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
    m_sprite.setTextureRect(m_idleRects[m_currentFrame]);

    ++m_currentFrame;
    if (m_currentFrame >= m_idleRects.size())
    {
        m_currentFrame = 0;
    }
}
