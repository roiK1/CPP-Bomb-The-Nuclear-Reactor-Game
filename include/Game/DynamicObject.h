#pragma once
#include "Object.h"
#include "Movement.h"

class StaticObject;

class DynamicObject : public Object
{
public:
	DynamicObject() = default;
	DynamicObject(	sf::Vector2f pos,float speed , const std::vector<sf::Texture>& textures,
					std::unique_ptr<Movement> movement);
	virtual ~DynamicObject() = default;

	bool isValidMove(const sf::Vector2f& wantedPos) const;
	virtual void handleCollison(StaticObject* staticObject) = 0;

protected:
	float m_speed;
	std::unique_ptr<Movement> m_movement;

};

