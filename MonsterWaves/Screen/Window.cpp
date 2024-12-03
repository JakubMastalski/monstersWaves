#include "Screen/Window.hpp"

Window::Window(const sf::Vector2u& windowSize, const std::string& windowTitle)
{
    setup(windowSize, windowTitle);
}

void Window::handleEvents()
{
    sf::Event event{};
    while (m_renderer.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                close();
            }
            break;
        }
    }
}

void Window::beginDraw(const sf::Color& screenColor)
{
    m_renderer.clear(screenColor);
}

void Window::draw(const sf::Drawable& drawable)
{
    m_renderer.draw(drawable);
}

void Window::endDraw()
{
    m_renderer.display();
}

void Window::close()
{
    m_isRunning = false;
    m_renderer.close();
}

bool Window::isRunning() const
{
    return m_isRunning;
}

sf::Vector2u Window::getSize() const
{
    return m_windowSize;
}

sf::RenderWindow& Window::getRenderer()
{
    return m_renderer;
}

void Window::setup(const sf::Vector2u& windowSize, const std::string& windowTitle)
{
    m_windowSize = windowSize;
    m_windowTitle = windowTitle;
    create();
}

void Window::create()
{
    constexpr auto style = sf::Style::Default;

    m_renderer.create({ m_windowSize.x, m_windowSize.y }, m_windowTitle, style);
    m_renderer.setFramerateLimit( 60 );
}
