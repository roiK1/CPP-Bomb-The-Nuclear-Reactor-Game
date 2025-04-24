#include "Player.h"
#include "Ammo.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "ObjectsPositions.h"

//-----------------------------------------------------------------------------
Player::Player()
    : Human(PLAYER_FIRST_POS, Textures::instance()->get(textureType::Player),
        PLAYER_SPEED, nullptr, INIT_PLAYER_LIFES),
    m_numOfMissils(INIT_ROCKETS_NUM),
    m_shootCooldownTime(PLAYER_SHOOT_COOLDOWN),
    m_faceDirection(RIGHT), m_isGotEnoughTNTBombs(false), m_isOnHelicopter(false),
    m_numOfTNTBombs(0)
{
    m_ammoManager.addAmmoType(AmmoType::Bullet, std::make_unique<ShootBullet>());
    m_ammoManager.addAmmoType(AmmoType::Missile, std::make_unique<ShootMissile>());
    m_shootClock.restart();
    m_object.setScale(0.2f, 0.2f);
}

//-----------------------------------------------------------------------------
void Player::addMissile(int amount)
{
    m_numOfMissils += amount;
}

//-----------------------------------------------------------------------------
int Player::getNumOfMissiles() const
{
    return m_numOfMissils;
}

//-----------------------------------------------------------------------------
int Player::getNumOfLives() const
{
    return m_lives;
}

//-----------------------------------------------------------------------------
int Player::getNumOfTNTs() const
{
    return m_numOfTNTBombs;
}

//-----------------------------------------------------------------------------
void Player::updateView(sf::View& view)
{
    // Left + right movement
    if ((getPos().x < view.getCenter().x && getPos().x > WINDOW_WIDTH / 2) ||
        (getPos().x > view.getCenter().x && getPos().x < GAME_BG_WIDTH - WINDOW_WIDTH / 2))
    {
        view.setCenter(getPos().x, view.getCenter().y);
    }

    // Up + down movement
    if ((getPos().y < view.getCenter().y && getPos().y > WINDOW_HIGH / 2) ||
        (getPos().y > view.getCenter().y && getPos().y < GAME_BG_HIGH - WINDOW_HIGH / 2))
    {
        view.setCenter(view.getCenter().x, getPos().y);
    }
}

//-----------------------------------------------------------------------------
void Player::move(const sf::Time& timePassed)
{
    sf::Vector2f movement = m_lastMovementAmount = m_moveDirection * m_speed * timePassed.asSeconds();

    if (isValidMove(m_object.getPosition() + movement))
    {
        m_object.move(movement);
        updateTextureTimer(timePassed);
        m_object.setScale(0.2f, 0.2f);
    }
}

//-----------------------------------------------------------------------------
void Player::update(const sf::Time& timePassed)
{
    move(timePassed);
    auto ammoTarget = getPos() + 500.f * m_faceDirection;
    m_ammoManager.update(ammoTarget, timePassed);

    m_shield.update(getPos());
}

//-----------------------------------------------------------------------------
void Player::handleCollison(StaticObject* staticObject)
{
    m_object.move(-m_lastMovementAmount);
    m_ammoManager.handleCollison(staticObject);
    staticObject->handleCollison(this);
}

//-----------------------------------------------------------------------------
void Player::handleCollison(PlayerRescueHelicopter* helicopter)
{
}

//-----------------------------------------------------------------------------
void Player::handleCollison(TNTBomb* TntBomb)
{
    m_numOfTNTBombs++;
    if (m_numOfTNTBombs >= MIN_TNT_BOMBS_FOR_EXPLOTION)
    {
        m_isGotEnoughTNTBombs = true;
    }
}

//-----------------------------------------------------------------------------
void Player::handleAmmoCollison(Enemy* enemy)
{
    m_ammoManager.handleCollison(enemy);
}

//-----------------------------------------------------------------------------
void Player::handleAmmoCollison(StaticObject* staticObject)
{
    m_ammoManager.handleCollison(staticObject);
}

//-----------------------------------------------------------------------------
void Player::handleKeyPress(const sf::Keyboard::Key& keyPressed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_moveDirection = m_faceDirection = UP_RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_moveDirection = m_faceDirection = UP_LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_moveDirection = m_faceDirection = DOWN_RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_moveDirection = m_faceDirection = DOWN_LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_moveDirection = m_faceDirection = UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_moveDirection = m_faceDirection = DOWN;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_moveDirection = m_faceDirection = LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_moveDirection = m_faceDirection = RIGHT;
    }

    animDirection(m_moveDirection);
}

//-----------------------------------------------------------------------------
void Player::handleKeyReleased()
{
    m_moveDirection = STAY;
    animDirection(STAY);
}

//-----------------------------------------------------------------------------
void Player::handleMousePress(const sf::Mouse::Button& keyPressed)
{
    sf::Time currentTime = m_shootClock.getElapsedTime();
    bool coolDownFinished = currentTime.asSeconds() >= m_shootCooldownTime;

    if (coolDownFinished)
    {
        if (sf::Mouse::Left == keyPressed)
        {
            shoot(AmmoType::Bullet);
        }
        else if (sf::Mouse::Right == keyPressed && m_numOfMissils > 0)
        {
            shoot(AmmoType::Missile);
            m_numOfMissils--;
        }
        m_shootClock.restart();
    }
}

//-----------------------------------------------------------------------------
void Player::shoot(AmmoType type)
{
    m_ammoManager.changeAmmoType(type);
    auto objectSize = sf::Vector2f(m_object.getScale().x * m_object.getTexture()->getSize().x,
        m_object.getScale().y * m_object.getTexture()->getSize().y);

    m_ammoManager.shoot(sf::Vector2f(m_object.getPosition().x + objectSize.x / 2 * m_faceDirection.x,
        m_object.getPosition().y + objectSize.y / 2 * m_faceDirection.y));
}


//-----------------------------------------------------------------------------
void Player::draw(sf::RenderWindow& window) const
{
    if (m_shield.isActive())
    {
        m_shield.draw(window);
    }
    Object::draw(window);
    m_ammoManager.draw(window);
}

//-----------------------------------------------------------------------------
void Player::shieldState()
{
    m_shield.activation();
}

//-----------------------------------------------------------------------------
Shield* Player::getShield()
{
    return &m_shield;
}

//-----------------------------------------------------------------------------
void Player::useTNTsBombs()
{
    if (m_isGotEnoughTNTBombs)
    {
        m_numOfTNTBombs -= MIN_TNT_BOMBS_FOR_EXPLOTION;
        if (m_numOfTNTBombs < MIN_TNT_BOMBS_FOR_EXPLOTION)
        {
            m_isGotEnoughTNTBombs = false;
        }
    }
}

//-----------------------------------------------------------------------------
bool Player::isGotEnoughTNTForExplotion() const
{
    return m_isGotEnoughTNTBombs;
}

//-----------------------------------------------------------------------------
