#include "DynamicObject.h"

//-----------------------------------------------------------------------------
DynamicObject::DynamicObject(	sf::Vector2f pos ,float speed , 
								const std::vector<sf::Texture>& textures,
								std::unique_ptr<Movement> movement)
	:Object(pos , textures) , m_speed(speed) , m_movement(std::move(movement))
{

}

//-----------------------------------------------------------------------------
bool DynamicObject::isValidMove(const sf::Vector2f& wantedPos) const
{
	auto objectSize = m_object.getTexture()->getSize();
	if (wantedPos.x - objectSize.x/2 <= 0 || 
		wantedPos.x + objectSize.x/2 >= GAME_BG_WIDTH ||
		wantedPos.y - objectSize.y/2 <= 0 ||
		wantedPos.y + objectSize.y/2 >= GAME_BG_HIGH)
	{
		return false;
	}

	return true;
}

//-----------------------------------------------------------------------------
