#pragma once
#include "Ammo.h"

class MissileExplosion : public Ammo
{
public:
	MissileExplosion(sf::Vector2f pos);
	virtual ~MissileExplosion() = default;

	void update(const sf::Time& timePassed) override;
	void handleCollison(Human* human) override;
	void handleCollison(StaticObject* staticObject) override;

private:
	static bool m_register;
	bool m_isAllreadyHurtedSomeOne;
};
