#include "Screen/InventoryScreen.hpp"

#include <random>

InventoryScreen::InventoryScreen(std::unique_ptr<Window> window) : BaseScreen(std::move(window))
{
    constexpr int   gridSize{ 100 };
    constexpr float radius{ gridSize * 0.25 };
    std::vector colors = { sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Red };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, static_cast<int>(colors.size() - 1));
    for (int x = 0; x < m_window->getSize().x; x += gridSize)
    {
        for (int y = 0; y < m_window->getSize().y; y += gridSize)
        {
            sf::RectangleShape square(sf::Vector2f(gridSize, gridSize));
            square.setPosition(static_cast<float>(x), static_cast<float>(y));
            square.setOutlineColor(sf::Color::Black);
            square.setOutlineThickness(1);
            square.setFillColor(sf::Color::White);
            m_squares.push_back(square);
            sf::CircleShape circle(radius);
            sf::Color randomColor = colors[distribution(gen)];
            circle.setFillColor(randomColor);
            circle.setOrigin(radius, radius);
            circle.setPosition(static_cast<float>(x + gridSize * 0.5),
                static_cast<float>(y + gridSize * 0.5));
            m_circles.push_back(circle);
        }
    }
}
void InventoryScreen::handleEvents()
{
    // Window events
    m_window->handleEvents();

    // Screen individual events
    sf::Event event{};

    while (m_window->getRenderer().pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::G:
                // Back to the Game Screen
                return;

            default:
                break;
            }
        }
    }
}
void InventoryScreen::update(const float dt)
{
    // Empty body.
}
void InventoryScreen::render()
{
    m_window->beginDraw();
    for (const auto& square : m_squares)
    {
        m_window->draw(square);
    }
    for (const auto& circle : m_circles)
    {
        m_window->draw(circle);
    }
    m_window->endDraw();
}