#pragma once
#include "Movement.h"

class MoveStraight : public Movement
{
private:
	static bool m_register;
	sf::Vector2f m_movementAmount;
	bool m_isInitDirection;

public:
	MoveStraight();
	virtual ~MoveStraight() = default;
		virtual sf::Vector2f move(const sf::Vector2f& playerPos,
								  const sf::Vector2f& objectPos , 
								  float speed, float timePassed) override;
}; 