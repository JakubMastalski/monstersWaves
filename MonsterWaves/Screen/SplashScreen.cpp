#include "SplashScreen.hpp"

SplashScreen::SplashScreen(float duration)
	: m_windowDuration(duration)
{
	initWindow();
}

void SplashScreen::update()
{
	float deltaTime = m_timer.getDeltaTime();

	if (m_timer.getTotalTimeInSeconds() >= m_windowDuration)
	{
		m_window.getRenderer().close();
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
	m_window.setup(sf::Vector2u(1000, 800), "Splash Screen");

	if (!m_font.loadFromFile("bebasFont.ttf")) {
		std::cerr << "The font could not be loaded!" << std::endl;
		return;
	}

	m_text.setFont(m_font);
	m_text.setString("Siema!"); 
	m_text.setCharacterSize(30); 
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(200, 300);
}
