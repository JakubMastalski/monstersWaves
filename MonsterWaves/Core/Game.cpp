#include "Game.hpp"

void Game::Run()
{
	ScreenManager::Init();
	ScreenManager::GetInstance().run();
}


