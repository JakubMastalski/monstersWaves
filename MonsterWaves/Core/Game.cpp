#include "Core/Game.hpp"

Game::Game()
{
	//m_screen = new SplashScreen(m_window);
	//m_screen = new MenuScreen(m_window);
	//m_screen = new GameScreen(m_window);
	auto m_window = new Window();

	//m_screen = std::make_unique<InventoryScreen>(m_window);
	//m_screen = std::make_unique<MenuScreen>(m_window);
	//m_screen = std::make_unique<SplashScreen>(m_window);
	m_screen = std::make_unique<GameScreen>(m_window);
}

Game::~Game()
{
	//EMPTY BODY
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


