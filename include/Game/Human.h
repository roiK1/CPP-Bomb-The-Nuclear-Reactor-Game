#pragma once 
#include "DynamicObject.h"

class Human : public DynamicObject
{
public:
	Human(	sf::Vector2f, const std::vector<sf::Texture>& textures,
			float speed, std::unique_ptr<Movement> movement , int lives);
	~Human() = default;

	void disqualification(int amount);
	void addLive(int amount);
	void animDirection(const sf::Vector2f dir);

	bool getIsDead() const;

protected:
	int m_lives;
	sf::Vector2f m_lastMovementAmount;
};
