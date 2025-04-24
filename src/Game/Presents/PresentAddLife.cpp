#include "PresentAddLife.h"

//-----------------------------------------------------------------------------
bool PresentAddLife::m_register = Factory::registerPresent(
	[](const sf::Vector2f& pos , int& totalScore)->unique_ptr<Present>
	{
		return std::make_unique<PresentAddLife>(pos , totalScore);
	});

//-----------------------------------------------------------------------------
PresentAddLife::PresentAddLife(const sf::Vector2f& pos, int& totalScore)
	:Present(pos , Textures::instance()->get(textureType::presentAddLife) ,
			 totalScore),
	m_lifeAmount(PRESENT_LIFE_AMOUNT)
{}

//-----------------------------------------------------------------------------
void PresentAddLife::handleCollison(Player* player)
{
	player->addLive(m_lifeAmount);
	Present::handleCollison(player);
}

//-----------------------------------------------------------------------------
