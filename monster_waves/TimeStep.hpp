#pragma once
#include <SFML/System/Clock.hpp>

class TimeStep
{
public:
    TimeStep();
    float getDeltaTime();
    void reset();
private:
    sf::Clock m_clock;
    sf::Time m_lastTime;
};