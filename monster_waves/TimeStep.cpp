#include "TimeStep.hpp"

TimeStep::TimeStep() : m_lastTime(m_clock.getElapsedTime())
{
    // Empty body
}
float TimeStep::getDeltaTime()
{
    const sf::Time currentTime = m_clock.getElapsedTime();
    const sf::Time deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;
    return deltaTime.asSeconds();
}

void TimeStep::reset()
{
    m_lastTime = m_clock.restart();
}

float TimeStep::getTotalTime() const
{
    return m_clock.getElapsedTime().asSeconds();
}
