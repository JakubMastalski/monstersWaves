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
	void setup(const sf::Vector2u& windowSize, const std::string& windowTitle);

	bool isDone() const;
	sf::Vector2u getSize() const;
    sf::RenderWindow& getRenderer();
private:
	 void create();
	
	 sf::RenderWindow m_renderer;
	 sf::Vector2u m_windowSize;
	 std::string m_windowTitle;
	
	 bool m_isDone{ false };
};
