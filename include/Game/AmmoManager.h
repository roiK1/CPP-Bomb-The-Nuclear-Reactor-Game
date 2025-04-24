#pragma once
#include "Ammo.h"
#include "ShootInterface.h"
#include <vector>

class Human;
class Shield;
class AmmoManager
{
public:
	AmmoManager();
	~AmmoManager() = default;

	void update(const sf::Vector2f& targetPos, const sf::Time& timePassed);
	void shoot(const sf::Vector2f& ammoPos);
	float getShootCooldownClock() const ;
	void resetShootCoolDownClock();
	void draw(sf::RenderWindow& window) const;

    template <typename T>
    void handleCollison(T*);

	void changeAmmoType(AmmoType type);
	void addAmmoType(AmmoType type, std::unique_ptr <ShootInterface> shoot);
	void handleCollison(StaticObject* staticObject);

private:
	std::vector<std::unique_ptr<Ammo>> m_ammoFired;
	std::map<AmmoType , std::unique_ptr<ShootInterface>> m_shoot;
	float m_timePassedFromLastShoot;
	AmmoType m_currAmmo;

};

//-----------------------------------------------------------------------------
template <typename T>
void AmmoManager::handleCollison(T* type)
{
    std::vector<std::unique_ptr<Ammo>> newExplosions;
    for (int ammo = 0; ammo < m_ammoFired.size(); ammo++)
    {
        if (m_ammoFired[ammo]->checkCollison(type))
        {
            m_ammoFired[ammo]->handleCollison(type);
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