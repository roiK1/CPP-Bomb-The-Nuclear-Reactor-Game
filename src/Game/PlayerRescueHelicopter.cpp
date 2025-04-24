#include "PlayerRescueHelicopter.h"
#include "Factory.h"
#include "Player.h"

//-----------------------------------------------------------------------------
PlayerRescueHelicopter::PlayerRescueHelicopter(sf::Vector2f pos , 
								bool& missionSuccess , bool& isBombPlanted)
	:StaticObject(	pos ,
					Textures::instance()->get(textureType::RescueHelicopter)) ,
	 m_missionSuccess(missionSuccess) , m_isBombPlanted(isBombPlanted), 
	 m_isEscapeTime(false)
{
}

//-----------------------------------------------------------------------------
void PlayerRescueHelicopter::handleCollison(Player* player)
{
	if (m_isBombPlanted)
	{
		m_missionSuccess = true;
	}
}

//-----------------------------------------------------------------------------
void PlayerRescueHelicopter::update(const sf::Time& delta)
{
	updateTextureTimer(delta);
}

//-----------------------------------------------------------------------------