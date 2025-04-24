#include "PresentShield.h"
//-----------------------------------------------------------------------------
bool PresentShield::m_register = Factory::registerPresent(
	[](const sf::Vector2f& pos, int& totalScore)->unique_ptr<Present>
	{
		return std::make_unique<PresentShield>(pos, totalScore);
	});

//-----------------------------------------------------------------------------
PresentShield::PresentShield(const sf::Vector2f& pos, int& totalScore)
	:Present(pos, Textures::instance()->get(textureType::presentShield),
			 totalScore)
{
}

//-----------------------------------------------------------------------------
void PresentShield::handleCollison(Player* player)
{
	Present::handleCollison(player);
	player->shieldState();
}

//-----------------------------------------------------------------------------
