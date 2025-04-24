#pragma once
#include "Ammo.h"
#include "Movement.h"

class Bullet : public Ammo
{
private:
	static bool m_register;

public:
	Bullet(const sf::Vector2f&);
	virtual ~Bullet() = default;
};