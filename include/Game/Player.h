#pragma once
#include "AmmoManager.h"
#include "Human.h"
#include "Consts.h"
#include "Shield.h"
#include "TNTBomb.h"
#include "Gate.h"
#include "Key.h"

class PlayerRescueHelicopter;

class Player : public Human
{
public:
	Player();
	~Player() = default;

	//setters
	void addMissile(int amount);

	//getters
	int getNumOfMissiles() const;
	int getNumOfLives() const;
	int getNumOfTNTs() const;
	bool isGotEnoughTNTForExplotion() const;

	void updateView(sf::View&);
	void move(const sf::Time&);
	void update(const sf::Time& timePassed);

	void handleCollison(StaticObject*) override;
	void handleCollison(PlayerRescueHelicopter* helicopter);
	void handleCollison(TNTBomb* TntBomb);
	void handleAmmoCollison(Enemy*);
	void handleAmmoCollison(StaticObject*);
	void handleKeyPress(const sf::Keyboard::Key& keyPressed);
	void handleKeyReleased();
	void handleMousePress(const sf::Mouse::Button& keyPressed);

	void shoot(AmmoType type);
	void draw(sf::RenderWindow& window) const;
	void shieldState();

	Shield* getShield();
	void useTNTsBombs();

private:
	int m_numOfMissils,
		m_numOfTNTBombs;

	sf::Vector2f m_moveDirection,
		//for ammo direction
		m_faceDirection;

	AmmoManager m_ammoManager;
	sf::Clock m_shootClock;
	float m_shootCooldownTime;
	bool m_isGotEnoughTNTBombs, m_isOnHelicopter;
	Shield m_shield;
};