#include "Player.hpp"

Player::Player(const Window* window)
{
    m_movingTexture.loadFromFile("C:/Users/USER/Desktop/monstersWaves/res/images/Run.png");
    m_idleTexture.loadFromFile("C:/Users/USER/Desktop/monstersWaves/res/images/Idle.png");
    m_attackTexture.loadFromFile("C:/Users/USER/Desktop/monstersWaves/res/images/Attack1.png");
    
    m_sprite.setTexture(m_idleTexture);
    m_sprite.setPosition(
        static_cast<float>(window->getSize().x) * 0.5f - 162 * 0.5f,
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
       default:
           stopMoving();
   }
}

void Player::moveLeft(const float dt)
{
    m_sprite.move(-100 * dt, 0);
    if (!m_isMovingLeft)
    {
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
    m_sprite.move(100 * dt, 0);
    if (!m_isMovingRight)
    {
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
    m_sprite.move(0, -100 * dt);
    if (!m_isMovingUp)
    {
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

void Player::moveDown(float dt)
{
    m_sprite.move(0, 100 * dt);
    if (!m_isMovingDown)
    {
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
        m_sprite.setTexture(m_idleTexture);
        m_currentFrame = 0;
    }
   
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