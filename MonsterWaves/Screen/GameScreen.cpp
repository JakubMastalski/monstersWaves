#include "Screen/GameScreen.hpp"

GameScreen::GameScreen(Window* window) :
    BaseScreen(window), m_player({ window })
{
    m_enemies.reserve(20);

    for (int i = 0; i < 5; ++i)
    {
        m_enemies.push_back(std::make_unique<Enemy>(window, m_player.getPosition(), 90.0f));
    }
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
    m_player.setDirection(m_playerDirection, dt);
    m_player.update(dt);

    for (const auto& enemy : m_enemies)
    {
        enemy->update(dt, m_player.getPosition(),
            { m_player.getBounds().width / 2 , m_player.getBounds().height - 100 });

        if (enemy->checkCollisionWithPlayerAttack(m_player.getSprite()) && m_player.isAttacking())
        {
            enemy->enemyDie();
        }
    }
  
}

void GameScreen::render()
{
    m_window->beginDraw();

    m_player.draw(m_window.get());

    for (const auto& enemy : m_enemies)
    {
        enemy->draw(m_window.get());
    }

    m_window->endDraw();
}
