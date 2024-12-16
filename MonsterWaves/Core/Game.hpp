#pragma once

#include "Utils/TimeStep.hpp"

class Game
{
public:
    Game();
    ~Game();

public:
    void run();

private:
    TimeStep m_timeStep;
};
