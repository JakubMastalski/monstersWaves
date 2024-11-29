#pragma once

#include <SFML/Graphics.hpp>

#include <cmath>
#include <string>

class Window
{
public:
	explicit Window(const sf::Vector2u& windowSize = { 1000, 800 },
                  const std::string& windowTitle = "MonsterWaves" );
	void handleInput();
	void beginDraw(const sf::Color& screenColor = sf::Color::Black);
    void draw(const sf::Drawable& drawable);
	void endDraw();
	
	bool isDone() const;
	sf::Vector2u getSize() const;
    sf::RenderWindow& getRenderer();
private:
	 void setup(const sf::Vector2u& windowSize, const std::string& windowTitle);
	 void create();
	
	 sf::RenderWindow m_renderer;
	 sf::Vector2u m_windowSize;
	 std::string m_windowTitle;
	
	 bool m_isDone{ false };
};
