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

    sf::Vector2f blockSize(170.f, 130.f);
    block1.setSize(blockSize);
    block2.setSize(blockSize);

    sf::Vector2f block3Size(40.f, 40.f);

    block3.setSize(block3Size);

    block1.setFillColor(sf::Color::Red);
    block2.setFillColor(sf::Color::Blue);
    block3.setFillColor(sf::Color::Green);

    float windowWidth = 1000.f;
    float windowHeight = 800.f;
    float gapBetweenBlocks = 75.f; 

    float totalWidth = (blockSize.x * 2) + gapBetweenBlocks;
    float startX = (windowWidth - totalWidth) / 2.f;
    float centerY = (windowHeight - blockSize.y) / 2.f;

    block1.setPosition(startX - 30, centerY + 110);
    block2.setPosition(startX + blockSize.x + gapBetweenBlocks + 30, centerY + 110);
    block3.setPosition(startX + 190, centerY - 50);

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
            m_window->close();
            break;
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
    sf::FloatRect playerBounds = m_player.getBounds();
    sf::FloatRect block1Bounds = block1.getGlobalBounds();
    sf::FloatRect block2Bounds = block2.getGlobalBounds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerBounds.left > 30)
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.left -= m_player.getSpeed();
        if (!futureBounds.intersects(block1Bounds) && !futureBounds.intersects(block2Bounds))
        {
            if (m_playerDirection != Direction::None) isMovingDiagonally = true;
            m_playerDirection = Direction::Left;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        (playerBounds.left + playerBounds.width < 970))
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.left += m_player.getSpeed();
        if (!futureBounds.intersects(block1Bounds) && !futureBounds.intersects(block2Bounds))
        {
            if (m_playerDirection != Direction::None) isMovingDiagonally = true;
            m_playerDirection = Direction::Right;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerBounds.top > 150)
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.top -= m_player.getSpeed();
        if (!futureBounds.intersects(block1Bounds) && !futureBounds.intersects(block2Bounds))
        {
            if (m_playerDirection != Direction::None) isMovingDiagonally = true;
            m_playerDirection = Direction::Up;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        (playerBounds.top + playerBounds.height < 800))
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.top += m_player.getSpeed();
        if (!futureBounds.intersects(block1Bounds) && !futureBounds.intersects(block2Bounds))
        {
            if (m_playerDirection != Direction::None) isMovingDiagonally = true;
            m_playerDirection = Direction::Down;
        }
    }

    if (isMovingDiagonally)
    {
        sf::FloatRect futureBounds = playerBounds;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            futureBounds.left += m_player.getSpeed();
            futureBounds.top -= m_player.getSpeed();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            futureBounds.left -= m_player.getSpeed();
            futureBounds.top -= m_player.getSpeed();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            futureBounds.left += m_player.getSpeed();
            futureBounds.top += m_player.getSpeed();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            futureBounds.left -= m_player.getSpeed();
            futureBounds.top += m_player.getSpeed();
        }

        if (futureBounds.intersects(block1Bounds) || futureBounds.intersects(block2Bounds))
        {
            m_playerDirection = Direction::None; 
        }
    }
}



void GameScreen::resetGameState(Window* window)
{
    m_level = 1;
    m_levelText.setString("Level  " + std::to_string(m_level));
    m_scoreText.setString("0");

    m_enemies.clear();
    m_amountOfEnemies = 5;
    m_enemiesSpeed = 65.0f;

    m_player.resetPlayer(window);

    for (int i = 0; i < m_amountOfEnemies; ++i)
    {
        if (i < m_enemies.size()) {
            m_enemies[i]->resetEnemy(window, m_player.getPosition());
        }
        else {
            m_enemies.push_back(std::make_unique<Enemy>(window, m_player.getPosition(), m_enemiesSpeed));
        }
    }
    

}

void GameScreen::update(float dt)
{

    if (m_player.getLives() <= 0)
    {
        resetGameState(m_window.get());
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
        if (enemy->checkCollisionWithPlayer(m_player.getSprite()) &&
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
            m_player.setSpeed(m_player.getSpeed() * 1.1f);
        }
    }
}

void GameScreen::render()
{
    m_window->beginDraw();

    m_window->draw(m_backgroundSprite);

    m_window->draw(m_scoreText);
    m_window->draw(m_levelText);

    m_window->draw(block1);
    m_window->draw(block2);
    m_window->draw(block3);

    m_player.draw(m_window.get());

    for (auto& enemy : m_enemies)
    {
        if (!enemy->enemyisDead) enemy->draw(m_window.get());
    }

    for (auto& enemy : m_enemies)
    {
        if (!enemy->enemyisDead) enemy->draw(m_window.get());
    }

    m_window->endDraw();
}
