#include "MoveSmart.h"
//-----------------------------------------------------------------------------
bool MoveSmart::m_register = Factory::registerMove(
    MoveType::Smart,
    []()->unique_ptr<Movement>
    {
        return std::make_unique<MoveSmart>();
    });

//-----------------------------------------------------------------------------

sf::Vector2f MoveSmart::move(const sf::Vector2f& playerPos, const sf::Vector2f& objectPos,
    float speed, float timePassed)
{
    sf::Vector2f direction = playerPos - objectPos;

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0)
    {

        if (length < MAX_APPROACH_TO_PLAYER)
        {
            m_direction = STAY;
        }
        else {
            direction /= length;

            if (std::abs(direction.x) > 0.5f && std::abs(direction.y) > 0.5f)
            {
                if (direction.x > 0)
                    m_direction = (direction.y > 0) ? DOWN_RIGHT : UP_RIGHT;
                else
                    m_direction = (direction.y > 0) ? DOWN_LEFT : UP_LEFT;
            }
            else if (std::abs(direction.x) > std::abs(direction.y))
            {
                m_direction = (direction.x > 0) ? RIGHT : LEFT;
            }
            else
            {
                m_direction = (direction.y > 0) ? DOWN : UP;
            }
        }
    }
    else
    {
        m_direction = STAY;
    }
    return sf::Vector2f(m_direction * speed * timePassed);
}

//-----------------------------------------------------------------------------