#pragma once

#include "Screen/BaseScreen.hpp"
#include "Screen/GameScreen.hpp"
#include "Screen/Window.hpp"
#include "Utils/TimeStep.hpp"
#include <cmath>

class Game
{
public:
    Game();

    void run();
private:
    std::unique_ptr<BaseScreen> m_screen;
    TimeStep m_timeStep;
};