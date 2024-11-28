#include "Window.hpp"

class BaseScreen
{
public:
	virtual BaseScreen() = default;
	virtual ~BaseScreen() = default;
protected:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvent() = 0;
private:
	Window m_window;
}; 
	