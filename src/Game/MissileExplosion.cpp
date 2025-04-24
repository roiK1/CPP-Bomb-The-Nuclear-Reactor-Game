#include "MissileExplosion.h"
#include "Human.h"

//-----------------------------------------------------------------------------
bool MissileExplosion::m_register = Factory::registerShoot(
	AmmoType::Explotion, [](const sf::Vector2f& pos)->unique_ptr<Ammo>
	{
		return std::make_unique<MissileExplosion>(pos);
	});

//-----------------------------------------------------------------------------
MissileExplosion::MissileExplosion(sf::Vector2f pos)
	: Ammo(pos , Textures::instance()->get(textureType::missileExplotion) ,
		   0 , nullptr , MISSILE_DAMAGE) ,
	 m_isAllreadyHurtedSomeOne(false)
{
	Sounds::instance()->playSounds(soundsType::missileExplotion);
}
//-----------------------------------------------------------------------------
void MissileExplosion::update(const sf::Time& timePassed)
{
	if (m_textureIndex == m_textures.size() - 1)
	{
		m_isExits = false;
		return;
	}
	updateTextureTimer(timePassed);
}
//-----------------------------------------------------------------------------
void MissileExplosion::handleCollison(Human* human)
{
	if (!m_isAllreadyHurtedSomeOne)
	{
		human->disqualification(MISSILE_EXPLOTION_DAMAGE);
		m_isAllreadyHurtedSomeOne = true;
	}
}
//-----------------------------------------------------------------------------
void MissileExplosion::handleCollison(StaticObject* staticObject)
{
}

//-----------------------------------------------------------------------------