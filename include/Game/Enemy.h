#pragma once
#include "Object.h"
#include "Movement.h"
#include "ShootInterface.h"
#include "AmmoManager.h"
#include "Human.h"
#include "ScoreGiverObject.h"
#include <memory> 


class Player;

class Enemy : public Human , public ScoreGiverObject
{
private:
	AmmoManager m_ammoManager;

	void shoot(const sf::Vector2f& playerPos);
	bool isPlayerInRange(const sf::View& view) const;

public:
	Enemy(	const sf::Vector2f& pos, unique_ptr<Movement> movement,
			AmmoType ammoName, unique_ptr<ShootInterface> ammoShoot, float speed,
			const std::vector<sf::Texture>& textures, int& totalScore, int scoreAmount);
	~Enemy();

	void update(const sf::Vector2f& playerPos , const sf::Time& timePassed,
				const sf::View& view);
	void move(const sf::Vector2f& playerPos , const sf::Time& timePassed);
	void draw(sf::RenderWindow& window) const;
	void handleAmmoCollison(Player* player);
	void handleAmmoCollison(StaticObject* staticObject);
	void handleCollison(StaticObject*) override;
	void handleCollison(Present* present) {};
};