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
            case sf::Keyboard::I:
                // Open Inventory Screen
                return;
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_player.isMovingLeft = true;
        m_player.isMovingRight = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_player.isMovingRight = true;
        m_player.isMovingLeft = false;
    }
    else
    {
        m_player.isMovingLeft = false;
        m_player.isMovingRight = false;
    }
}

void GameScreen::update(float dt)
{
    m_player.update(dt);
}

void GameScreen::render()
{
    m_window->beginDraw();

    m_player.draw(m_window.get());

    m_window->endDraw();
}
