#pragma once
#include "Object.h"

class Player;
class Enemy;
class Ammo;
class Bullet;
class Missile;

class StaticObject : public Object
{
protected:
	bool m_isExists;

public:
	StaticObject(sf::Vector2f pos, const std::vector<sf::Texture>& textures);

	virtual ~StaticObject() = default;
	bool getIsExists() const;

	virtual void handleCollison(Player*) = 0;
	virtual void handleCollison(Ammo* ammo) {};
};