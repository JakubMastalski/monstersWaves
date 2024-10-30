#pragma once
#include "Window.hpp"
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
    Window m_window;
    const sf::Clock m_stopwatch{};
};