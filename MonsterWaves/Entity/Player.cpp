#include "Player.hpp"

Player::Player(const Window* window)
{
    m_circleShape.setRadius(50.0f);
    m_circleShape.setOrigin(
        m_circleShape.getLocalBounds().width * 0.5f,
        m_circleShape.getLocalBounds().height * 0.5f
    );
    m_circleShape.setPosition(
        static_cast<float>(window->getSize().x) * 0.5f,
        static_cast<float>(window->getSize().y) * 0.5f
    );
    m_circleShape.setFillColor(sf::Color::Yellow);
}

void Player::update(const float dt)
{
    if (isMovingLeft)
    {
        m_circleShape.move(-100 * dt, 0);
    }
    else if (isMovingRight)
    {
        m_circleShape.move(100 * dt, 0);
    }
}

void Player::draw(Window* window)
{
    window->draw(m_circleShape);
}