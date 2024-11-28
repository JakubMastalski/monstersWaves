#include "Window.hpp"

class Screen
{
public:
	virtual Screen() = default;
	virtual void update(Window& window) = 0;
	virtual void render(Window& window) = 0;
	virtual void handleEvent(sf::Event& event, Window& window) = 0;
}; 
	