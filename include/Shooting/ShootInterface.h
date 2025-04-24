#pragma once
#include <sfml/Graphics.hpp>

class Ammo;

class ShootInterface
{
public:
	virtual ~ShootInterface() = default;
	virtual std::unique_ptr<Ammo> shoot(const sf::Vector2f& ammoPos) = 0;
};
