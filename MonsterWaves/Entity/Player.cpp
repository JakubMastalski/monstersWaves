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
    else if (isMovingUp)
    {
        m_circleShape.move(0, -100 * dt);
    }
    else if (isMovingDown)
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
        this->isMovingLeft = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->isMovingRight = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->isMovingUp = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->isMovingDown = true;
    }
    else
    {
        this->isMovingLeft = false;
        this->isMovingRight = false;
        this->isMovingUp = false;
        this->isMovingDown = false;
    }
}
