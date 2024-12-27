#pragma once

#include "Entity/Enemy.hpp"
#include "Entity/Player.hpp"
#include "Screen/BaseScreen.hpp"
#include "Utils/TimeStep.hpp"

#include <cmath>
#include <vector>

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

    std::vector<std::unique_ptr<Enemy>> m_enemies;
    int   m_amountOfEnemies{ 5 };
    float m_enemiesSpeed{ 65.0f };
private:
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_levelText;
    int  m_score{ 0 };
    int  m_level{ 1 };

    bool enemiesDead = { false };
};
