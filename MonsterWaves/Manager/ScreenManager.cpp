#include "ScreenManager.hpp"

#include <Screen/GameScreen.hpp>
#include <Screen/GameOverScreen.hpp>
#include <Screen/MenuScreen.hpp>
#include <Screen/SplashScreen.hpp>

#include <cassert>

static ScreenManager* s_Instance = nullptr;

void ScreenManager::Init()
{
    assert(!s_Instance);

    s_Instance = new ScreenManager();
}

void ScreenManager::ShutDown()
{
    delete s_Instance;
    s_Instance = nullptr;
}

ScreenManager& ScreenManager::GetInstance()
{
    assert(s_Instance);

    return *s_Instance;
}

ScreenManager::ScreenManager()
{
    auto* mainWindow = new Window();

    m_screens[ScreenType::SPLASH] = std::make_unique< SplashScreen >(mainWindow);
    m_screens[ScreenType::MENU] = std::make_unique< MenuScreen >(mainWindow);
    m_screens[ScreenType::GAME] = std::make_unique< GameScreen >(mainWindow);
    m_screens[ScreenType::GAMEOVER] = std::make_unique< GameOverScreen >(mainWindow);

    mainWindow->create();

    m_activeScreen = m_screens[ScreenType::SPLASH].get();
}

void ScreenManager::setScreen(const ScreenType screenType)
{
    m_activeScreen = m_screens[screenType].get();
}

bool ScreenManager::isRunning() const
{
    return m_activeScreen->isRunning();
}

void ScreenManager::handleEvents() const
{
    m_activeScreen->handleEvents();
}

void ScreenManager::update(const float dt) const
{
    m_activeScreen->update(dt);
}

void ScreenManager::render() const
{
    m_activeScreen->render();
}