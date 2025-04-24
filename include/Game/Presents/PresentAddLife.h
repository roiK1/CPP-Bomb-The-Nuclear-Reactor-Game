#pragma once
#include "Present.h"

class PresentAddLife : public Present
{
private:
	static bool m_register;
	int m_lifeAmount;

public:
	PresentAddLife(const sf::Vector2f& pos , int& totalScore);
	virtual ~PresentAddLife() = default;

	virtual void handleCollison(Player*) override;
};