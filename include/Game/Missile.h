#pragma once
#include "Ammo.h"
#include "Movement.h"
#include "MissileExplosion.h"

class Missile : public Ammo 
{
public:
	Missile(const sf::Vector2f& pos);
	virtual ~Missile() = default;

	void handleCollison(Human* human) override;
	void handleCollison(StaticObject* staticObject) override;
	std::unique_ptr<Ammo> makeExplosion();
	void update(const sf::Time& timePassed) override;

private:
	static bool m_register;
	sf::Clock m_exploadTimer;
};
