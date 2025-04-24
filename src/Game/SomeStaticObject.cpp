#include "SomeStaticObject.h"
#include "Human.h"
#include "Player.h"
#include "Enemy.h"

//-----------------------------------------------------------------------------
SomeStaticObject::SomeStaticObject(sf::Vector2f pos, const std::vector<sf::Texture>& textures ,
								   int resistance)
	:StaticObject(pos, textures) , m_resistance(resistance)
{
}

////-----------------------------------------------------------------------------
void SomeStaticObject::makeDamage(int damage)
{
	m_resistance -= damage;
	nextTextureIndex();
	updateTexture();
	if (m_resistance <= 0)
	{
		m_isExists = false;
	}
}

//-----------------------------------------------------------------------------
void SomeStaticObject::handleCollison(Ammo* ammo)
{
	ammo->handleCollison(this);
}

////-----------------------------------------------------------------------------