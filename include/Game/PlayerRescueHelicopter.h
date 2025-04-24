#pragma once
#include "StaticObject.h"

class Player;

class PlayerRescueHelicopter : public StaticObject
{
public:
	PlayerRescueHelicopter(sf::Vector2f pos , bool& MissionSuccess , bool& isBombPlanted);
	~PlayerRescueHelicopter() = default;

	void handleCollison(Player*);
	void update(const sf::Time& delta);

private:
	bool &m_missionSuccess ,
		 &m_isBombPlanted , 
		 m_isEscapeTime;
};