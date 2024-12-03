#pragma once

#include "Screen/Window.hpp"

class BaseScreen
{
public:
	explicit BaseScreen(Window* window);
	virtual ~BaseScreen() = default;
protected:
	virtual void update(float dt) = 0;
	virtual void render() = 0;
	virtual void handleEvent() = 0;
public:
	bool isRunning() const;
protected:
	Window* m_window;
}; 
	