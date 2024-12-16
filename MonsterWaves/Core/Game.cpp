#include "Game.hpp"

#include "Manager/ScreenManager.hpp"

Game::Game()
{
    ScreenManager::Init();
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

