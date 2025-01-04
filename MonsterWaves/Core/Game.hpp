#pragma once

#include "Utils/TimeStep.hpp"

class Game
{
public:
    Game();

public:
    void run();

private:
    TimeStep m_timeStep;
};
