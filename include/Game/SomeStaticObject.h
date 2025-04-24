#pragma once
#include "StaticObject.h"

class Player;
class Enemy;
class SomeStaticObject : public StaticObject
{
public:
	SomeStaticObject (sf::Vector2f pos, const std::vector<sf::Texture>& textures,
					  int resistance);
	~SomeStaticObject () = default;
	void handleCollison(Player* player) override {};
	void handleCollison(Ammo* ammo) override;
	void makeDamage(int damage);

private:
	int m_resistance;
};
