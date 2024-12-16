#include "Screen/MenuScreen.hpp"

#include "Manager/ScreenManager.hpp"

MenuScreen::MenuScreen(Window* window) : BaseScreen(window)
{
    m_font.loadFromFile("res/fonts/aleo/Aleo-Italic.otf");
    m_text.setFont(m_font);
    m_text.setString("Menu Screen");
    m_text.setCharacterSize(32);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(static_cast<float>(m_window->getSize().x * 0.5 - m_text.getGlobalBounds().width * 0.5),
        static_cast<float>(m_window->getSize().y * 0.5 - m_text.getGlobalBounds().height));
}

void MenuScreen::handleEvents()
{
    while (m_window->getRenderer().pollEvent(m_event))
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
            {
                m_window->close();
                break;
        case sf::Event::KeyPressed:
            switch (m_event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window->close();
                break;
            case sf::Keyboard::Enter:
                ScreenManager::GetInstance().setScreen(ScreenType::GAME);
                return;
            }
            }
        }
    }
}

void MenuScreen::update(float dt)
{

}

void MenuScreen::render()
{
    m_window->beginDraw(sf::Color::Blue);
    m_window->draw(m_text);
    m_window->endDraw();
}
