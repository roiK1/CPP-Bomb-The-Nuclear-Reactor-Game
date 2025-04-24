#include "Ammo.h"
#include "Human.h"

//-----------------------------------------------------------------------------
Ammo::Ammo(	sf::Vector2f pos , const std::vector<sf::Texture>& textures,
			float speed, std::unique_ptr<Movement> movement,int damage) 
	:DynamicObject(pos, speed ,textures, std::move(movement)),
	 m_damage(damage), m_isExits(true), m_makeExplotion(false)
{
}

//-----------------------------------------------------------------------------
void Ammo::move(const sf::Vector2f& targetPos, const sf::Time& timePassed)
{
	if (m_movement == nullptr)
	{
		return;
	}

	auto movement = m_movement->move(targetPos, getPos(),
		m_speed, timePassed.asSeconds());
	if (isValidMove(m_object.getPosition() + movement))
	{
		m_object.move(movement);
	}
	else
	{
		m_isExits = false;
	}
}

//-----------------------------------------------------------------------------
bool Ammo::getIsExits() const
{
	return m_isExits;
}

//-----------------------------------------------------------------------------
void Ammo::handleCollison(Human* human)
{
	human->disqualification(m_damage);
	m_isExits = false;
}

//-----------------------------------------------------------------------------
void Ammo::handleCollison(StaticObject* staticObject)
{
	m_isExits = false;
	staticObject->handleCollison(this);
}

//-----------------------------------------------------------------------------
void Ammo::handleCollison(SomeStaticObject* staticObject)
{
	staticObject->makeDamage(m_damage);
}

//-----------------------------------------------------------------------------
std::unique_ptr<Ammo> Ammo::makeExplosion()
{
	return nullptr;
}

//-----------------------------------------------------------------------------
bool Ammo::getNeedToMakeExplosion() const
{
	return m_makeExplotion;
}

//-----------------------------------------------------------------------------