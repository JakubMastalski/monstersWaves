#include "Core/Game.hpp"
#include "Screen/SplashScreen.hpp"
#include "Screen/MenuScreen.hpp"

Game::Game()
{
	//m_screen = new SplashScreen(m_window);
	//m_screen = new MenuScreen(m_window);
	m_screen = new GameScreen(m_window);
}

Game::~Game()
{
	delete m_screen;
}

void Game::run()
{
	while (m_screen->isRunning())
	{
		const float deltaTime = m_timeStep.getDeltaTime();

		m_screen->handleEvents();
		m_screen->update(deltaTime);
		m_screen->render();
	}
}


