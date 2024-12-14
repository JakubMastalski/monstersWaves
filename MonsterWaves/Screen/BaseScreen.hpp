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
	virtual void handleEvents();
public:
	bool isRunning() const;
protected:
	std::unique_ptr<Window> m_window;
}; 
	