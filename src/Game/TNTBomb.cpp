#include "TNTBomb.h"
#include "Player.h"

//-----------------------------------------------------------------------------
TNTBomb::TNTBomb(sf::Vector2f pos)
	:StaticObject(pos, Textures::instance()->get(textureType::tntBomb))
{
	m_object.scale(0.7 , 0.7);
}

//-----------------------------------------------------------------------------
void TNTBomb::handleCollison(Player* player)
{
	player->handleCollison(this);
	m_isExists = false;
	Sounds::instance()->playSounds(soundsType::collectedSomething);
}

//-----------------------------------------------------------------------------