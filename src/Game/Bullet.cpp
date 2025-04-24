#include "Bullet.h"


//-----------------------------------------------------------------------------
bool Bullet::m_register = Factory::registerShoot(
	AmmoType::Bullet , [](const sf::Vector2f& pos)->unique_ptr<Ammo>
	{
		return std::make_unique<Bullet>(pos);
	});

//-----------------------------------------------------------------------------
Bullet::Bullet(const sf::Vector2f& pos)
	:Ammo(pos, Textures::instance()->get(textureType::bullet),
			BULLET_SPEED , std::make_unique<MoveStraight>() , 
			BULLET_DAMAGE) 
{
	Sounds::instance()->playSounds(soundsType::shootBullet);
}

//-----------------------------------------------------------------------------