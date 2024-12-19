#include "Screen/GameScreen.hpp"

GameScreen::GameScreen(Window* window) : BaseScreen(window), m_player({ window })
{
   //EMPTY BODY
}

void GameScreen::handleEvents()
{

    while (m_window->getRenderer().pollEvent(m_event))
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
        {
            m_window->close();
            break;
        }
        case sf::Event::KeyPressed:
            switch (m_event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window->close();
                break;
            case sf::Keyboard::Space:
                m_player.attack();
                break;
            case sf::Keyboard::I:
                // Open Inventory Screen
                return;
            }
        }
    }

    m_playerDirection = Direction::None;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_playerDirection = Direction::Left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_playerDirection = Direction::Right;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_playerDirection = Direction::Up;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_playerDirection = Direction::Down;
    }
}

void GameScreen::update(float dt)
{
    m_player.setDirection(m_playerDirection, dt);
    m_player.update(dt);
}

void GameScreen::render()
{
    m_window->beginDraw();

    m_player.draw(m_window.get());

    m_window->endDraw();
}
