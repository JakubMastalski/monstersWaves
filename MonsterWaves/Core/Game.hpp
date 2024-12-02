#pragma once
#include "Screen/SplashScreen.hpp"
#include "Screen/Window.hpp"
#include "Utils/TimeStep.hpp"
#include <cmath>

class Game
{
public:
    Game();
    void run();
private:
    void handleEvents();
    void update(const float& dt);
    void draw();

    sf::CircleShape m_circle;
    SplashScreen splashScreen;
    Window m_window;
    TimeStep m_timeStep;
    const sf::Clock m_stopwatch{};
};