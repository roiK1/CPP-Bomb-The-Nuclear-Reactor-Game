#pragma once
#include "ShootInterface.h"
#include "Factory.h"

class Bullet;

class ShootBullet : public ShootInterface
{
public:
	virtual ~ShootBullet() = default;
	virtual std::unique_ptr<Ammo> shoot(const sf::Vector2f& bulletPos) override;
};