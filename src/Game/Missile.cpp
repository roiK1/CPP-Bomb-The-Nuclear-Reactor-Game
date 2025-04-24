#include "Missile.h"

//-----------------------------------------------------------------------------
bool Missile::m_register = Factory::registerShoot(
	AmmoType::Missile, [](const sf::Vector2f& pos)->unique_ptr<Ammo>
	{
		return std::make_unique<Missile>(pos);
	});

//-----------------------------------------------------------------------------
Missile::Missile(const sf::Vector2f& pos)
	:Ammo(pos, Textures::instance()->get(textureType::missile),
		MISSILE_SPEED, std::make_unique<MoveStraight>() ,MISSILE_DAMAGE) 
{
	Sounds::instance()->playSounds(soundsType::shootMissle);
	m_exploadTimer.restart();
}

//-----------------------------------------------------------------------------
void Missile::handleCollison(Human* human)
{
	Ammo::handleCollison(human);
	m_makeExplotion = true;
}

//-----------------------------------------------------------------------------
void Missile::handleCollison(StaticObject* staticObject)
{
	Ammo::handleCollison(staticObject);
	m_makeExplotion = true;
}

//-----------------------------------------------------------------------------
std::unique_ptr<Ammo> Missile::makeExplosion()
{
	return Factory::createAmmo(AmmoType::Explotion, m_object.getPosition());
}

//-----------------------------------------------------------------------------
void Missile::update(const sf::Time& timePassed)
{
	if (m_exploadTimer.getElapsedTime().asSeconds() > MISSILE_EXPLOTION_TIME)
	{
		m_makeExplotion = true;
		m_isExits = false;
	}
	m_object.rotate(5.f);
}

//-----------------------------------------------------------------------------

