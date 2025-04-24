#include "Present.h"

//-----------------------------------------------------------------------------
Present::Present(sf::Vector2f pos, const std::vector<sf::Texture>& textures,
				 int& totalScore)
	:StaticObject(pos  , textures) , ScoreGiverObject(totalScore , SCORE_GIFT)
{
}

//-----------------------------------------------------------------------------
void Present::handleCollison(Player* player)
{
	m_isExists = false;
	addScore();
}

//-----------------------------------------------------------------------------
