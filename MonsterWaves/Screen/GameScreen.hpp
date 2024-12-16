#pragma once

#include "Entity/Player.hpp"
#include "Screen/BaseScreen.hpp"
#include "Utils/TimeStep.hpp"

#include <cmath>

class GameScreen final : public BaseScreen
{
public:
	explicit GameScreen(Window* window);

public:
    void handleEvents() override;
    void update(float dt) override;
    void render() override;

private:
    Player m_player;
    TimeStep m_timeStep;
};
