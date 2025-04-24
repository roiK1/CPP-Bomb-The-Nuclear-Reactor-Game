#pragma once
#include "Movement.h"

class MoveSmart : public Movement
{
private:
	static bool m_register;

public:
	virtual ~MoveSmart() = default;
	virtual sf::Vector2f move(const sf::Vector2f& playerPos,
							  const sf::Vector2f& objectPos,
							  float speed, float timePassed) override;
};
