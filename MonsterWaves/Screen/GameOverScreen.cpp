#include "GameOverScreen.hpp"
#include <Manager/ScreenManager.hpp>

GameOverScreen::GameOverScreen(Window* window) : BaseScreen(window)
{
    m_timeStep.reset();

    m_font.loadFromFile("res/fonts/aleo/Aleo-Italic.otf");
    m_text.setFont(m_font);
    m_text.setString("Gave Over!");
    m_text.setCharacterSize(32);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(static_cast<float>(m_window->getSize().x * 0.5 - m_text.getGlobalBounds().width * 0.5),
        static_cast<float>(m_window->getSize().y * 0.5 - m_text.getGlobalBounds().height));

}
void GameOverScreen::handleEvents()
{
    while (m_window->getRenderer().pollEvent(m_event))
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
            m_window->close();
            break;
        case sf::Event::KeyPressed:
            switch (m_event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window->close();
                break;
            default:
                break;
            }
        }
    }
}
void GameOverScreen::update(float dt)
{
    {
        ScreenManager::GetInstance().setScreen(ScreenType::MENU);
    }
}
void GameOverScreen::render()
{
    m_window->draw(m_text);
    m_window->endDraw();
}