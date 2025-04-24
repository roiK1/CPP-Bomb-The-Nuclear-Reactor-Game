#pragma once
#include "Present.h"

class PresentShield : public Present
{
private:
	static bool m_register;

public:
	PresentShield(const sf::Vector2f& pos, int& totalScore);
	virtual ~PresentShield() = default;
	virtual void handleCollison(Player*) override;
};