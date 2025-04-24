#pragma once
#include "ShootInterface.h"
#include "Factory.h"

class ShootMissile : public ShootInterface
{
public:
	virtual ~ShootMissile() = default;
	virtual std::unique_ptr<Ammo> shoot(const sf::Vector2f& bulletPos) override;
};
