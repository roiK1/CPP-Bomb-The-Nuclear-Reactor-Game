#pragma once 
#include "StaticObject.h"
#include "Player.h"
#include "ScoreGiverObject.h"

class Present : public StaticObject , public ScoreGiverObject
{
public:
	Present(sf::Vector2f pos, const std::vector<sf::Texture>& textures,
			int& totalScore);
	virtual ~Present() = default;

	virtual void handleCollison(Player* player);

private:

};