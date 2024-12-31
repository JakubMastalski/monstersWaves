#include "Player.hpp"

Player::Player(const Window* window)
{
    m_movingTexture.loadFromFile("res/images/Run.png");
    m_idleTexture.loadFromFile("res/images/Idle.png");
    m_attackTexture.loadFromFile("res/images/Attack1.png");
    
    m_sprite.setTexture(m_idleTexture);
    m_sprite.setPosition(
        static_cast<float>(window->getSize().x) * 0.5f - 162 * 0.5f - 40,
        static_cast<float>(window->getSize().y) * 0.5f - 162 * 0.5f
    );
    m_sprite.setScale(1.5f, 1.5f);

    for (int i = 0; i < m_idleRects.size(); ++i)
    {
        m_idleRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    for (int i = 0; i < m_movingRects.size(); ++i)
    {
        m_movingRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    for (int i = 0; i < m_attackRects.size(); ++i)
    {
        m_attackRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    m_sprite.setTextureRect(m_idleRects[m_currentFrame]);

    for (int i = 0; i < 3; ++i)
    {
        sf::CircleShape lifeShape{ 7 };
        lifeShape.setPosition(i * 20 + 10, 20);
        lifeShape.setFillColor(sf::Color::Red);

        m_circleLives.push_back(lifeShape);
    }
}

void Player::update(const float dt)
{
    updateAttackAnimation(dt);
    updateMoveAnimation(dt);
}
void Player::updateAttackAnimation(const float dt)
{
    if (m_isAttacking)
    {
        m_attackAnimationTime += dt;

        if (m_attackAnimationTime >= m_frameDuration)
        {
            m_attackAnimationTime = 0.0f;
            m_sprite.setTextureRect(m_attackRects[m_currentFrame]);
            ++m_currentFrame;
        }
         
        if (m_currentFrame >= m_attackRects.size())
        {
            stopAttack();
        }
    }
}

void Player::stopAttack()
{
    m_currentFrame = 0;
    m_isAttacking = false;
    m_sprite.setTexture(m_idleTexture);
}


void Player::draw(Window* window) const
{
    for (const auto& lifeCircle : m_circleLives)
    {
        window->draw(lifeCircle);
    }
    window->draw(m_sprite);
}

void Player::setDirection(const Direction direction, const float dt)
{
    switch (direction)
    {
    case Direction::Left:
    {
        moveLeft(dt);
        break;
    }
       case Direction::Right:
    {
        moveRight(dt);
        break;
    }
       case Direction::Up:
       {
           moveUp(dt);
           break;
       }
       case Direction::Down:
       {
           moveDown(dt);
           break;
       }
       case Direction::Diagonaly_UpRight:
       {
           moveDiagonaly_UpRight(dt);
           break;
       }
       case Direction::Diagonaly_UpLeft:
       {
           moveDiagonaly_UpLeft(dt);
           break;
       }
       case Direction::Diagonaly_DownRight:
       {
           moveDiagonaly_DownRight(dt);
           break;
       }
       case Direction::Diagonaly_DownLeft:
       {
           moveDiagonaly_DownLeft(dt);
           break;
       }
       default:
           stopMoving();
   }
}

void Player::moveLeft(const float dt)
{
    m_sprite.move(-m_speed * dt, 0);
    if (!m_isMovingLeft)
    {
        m_isAttacking = false;
        m_isMovingLeft = true;
        m_isMovingRight = false;
        m_isMovingUp = false;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);

        m_lastDirection = Direction::Left;

        m_sprite.setScale(-1.5f, 1.5f);
        m_sprite.setOrigin(162.0f, 0.0f);
    }
}

void Player::moveRight(const float dt)
{
    m_sprite.move(m_speed * dt, 0);
    if (!m_isMovingRight)
    {
        m_isAttacking = false;
        m_isMovingLeft = false;
        m_isMovingRight = true;
        m_isMovingUp = false;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;

        m_sprite.setTexture(m_movingTexture); 
        m_lastDirection = Direction::Right;

        m_sprite.setScale(1.5f, 1.5f); 
        m_sprite.setOrigin(0.0f, 0.0f);
    }
}

void Player::moveUp(float dt)
{
    m_sprite.move(0, -m_speed * dt);
    if (!m_isMovingUp)
    {
        m_isAttacking = false;
        m_isMovingRight = false;
        m_isMovingLeft = false;
        m_isMovingUp = true;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);

        m_lastDirection = Direction::Up;
    }
}

void Player::moveDiagonaly_UpRight(float dt)
{
    m_sprite.move((m_speed - 20) * dt, - (m_speed - 20) * dt);

    if (!m_isMovingRight)
    {
        m_isAttacking = false;
        m_isMovingLeft = false;
        m_isMovingRight = true;
        m_isMovingUp = false;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;

        m_sprite.setTexture(m_movingTexture);
        m_lastDirection = Direction::Right;

        m_sprite.setScale(1.5f, 1.5f);
        m_sprite.setOrigin(0.0f, 0.0f);
    }
} 

void Player::moveDiagonaly_UpLeft(float dt)
{
    m_sprite.move(-m_speed * dt, -m_speed * dt);

    if (!m_isMovingLeft)
    {
        m_isAttacking = false;
        m_isMovingLeft = true;
        m_isMovingRight = false;
        m_isMovingUp = false;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);

        m_lastDirection = Direction::Left;

        m_sprite.setScale(-1.5f, 1.5f);
        m_sprite.setOrigin(162.0f, 0.0f);
    }
}

