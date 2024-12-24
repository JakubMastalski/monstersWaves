#pragma once

#include "Screen/BaseScreen.hpp"
#include "Utils/TimeStep.hpp"

class SplashScreen final : public BaseScreen
{
public:
    explicit SplashScreen(Window* window, float duration = 1.0f);
public:
    void handleEvents() override;
    void update(float dt) override;
    void render() override;
private:
    TimeStep    m_timeStep;
    sf::Font    m_font;
    sf::Text    m_text;
    float       m_duration;
};