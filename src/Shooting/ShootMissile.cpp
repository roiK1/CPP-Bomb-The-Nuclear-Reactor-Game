#include "ShootMissile.h"
#include "Ammo.h"

std::unique_ptr<Ammo> ShootMissile::shoot(const sf::Vector2f& bulletPos)
{
	return Factory::createAmmo(AmmoType::Missile, bulletPos);
}
