#pragma once
#include "Present.h"

class PresentAddMissile : public Present
{
private:
	static bool m_register;
	int m_missileAmount;
public:
	PresentAddMissile(const sf::Vector2f& pos, int& totalScore);
	virtual ~PresentAddMissile() = default;
	virtual void handleCollison(Player*) override;
};