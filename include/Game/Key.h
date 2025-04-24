#pragma once
#include "StaticObject.h"


class Player;
class Gate;

class Key : public StaticObject
{
public:
	Key(sf::Vector2f pos , Gate* gate);
	~Key() = default;

	void handleCollison(Player*) override;

private:
	Gate* m_gate;
};