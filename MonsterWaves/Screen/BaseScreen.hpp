#include "Screen/Window.hpp"

class BaseScreen
{
public:
	BaseScreen() = default;
	virtual ~BaseScreen() = default;
protected:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual void handleEvent() = 0;
protected:
	Window m_window;
}; 
	