void Player::moveDiagonaly_DownRight(float dt)
{
    m_sprite.move(m_speed * dt, m_speed * dt);

    if (!m_isMovingRight)
    {
        m_isAttacking = false;
        m_isMovingLeft = false;
        m_isMovingRight = true;
        m_isMovingUp = false;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;

        m_sprite.setTexture(m_movingTexture);
        m_lastDirection = Direction::Right;

        m_sprite.setScale(1.5f, 1.5f);
        m_sprite.setOrigin(0.0f, 0.0f);
    }
}

void Player::moveDiagonaly_DownLeft(float dt)
{
    m_sprite.move(-m_speed * dt, m_speed * dt);

    if (!m_isMovingLeft)
    {
        m_isAttacking = false;
        m_isMovingLeft = true;
        m_isMovingRight = false;
        m_isMovingUp = false;
        m_isMovingDown = false;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);

        m_lastDirection = Direction::Left;

        m_sprite.setScale(-1.5f, 1.5f);
        m_sprite.setOrigin(162.0f, 0.0f);
    }
}


void Player::moveDown(float dt)
{
    m_sprite.move(0, m_speed * dt);
    if (!m_isMovingDown)
    {
        m_isAttacking = false;
        m_isMovingRight = false;
        m_isMovingLeft = false;
        m_isMovingUp = false;
        m_isMovingDown = true;
        m_isIdle = false;
        m_currentFrame = 0;
        m_sprite.setTexture(m_movingTexture);

        m_lastDirection = Direction::Down;
    }
}

void Player::stopMoving()
{
    if (!m_isIdle)
    {
        m_isIdle = true;
        m_isMovingLeft = false;
        m_isMovingRight = false;
        m_isMovingUp = false;
        m_isMovingDown = false;

        m_moveDiagonaly_DownRight = false;
        m_moveDiagonaly_DownLeft = false;
        m_moveDiagonaly_UpRight = false;
        m_moveDiagonaly_UpLeft = false;

        m_sprite.setTexture(m_idleTexture);
        m_currentFrame = 0;
    }
}

void Player::setSpeed(const float multiplayer)
{
    m_speed = multiplayer;
}

bool Player::getIdle()
{
    return this->m_isIdle;
}

void Player::attack()
{
    if (!m_isAttacking)
    {
        m_isAttacking = true;
        m_currentFrame = 0;
        m_sprite.setTexture(m_attackTexture);
    }
}

