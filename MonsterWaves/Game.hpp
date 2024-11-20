#pragma once
#include "Window.hpp"
#include "TimeStep.hpp"
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
    Window m_window;
    TimeStep m_timeStep;
    const sf::Clock m_stopwatch{};
};