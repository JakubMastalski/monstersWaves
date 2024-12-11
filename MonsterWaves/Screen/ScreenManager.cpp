#include "ScreenManager.hpp"

ScreenManager::ScreenManager(Window& window): BaseScreen(window)
{
	;
}

void ScreenManager::pushScreen(std::shared_ptr<BaseScreen> screen)
{
	if (screen) {
		m_screens.push(screen);
	}
}

void ScreenManager::popScreen()
{
	if (!m_screens.empty()) {
		m_screens.pop();
	}
}

void ScreenManager::update(float deltaTime)
{

}

void ScreenManager::render()
{
	
}

