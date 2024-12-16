#include "SplashScreen.hpp"

#include "Manager/ScreenManager.hpp"

SplashScreen::SplashScreen(Window* window, const float duration) : BaseScreen(window), m_duration(duration)
{
    m_font.loadFromFile("res/fonts/aleo/Aleo-Light.otf");
    m_text.setFont(m_font);
    m_text.setString("Welcome to the Game!");
    m_text.setCharacterSize(64);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(static_cast<float>(m_window->getSize().x * 0.5 - m_text.getGlobalBounds().width * 0.5),
        static_cast<float>(m_window->getSize().y * 0.5 - m_text.getGlobalBounds().height * 0.5));
}
void SplashScreen::handleEvents()
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
void SplashScreen::update(const float dt)
{
    if (m_timeStep.getTotalTimeInSeconds() >= m_duration)
    {
        ScreenManager::GetInstance().setScreen(ScreenType::MENU);
    }
}
void SplashScreen::render()
{
    m_window->beginDraw();

    m_window->draw(m_text);
    m_window->endDraw();
}