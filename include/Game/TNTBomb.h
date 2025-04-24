#pragma once
#include "StaticObject.h"


class Player;

class TNTBomb : public StaticObject
{
public:
	TNTBomb(sf::Vector2f pos);
	~TNTBomb() = default;

	void handleCollison(Player*) override;

private:
};