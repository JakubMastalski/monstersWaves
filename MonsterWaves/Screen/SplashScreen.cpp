#include "SplashScreen.hpp"

SplashScreen::SplashScreen(Window window, float duration)
	: m_window(std::move(window)), m_windowDuration(duration)
{
	m_window.setup({ 800, 600 }, "Splash Screen");
}

void SplashScreen::update()
{
	float deltaTime = m_timeStep.getDeltaTime();

	if (m_timeStep.getTotalTimeInSeconds() >= windowDuration)
	{
		m_window.close();
	}
}

void SplashScreen::render()
{
	while (!m_window.isDone())
	{
		draw();
		handleEvent();
		update();
	}
}

void SplashScreen::draw()
{
	m_window.beginDraw();
	m_window.draw()
	m_window.endDraw();
}

void SplashScreen::handleEvent()
{
	m_window.handleInput();
}

void SplashScreen::initWindow()
{

}
