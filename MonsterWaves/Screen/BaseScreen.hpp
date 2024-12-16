#pragma once

#include "Screen/Window.hpp"

#include "memory"

class BaseScreen
{
public:
	BaseScreen(Window* window);
	virtual ~BaseScreen() = default;
public:
	virtual void update(float dt) = 0;
	virtual void render() = 0;
	virtual void handleEvents() = 0;
public:
	bool isRunning() const;
protected:
<<<<<<< HEAD
	std::unique_ptr< Window >   m_window;
=======
	std::unique_ptr<Window> m_window;
>>>>>>> develop
	sf::Event m_event{};
}; 
	