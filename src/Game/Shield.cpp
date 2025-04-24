#include "Shield.h"
#include "Ammo.h"
//-----------------------------------------------------------------------------
Shield::Shield()
	:StaticObject(sf::Vector2f(0.f, 0.f), Textures::instance()->get(textureType::shieldState)),
	m_isActive(false)
{
}

//-----------------------------------------------------------------------------
void Shield::activation()
{
	m_shieldClock.restart();
	m_isActive = true;
}

//-----------------------------------------------------------------------------
void Shield::disable()
{
	m_isActive = false;
}

//-----------------------------------------------------------------------------
bool Shield::isActive() const
{
	return m_isActive;
}

//-----------------------------------------------------------------------------
void Shield::update(const sf::Vector2f& pos)
{
	bool shieldTimePassed = m_shieldClock.getElapsedTime().asSeconds() > SHIELD_PROTECTION_TIME;
	shieldTimePassed ? disable() : m_object.setPosition(pos);
}

//-----------------------------------------------------------------------------
void Shield::handleCollison(Ammo* ammo)
{
	Sounds::instance()->playSounds(soundsType::shieldInterception);
}