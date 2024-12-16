#include "Game.hpp"

#include "Manager/ScreenManager.hpp"

Game::Game()
{
    ScreenManager::Init();
}

Game::~Game()
{
    // Bug to fix
    // ScreenManager::ShutDown();
}

void Game::run()
{
    while (ScreenManager::GetInstance().isRunning())
    {
        const float deltaTime = m_timeStep.getDeltaTime();
        ScreenManager::GetInstance().handleEvents();
        ScreenManager::GetInstance().update(deltaTime);
        ScreenManager::GetInstance().render();
    }
}

