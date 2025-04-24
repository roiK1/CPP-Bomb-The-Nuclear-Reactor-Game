#pragma once
#include <sfml/Graphics.hpp>
#include "MoveStraight.h"
#include "DynamicObject.h"
#include "SomeStaticObject.h"
#include <iostream>

class Enemy;
class Player;
class Human;
class Shield;

class Ammo : public DynamicObject
{
public:
	Ammo(sf::Vector2f pos, const std::vector<sf::Texture>& textures,
		 float speed, std::unique_ptr<Movement> movement, int damage);
	virtual ~Ammo() = default;

	virtual void move(const sf::Vector2f& playerPos, const sf::Time& timePassed);
	virtual void handleCollison(Human* human);
	virtual void handleCollison(StaticObject* staticObject) override;
	virtual void handleCollison(SomeStaticObject* staticObject);
	virtual std::unique_ptr<Ammo> makeExplosion();

	bool getIsExits() const;
	bool getNeedToMakeExplosion() const;

	virtual void update(const sf::Time& timePassed) {};

protected:
	int m_damage;
	bool m_isExits,
		 m_makeExplotion;

};