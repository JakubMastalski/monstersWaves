#pragma once

#include "Entity/Enemy.hpp"
#include "Entity/Player.hpp"
#include "Screen/BaseScreen.hpp"
#include "Screen/ScreenType.hpp"
#include <Manager/ScreenManager.hpp>
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

    void resetGameState(Window* window);

private:
    Player m_player;
    TimeStep m_timeStep;

    sf::FloatRect getReducedBounds(const sf::Sprite& sprite, float offset);

private:
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;

    Direction m_playerDirection{ Direction::None };

private:
    std::vector<std::unique_ptr<Enemy>> m_enemies;

private:
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_levelText;
    int  m_score{ 0 };
    int  m_level{ 1 };

    int   m_amountOfEnemies{ 5 };
    float m_enemiesSpeed{ 65.0f };

    sf::RectangleShape fountainRight;
    sf::RectangleShape fountainLeft;

private:
    bool enemiesDead = { false };
};
