#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Przyk³ad SFML");

    sf::RectangleShape rectangle(sf::Vector2f(200.f, 150.f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(300.f, 225.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(rectangle);

        window.display();
    }

    return 0;
}