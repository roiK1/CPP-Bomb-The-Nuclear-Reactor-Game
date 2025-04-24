#pragma once
#include "StaticObject.h"

class Player;
class Key;

class Gate : public StaticObject
{
public:
	Gate(sf::Vector2f pos);
	~Gate() = default;

	void handleCollison(Player* player) override {};
	void openGate();

private:
};
