#pragma once

#include <SFML/Graphics.hpp>

#include <cmath>
#include <string>

class Window
{
public:
	explicit Window(const sf::Vector2u& windowSize = { 1000, 800 }, const std::string& windowTitle = "MonsterWaves");
             ~Window();
public:
    void create();
    void destroy();

public:
    void handleEvents();
    void beginDraw(const sf::Color& screenColor = sf::Color::Black);
    void draw(const sf::Drawable& drawable);
    void endDraw();

public:
    bool isRunning() const;
    void close();

public:
    sf::Vector2u getSize() const;
    sf::RenderWindow& getRenderer();

private:
    void setup(const sf::Vector2u& windowSize, const std::string& windowTitle);

private:
	 sf::RenderWindow m_renderer;
	 sf::Vector2u m_Size;
	 std::string m_Title;
	
	 bool m_isRunning{ true };
};
