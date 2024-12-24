#pragma once

#include "Entity/Enemy.hpp"
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
    Direction m_playerDirection{ Direction::None };

    Enemy m_enemy;
};
