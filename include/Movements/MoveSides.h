#pragma once
#include "Movement.h"

class MoveSides : public Movement
{
private:
	static bool m_register;
	sf::Clock m_currSideMovementClock;
	float m_timeOfEachSideTurn;
	sf::Vector2f m_lastPos;

	void changeSide();
	sf::Vector2f getFaceDirection(const sf::Vector2f& playerPos, 
								  const sf::Vector2f& objectPos) const override;


public:
	MoveSides();
	virtual ~MoveSides() = default;
	virtual sf::Vector2f move(const sf::Vector2f& playerPos,
							  const sf::Vector2f& objectPos,
							  float speed, float timePassed) override;
};