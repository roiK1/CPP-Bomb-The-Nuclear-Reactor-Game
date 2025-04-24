#include "MoveSides.h"

//-----------------------------------------------------------------------------
bool MoveSides::m_register = Factory::registerMove(
	MoveType::Sides,
	[]()->unique_ptr<Movement>
	{
		return std::make_unique<MoveSides>();
	});

//-----------------------------------------------------------------------------
MoveSides::MoveSides() 
	: m_timeOfEachSideTurn(10.f) , m_lastPos(0.f,0.f)
{
	m_direction = LEFT;
	m_currSideMovementClock.restart();
}

//-----------------------------------------------------------------------------
void MoveSides::changeSide()
{
	m_direction == LEFT ? m_direction = RIGHT : m_direction = LEFT;
}

//-----------------------------------------------------------------------------
sf::Vector2f MoveSides::getFaceDirection(const sf::Vector2f& playerPos, const sf::Vector2f& objectPos) const
{
	float directionY = playerPos.y - objectPos.y;

	if (directionY < 0)
	{
		return UP;   
	}
	else if (directionY > 0)
	{
		return DOWN; 
	}
}

//-----------------------------------------------------------------------------
sf::Vector2f MoveSides::move(const sf::Vector2f& playerPos, const sf::Vector2f& objectPos,
							 float speed, float timePassed)
{
	if (m_lastPos == objectPos)
	{
		changeSide();
	}
	m_lastPos = objectPos;

	sf::Time currSideTimePassed = m_currSideMovementClock.getElapsedTime();

	if (currSideTimePassed.asSeconds() > m_timeOfEachSideTurn)
	{
		m_currSideMovementClock.restart();
		changeSide();
	}
	return m_direction * speed * timePassed;
}

//-----------------------------------------------------------------------------