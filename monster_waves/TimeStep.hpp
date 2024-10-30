#pragma once
#include <SFML/System/Clock.hpp>

class TimeStep
{
public:
    TimeStep();
    float getDeltaTime();
    void reset();
    float getTotalTimeInSeconds() const;
    sf::Int32 getTotalTimeInMilliseconds() const;
    sf::Int64 getTotalTimeInMicroseconds() const;
private:
    sf::Clock m_clock;
    sf::Time m_lastTime;
};