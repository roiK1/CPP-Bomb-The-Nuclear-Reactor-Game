#pragma once
#include "StaticObject.h"

class Shield : public StaticObject
{
private:
	static bool m_register;
	bool m_isActive;
	sf::Clock m_shieldClock;

public:
	Shield();
	virtual ~Shield() = default;
	void activation();
	void disable();
	bool isActive() const;
	void update(const sf::Vector2f& pos);
	virtual void handleCollison(Ammo* ammo) override;
	virtual void handleCollison(Player*) override {};
};