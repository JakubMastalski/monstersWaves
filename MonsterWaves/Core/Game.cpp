#include "Game.hpp"

Game::Game()
{
    m_circle.setRadius(100.0f);
    m_circle.setPosition(static_cast<float>(m_window.getSize().x) * 0.5f,
        static_cast<float>(m_window.getSize().y) * 0.5f);
    m_circle.setFillColor(sf::Color::Yellow);
}
void Game::run()
{
    splashScreen.render();

    if (splashScreen.getsplashIsDone())
    {
        const float deltaTime = m_timeStep.getDeltaTime();
        while (!m_window.isDone())
        {
            handleEvents();
            update(deltaTime);
            draw();
        }
    }
}
void Game::handleEvents()
{
    m_window.handleInput();
}
void Game::update(const float& dt)
{
    m_circle.setRadius(std::sin(m_timeStep.getTotalTimeInSeconds()) *
        static_cast<float>(m_window.getSize().x) / 8 +
        static_cast<float>(m_window.getSize().y) / 4);
    m_circle.setOrigin(sf::Vector2f(m_circle.getRadius(), m_circle.getRadius()));
}
void Game::draw()
{
    m_window.beginDraw();
    m_window.draw(m_circle);
    m_window.endDraw();
}