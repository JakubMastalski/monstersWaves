#pragma once

#include "Screen/GameScreen.hpp"
#include "Screen/BaseScreen.hpp"
#include "Screen/Window.hpp"
#include "Utils/TimeStep.hpp"


#include <cmath>

class Game
{
public:
    Game();
    ~Game();

    void run();
private:
    BaseScreen* m_screen;
    Window m_window;
    TimeStep m_timeStep;
};