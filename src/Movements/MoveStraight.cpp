#include "MoveStraight.h"

//-----------------------------------------------------------------------------
MoveStraight::MoveStraight() 
    :m_isInitDirection(false)
{
}

//-----------------------------------------------------------------------------
sf::Vector2f MoveStraight::move(const sf::Vector2f& playerPos , const sf::Vector2f& objectPos , 
                                float speed, float timePassed)
{
    if (!m_isInitDirection)
    {
        m_isInitDirection = true;
        sf::Vector2f direction = playerPos - objectPos;

        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0)
        {
            m_movementAmount =  direction / length;
        }
        else
        {
            m_movementAmount = STAY;
        }
    }
    
    return sf::Vector2f(m_movementAmount * speed * timePassed);
}

//-----------------------------------------------------------------------------