#include "StaticObject.h"
#include "Ammo.h"
#include "Missile.h"
#include "Bullet.h"

//-----------------------------------------------------------------------------
StaticObject::StaticObject(sf::Vector2f pos, const std::vector<sf::Texture>& textures)
	: Object(pos , textures) , m_isExists(true)
{
}

//-----------------------------------------------------------------------------
bool StaticObject::getIsExists() const
{
	return m_isExists;
}

//-----------------------------------------------------------------------------

