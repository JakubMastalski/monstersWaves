#include "SplashScreen.hpp"

SplashScreen::SplashScreen(float duration)
	: m_windowDuration(duration)
{
	initWindow();
}

void SplashScreen::update()
{
	float deltaTime = m_timeStep.getDeltaTime();

	if (m_timeStep.getTotalTimeInSeconds() >= m_windowDuration)
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
	m_window.draw(m_text);
	m_window.endDraw();
}

void SplashScreen::handleEvent()
{
	m_window.handleInput();
}

void SplashScreen::initWindow()
{
	m_window.setup({ 1000, 800 }, "Splash Screen");

	if (!font.loadFromFile("bebasFont.ttf")) {
		std::cerr << "The font could not be loaded!" << std::endl;
		return;
	}

	text.setFont(font);
	text.setString("Siema!"); 
	text.setCharacterSize(30); 
	text.setFillColor(sf::Color::White);
	text.setPosition(200, 300);
}