sf::FloatRect Player::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

sf::Vector2f Player::getPosition() const
{
    return m_sprite.getPosition();
}

void Player::updateMoveAnimation(const float dt)
{
    if (!m_isAttacking)
    {
        m_animationMoveIdleTime += dt;

        if (m_animationMoveIdleTime >= m_frameDuration)
        {
            m_animationMoveIdleTime = 0.0f;

            if (m_isMovingRight || m_isMovingLeft || m_isMovingDown || m_isMovingUp)
            {
                m_sprite.setTextureRect(m_movingRects[m_currentFrame]);
                ++m_currentFrame;

                if (m_currentFrame >= m_movingRects.size())
                {
                    m_currentFrame = 0;
                }
            }
            else if (m_isIdle)
            {
                m_sprite.setTextureRect(m_idleRects[m_currentFrame]);
                ++m_currentFrame;

                if (m_currentFrame >= m_idleRects.size())
                {
                    m_currentFrame = 0;
                }
            }
        }
    }
}

bool Player::isAttacking() const
{
    return m_isAttacking;
}

const sf::Sprite& Player::getSprite() const
{
    return m_sprite;
}

int Player::getLives() const
{
    return m_lives;
}

void Player::loseLife()
{
    if (m_lives > 0)
    {
        --m_lives;
        m_circleLives.erase(m_circleLives.end() - 1);
    }

    if (m_lives <= 0)
    {
        ScreenManager::GetInstance().setScreen(ScreenType::GAMEOVER);
        return;
    }
}

float Player::getSpeed()
{
    return m_speed;
}

void Player::resetPlayer(Window* window)
{
    m_sprite.setPosition(
        static_cast<float>(window->getSize().x) * 0.5f - 162 * 0.5f - 40,
        static_cast<float>(window->getSize().y) * 0.5f - 162 * 0.5f
    );
    m_sprite.setScale(1.5f, 1.5f);
    m_sprite.setOrigin(0.0f, 0.0f);

    m_sprite.setTexture(m_idleTexture);
    m_sprite.setTextureRect(m_idleRects[0]);

    m_circleLives.clear();

    m_lives = 3;

    for (int i = 0; i < m_lives; ++i)
    {
        sf::CircleShape lifeShape{ 7 };
        lifeShape.setPosition(i * 20 + 10, 20);
        lifeShape.setFillColor(sf::Color::Red);

        m_circleLives.push_back(lifeShape);
    }

    m_isIdle = true;
    m_isAttacking = false;
    m_isMovingLeft = false;
    m_isMovingRight = false;
    m_isMovingUp = false;
    m_isMovingDown = false;

    m_currentFrame = 0;
    m_animationMoveIdleTime = 0.0f;
    m_attackAnimationTime = 0.0f;

    m_speed = 100.0f; 

    m_lastDirection = Direction::None;

    m_movingTexture.loadFromFile("res/images/Run.png");
    m_idleTexture.loadFromFile("res/images/Idle.png");
    m_attackTexture.loadFromFile("res/images/Attack1.png");

    m_sprite.setTexture(m_idleTexture);

    m_sprite.setScale(1.5f, 1.5f);

    for (int i = 0; i < m_idleRects.size(); ++i)
    {
        m_idleRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    for (int i = 0; i < m_movingRects.size(); ++i)
    {
        m_movingRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    for (int i = 0; i < m_attackRects.size(); ++i)
    {
        m_attackRects[i] = sf::IntRect{ i * 162, 0, 162, 162 };
    }

    m_sprite.setTextureRect(m_idleRects[m_currentFrame]);

    for (int i = 0; i < 3; ++i)
    {
        sf::CircleShape lifeShape{ 7 };
        lifeShape.setPosition(i * 20 + 10, 20);
        lifeShape.setFillColor(sf::Color::Red);

        m_circleLives.push_back(lifeShape);
    }
}
