#include "Screen/GameScreen.hpp"

GameScreen::GameScreen(Window* window) : BaseScreen(window)
{
    m_circle.setRadius(0.0f);
    m_circle.setPosition(
        static_cast<float>(m_window->getSize().x) * 0.5f,
        static_cast<float>(m_window->getSize().y) * 0.5f
    );
    m_circle.setFillColor(sf::Color::Yellow);
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
}

void GameScreen::update(float dt)
{
    m_circle.setRadius(std::sin(m_timeStep.getTotalTimeInSeconds()) *
        static_cast<float>(m_window->getSize().x) / 8 +
        static_cast<float>(m_window->getSize().y) / 4);
    m_circle.setOrigin(sf::Vector2f(m_circle.getRadius(), m_circle.getRadius()));
}

void GameScreen::render()
{
    m_window->beginDraw();
    m_window->draw(m_circle);
    m_window->endDraw();
}
