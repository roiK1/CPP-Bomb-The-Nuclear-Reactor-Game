#include "PresentAddMissile.h"
//-----------------------------------------------------------------------------
bool PresentAddMissile::m_register = Factory::registerPresent(
	[](const sf::Vector2f& pos, int& totalScore)->unique_ptr<Present>
	{
		return std::make_unique<PresentAddMissile>(pos , totalScore);
	});

//-----------------------------------------------------------------------------
PresentAddMissile::PresentAddMissile(const sf::Vector2f& pos, int& totalScore)
	:Present(pos ,Textures::instance()->get(textureType::presentAddMissile),
			 totalScore),
	 m_missileAmount(PRESENT_MISSILE_AMOUNT)
{}

//-----------------------------------------------------------------------------
void PresentAddMissile::handleCollison(Player* player)
{
	player->addMissile(m_missileAmount);
	Present::handleCollison(player);
}

//-----------------------------------------------------------------------------
