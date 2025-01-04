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

    sf::Vector2f blockSize(80.0f, 75.0f);

    fountainRight.setSize(blockSize);
    fountainLeft.setSize(blockSize);

    float windowWidth = static_cast<float>(m_window->getSize().x);
    float windowHeight = static_cast<float>(m_window->getSize().y);
    float gapBetweenBlocks = 75.f; 

    float totalWidth = (blockSize.x * 2) + gapBetweenBlocks;
    float startX = (windowWidth - totalWidth) / 2.f;
    float centerY = (windowHeight - blockSize.y) / 2.f; 

    fountainRight.setPosition(startX - 85.f, centerY + 110.f);
    fountainLeft.setPosition(startX + blockSize.x - 70 + gapBetweenBlocks + 150.f, centerY + 110.f);

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

sf::FloatRect GameScreen::getReducedBounds(const sf::Sprite& sprite, float offset) {

    sf::FloatRect originalBounds = sprite.getGlobalBounds();
    return sf::FloatRect(

        originalBounds.left + offset,
        originalBounds.top + offset,
        originalBounds.width - 2 * offset - 70,
        originalBounds.height - 2 * offset
    );
}

void GameScreen::handleEvents()
{
    while (m_window->getRenderer().pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
        {
            m_window->close();
        }
        else if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::Escape)
            {
                m_window->close();
            }
            else if (m_event.key.code == sf::Keyboard::Space)
            {
                if (m_player.getIdle())
                {
                    m_player.attack();
                }
            }
            else if (m_event.key.code == sf::Keyboard::I)
            {
                // Open Inventory Screen
                return;
            }
        }
    }

    m_playerDirection = Direction::None;

    sf::FloatRect playerBounds = getReducedBounds(m_player.getSprite(), 50.0f);
    sf::FloatRect fountainRightBounds = fountainRight.getGlobalBounds();
    sf::FloatRect fountainLeftBounds = fountainLeft.getGlobalBounds();

    bool movingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool movingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool movingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool movingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    bool isMovingDiagonally = (movingLeft || movingRight) && (movingUp || movingDown);

    auto canMove = [&](sf::FloatRect futureBounds) -> bool {
        return !futureBounds.intersects(fountainRightBounds) &&
            !futureBounds.intersects(fountainLeftBounds);
        };

    if (movingLeft && playerBounds.left > 60)
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.left -= m_player.getSpeed();

        if (canMove(futureBounds))
        {
            m_playerDirection = Direction::Left;
        }
    }

    if (movingRight && (playerBounds.left + playerBounds.width < 920))
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.left += m_player.getSpeed();

        if (canMove(futureBounds))
        {
            m_playerDirection = Direction::Right;
        }
    }

    if (movingUp && playerBounds.top > 150)
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.top -= m_player.getSpeed();

        if (canMove(futureBounds))
        {
            m_playerDirection = Direction::Up;
        }
    }

    if (movingDown && (playerBounds.top + playerBounds.height < 750))
    {
        sf::FloatRect futureBounds = playerBounds;
        futureBounds.top += m_player.getSpeed();

        if (canMove(futureBounds))
        {
            m_playerDirection = Direction::Down;
        }
    }

    if (isMovingDiagonally)
    {
        sf::FloatRect futureBounds = playerBounds;

        if (movingUp && movingRight)
        {
            futureBounds.left += m_player.getSpeed();
            futureBounds.top -= m_player.getSpeed();
        }
        else if (movingUp && movingLeft)
        {
            futureBounds.left -= m_player.getSpeed();
            futureBounds.top -= m_player.getSpeed();
        }
        else if (movingDown && movingRight)
        {
            futureBounds.left += m_player.getSpeed();
            futureBounds.top += m_player.getSpeed();
        }
        else if (movingDown && movingLeft)
        {
            futureBounds.left -= m_player.getSpeed();
            futureBounds.top += m_player.getSpeed();
        }

        if (!canMove(futureBounds))
        {
            m_playerDirection = Direction::None;
        }
    }
}

void GameScreen::resetGameState(Window* window)
{
    m_level = 1;
    m_score = 0;

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
