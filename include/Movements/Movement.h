#pragma once
#include "Factory.h"
#include <sfml/Graphics.hpp>
#include "Consts.h"

class Movement
{
public:
	virtual ~Movement() = default;
	virtual sf::Vector2f move(const sf::Vector2f& playerPos, 
							  const sf::Vector2f& objectPos , 
							  float speed , float timePassed) = 0;

	virtual sf::Vector2f getFaceDirection(const sf::Vector2f& playerPos, 
										  const sf::Vector2f& objectPos) const;

	sf::Vector2f getMoveDirection() const;

protected:
	sf::Vector2f m_direction , m_faceDirection;

private:
	static bool m_registerIt;

};
