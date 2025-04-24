#include "Movement.h"

//-----------------------------------------------------------------------------
sf::Vector2f Movement::getFaceDirection(const sf::Vector2f& playerPos, const sf::Vector2f& objectPos) const
{
    return m_direction;
}

//-----------------------------------------------------------------------------
sf::Vector2f Movement::getMoveDirection() const
{
    return m_direction;
}

//-----------------------------------------------------------------------------
