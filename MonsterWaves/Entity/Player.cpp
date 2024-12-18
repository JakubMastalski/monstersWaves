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
    if (m_isMovingLeft)
    {
        m_circleShape.move(-100 * dt, 0);
    }
    else if (m_isMovingRight)
    {
        m_circleShape.move(100 * dt, 0);
    }
    else if (m_isMovingUp)
    {
        m_circleShape.move(0, -100 * dt);
    }
    else if (m_isMovingDown)
    {
        m_circleShape.move(0, 100 * dt);
    }
}

void Player::draw(Window* window)
{
    window->draw(m_circleShape);
}

void Player::control()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->m_isMovingLeft = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->m_isMovingRight = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->m_isMovingUp = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->m_isMovingDown = true;
    }
    else
    {
        this->m_isMovingLeft = false;
        this->m_isMovingRight = false;
        this->m_isMovingUp = false;
        this->m_isMovingDown = false;
    }
}
