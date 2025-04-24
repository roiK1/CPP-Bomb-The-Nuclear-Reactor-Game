#include "ShootBullet.h"
#include "Ammo.h"

//bool ShootBullet::m_register = Factory::registerShoot(
//	AmmoType::Bullet, [](const sf::Vector2f& pos)->unique_ptr<Ammo>
//	{
//		return std::make_unique<ShootBullet>(pos);
//	});

//-----------------------------------------------------------------------------
std::unique_ptr<Ammo> ShootBullet::shoot(const sf::Vector2f& bulletPos)
{
	return Factory::createAmmo(AmmoType::Bullet , bulletPos);
}
