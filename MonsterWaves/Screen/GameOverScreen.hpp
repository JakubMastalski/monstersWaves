#pragma once

#include "Screen/BaseScreen.hpp"
#include "Utils/TimeStep.hpp"

class GameOverScreen final : public BaseScreen
{
public:
    explicit GameOverScreen(Window* window);

public:
    void handleEvents() override;
    void update(float dt) override;
    void render() override;

private:
    TimeStep  m_timeStep;
    sf::Font  m_font;
    sf::Text  m_text;
};