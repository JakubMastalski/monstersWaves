#include "Game.hpp"
#include "Game.hpp"

Game::Game()
{
    // Empty constructor
}
void Game::run()
{
    while (!m_window.isDone())
    {
        handleEvents();
        // update( 5.0f );
        draw();
    }
}
void Game::handleEvents()
{
    m_window.handleInput();
}
void Game::update(const float& dt)
{
    // Empty body.
}
void Game::draw()
{
    m_window.beginDraw();
    sf::CircleShape circle(std::sin(m_stopwatch.getElapsedTime().asSeconds()) *
        (static_cast<float>(m_window.getSize().x) / 8 +
            static_cast<float>(m_window.getSize().y) / 4)
    );
    circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));
    circle.setPosition(static_cast<float>(m_window.getSize().x) * 0.5f,
        static_cast<float>(m_window.getSize().y) * 0.5f);
    circle.setFillColor(sf::Color::Yellow);
    m_window.draw(circle);
    m_window.endDraw();
}