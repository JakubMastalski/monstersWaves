#include "Screen/GameScreen.hpp"

GameScreen::GameScreen(Window* window) :
    BaseScreen(window), m_player({ window })
{
    m_enemies.reserve(60);

    m_backgroundTexture.loadFromFile("res/images/map.png");

    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_backgroundSprite.setScale(
        static_cast<float>(m_window->getSize().x) / m_backgroundTexture.getSize().x,
        static_cast<float>(m_window->getSize().y) / m_backgroundTexture.getSize().y
    );

    for (int i = 0; i < m_amountOfEnemies; ++i)
    {
        m_enemies.push_back(std::make_unique<Enemy>(window, m_player.getPosition(), m_enemiesSpeed));
    }  

    m_font.loadFromFile("res/fonts/aleo/Aleo-Italic.otf");
    m_scoreText.setFont(m_font);
    m_scoreText.setString("0");
    m_scoreText.setCharacterSize(26);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(
        static_cast<float>(m_window->getSize().x *
            0.5 - m_scoreText.getGlobalBounds().width * 0.5), 20);
    m_levelText.setFont(m_font);
    m_levelText.setString("Level  " +std::to_string(m_level));
    m_levelText.setCharacterSize(26);
    m_levelText.setFillColor(sf::Color::White);
    m_levelText.setPosition(
        static_cast<float>(m_window->getSize().x - m_levelText.getGlobalBounds().width * 0.5 - 60),
        10);
}

void GameScreen::handleEvents()
{

    while (m_window->getRenderer().pollEvent(m_event))
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
        {
            m_window->close();
            break;
        }
        case sf::Event::KeyPressed:
            switch (m_event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window->close();
                break;
            case sf::Keyboard::Space:
                if (m_player.getIdle())
                {
                    m_player.attack();
                }
                break;
            case sf::Keyboard::I:
                // Open Inventory Screen
                return;
            }
        }
    }

    m_playerDirection = Direction::None;

    bool isMovingDiagonally = false;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_player.getBounds().left > -50)
    {
        if (m_playerDirection != Direction::None) isMovingDiagonally = true;
        m_playerDirection = Direction::Left;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (m_player.getBounds().left + m_player.getBounds().width < 1050))
    {
        if (m_playerDirection != Direction::None) isMovingDiagonally = true;
        m_playerDirection = Direction::Right;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_player.getBounds().top > -50)
    {
        if (m_playerDirection != Direction::None) isMovingDiagonally = true;
        m_playerDirection = Direction::Up;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (m_player.getBounds().top + m_player.getBounds().height < 850))
    {
        if (m_playerDirection != Direction::None) isMovingDiagonally = true;
        m_playerDirection = Direction::Down;
    }

    if (isMovingDiagonally)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m_playerDirection = Direction::Diagonaly_UpRight;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            m_playerDirection = Direction::Diagonaly_UpLeft;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m_playerDirection = Direction::Diagonaly_DownRight;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            m_playerDirection = Direction::Diagonaly_DownLeft;
        }
    }

}

void GameScreen::update(float dt)
{

    if (m_player.getLives() < 0)
    {
        ScreenManager::GetInstance().setScreen(ScreenType::GAMEOVER);
        return;
    }

    m_player.setDirection(m_playerDirection, dt);
    m_player.update(dt);

    for (auto& enemy : m_enemies)
    {
        enemy->update(dt, m_player.getPosition(),
            { m_player.getBounds().width / 2 , m_player.getBounds().height - 100 });

        if (enemy->checkCollisionWithPlayerAttack(m_player.getSprite())
            && m_player.isAttacking()
            && enemy->enemyState != EnemyDead)
        {
            enemy->enemyDie();
            m_score += 20;
            m_scoreText.setString(std::to_string(m_score));
        }
        else if (enemy->checkCollisionWithPlayer(m_player.getSprite()) &&
            !m_player.isAttacking() &&
            enemy->enemyState != EnemyDead &&
            enemy->attackCasted)
        {
            m_player.loseLife();
            enemy->attackCasted = false;
        }
    }

    m_enemies.erase(
        std::remove_if(m_enemies.begin(), m_enemies.end(),
            [&](const std::unique_ptr<Enemy>& enemy)
            {
                return (enemy->enemyState == EnemyDead && enemy->enemyisDead);
            }),
        m_enemies.end());

    if (m_enemies.empty())
    {
        ++m_level;
        m_levelText.setString("Level " + std::to_string(m_level));

        if (m_level % 2 == 0)
        {
            m_amountOfEnemies *= 1.6;
        }
        else
        {
            m_enemiesSpeed *= 1.6f;
        }

        for (int i = 0; i < m_amountOfEnemies; ++i)
        {
            m_enemies.push_back(std::make_unique<Enemy>(m_window.get(), m_player.getPosition(), m_enemiesSpeed));
        }

        if (m_level % 3 == 0)
        {
            m_player.setSpeed(m_player.getSpeed() * 1.5f);
        }
    }
}

void GameScreen::render()
{
    m_window->beginDraw();

    m_window->draw(m_backgroundSprite);

    m_window->draw(m_scoreText);
    m_window->draw(m_levelText);


    m_player.draw(m_window.get());

    for (const auto& enemy : m_enemies)
    {
        if (!enemy->enemyisDead) enemy->draw(m_window.get());
    }

    m_window->endDraw();
}
