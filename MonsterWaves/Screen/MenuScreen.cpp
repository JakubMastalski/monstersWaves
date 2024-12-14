#include "Screen/MenuScreen.hpp"

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
    BaseScreen::handleEvents();
    sf::Event event;

    while (m_window->getRenderer().pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed: switch (event.key.code) {
        case sf::Keyboard::Enter:  
        return; default: break; }
        default: break; 
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
