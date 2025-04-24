#include "AmmoManager.h"
#include "Human.h"
//-----------------------------------------------------------------------------
AmmoManager::AmmoManager()
	:m_timePassedFromLastShoot(0.f) , m_currAmmo(AmmoType::None)
{
}

//-----------------------------------------------------------------------------
void AmmoManager::update(const sf::Vector2f& targetPos, const sf::Time& timePassed)
{
	m_timePassedFromLastShoot += timePassed.asSeconds();
    std::vector<std::unique_ptr<Ammo>> newExplosions;

    for (auto ItCurrAmmo = m_ammoFired.begin(); ItCurrAmmo != m_ammoFired.end(); )
    {
        (*ItCurrAmmo)->update(timePassed);

        if ((*ItCurrAmmo)->getNeedToMakeExplosion())
        {
            auto newAmmo = (*ItCurrAmmo)->makeExplosion();
            if (newAmmo)
            {
                newExplosions.emplace_back(std::move(newAmmo));
            }
        }

        if (!(*ItCurrAmmo)->getIsExits())
        {
            ItCurrAmmo = m_ammoFired.erase(ItCurrAmmo);
        }
        else
        {
            (*ItCurrAmmo)->move(targetPos, timePassed);
            ++ItCurrAmmo;
        }
    }

    m_ammoFired.insert(m_ammoFired.end(),
        std::make_move_iterator(newExplosions.begin()),
        std::make_move_iterator(newExplosions.end()));
}

//-----------------------------------------------------------------------------
void AmmoManager::shoot(const sf::Vector2f& ammoPos)
{
    if (!m_shoot.empty())
    {
        m_ammoFired.emplace_back(m_shoot[m_currAmmo]->shoot(ammoPos));
    }
}

//-----------------------------------------------------------------------------
float AmmoManager::getShootCooldownClock() const
{
	return m_timePassedFromLastShoot;
}

//-----------------------------------------------------------------------------
void AmmoManager::resetShootCoolDownClock()
{
	m_timePassedFromLastShoot = 0.f;
}

//-----------------------------------------------------------------------------
void AmmoManager::draw(sf::RenderWindow& window) const
{
	for (int ammo = 0; ammo < m_ammoFired.size(); ammo++)
	{
		m_ammoFired[ammo]->draw(window);
	}
}

//-----------------------------------------------------------------------------
void AmmoManager::changeAmmoType(AmmoType type)
{
    if (m_currAmmo != type)
    {
        m_currAmmo = type;
    }
}

//-----------------------------------------------------------------------------
void AmmoManager::addAmmoType(AmmoType type, std::unique_ptr<ShootInterface> shoot)
{
    m_shoot[type] = std::move(shoot);
    changeAmmoType(type);
}

//-----------------------------------------------------------------------------
void AmmoManager::handleCollison(StaticObject* staticObject)
{
    std::vector<std::unique_ptr<Ammo>> newExplosions;
    for (int ammo = 0; ammo < m_ammoFired.size(); ammo++)
    {
        if (m_ammoFired[ammo]->checkCollison(staticObject))
        {
            m_ammoFired[ammo]->handleCollison(staticObject);
            if (m_ammoFired[ammo]->getNeedToMakeExplosion())
            {
                auto newAmmo = m_ammoFired[ammo]->makeExplosion();
                if (newAmmo)
                {
                    newExplosions.emplace_back(std::move(newAmmo));
                }
            }
        }
    }
    m_ammoFired.insert(m_ammoFired.end(),
        std::make_move_iterator(newExplosions.begin()),
        std::make_move_iterator(newExplosions.end()));
}

//-----------------------------------------------------------------------------
