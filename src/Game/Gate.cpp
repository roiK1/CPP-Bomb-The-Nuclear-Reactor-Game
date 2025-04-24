#include "Gate.h"
#include "Player.h"


//-----------------------------------------------------------------------------
Gate::Gate(sf::Vector2f pos)
	: StaticObject(pos, Textures::instance()->get(textureType::gate))
{
}

//-----------------------------------------------------------------------------
void Gate::openGate()
{
	m_isExists = false;
}

//-----------------------------------------------------------------------------
