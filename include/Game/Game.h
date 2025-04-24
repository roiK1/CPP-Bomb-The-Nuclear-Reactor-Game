#pragma once
#include "Player.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "NuclearReactor.h"
#include "Factory.h"
#include "Ammo.h"
#include "PresentAddLife.h"
#include "GameInfo.h"
#include "ObserverBombPlanted.h"
#include "SomeStaticObject.h"
#include "PresentShield.h"
#include "PlayerRescueHelicopter.h"
#include "ObjectsPositions.h"

class Game : public ObserverBombPlanted
{
public:
	Game(GameInfo& gameInfo , sf::View& view);
	virtual ~Game() = default;

	void handleKeyPress(const sf::Keyboard::Key& keyPressed);
	void handleKeyReleased();
	void handleMousePress(sf::Mouse::Button keyPressed);

	void updateView();
	void update();
	void UpdateIsBombPlanted(bool isBombPlanted) override;
	void updateEnemies(const sf::Time& timePassed);
	void updateStaticObject();
	void updateGameInfo();

	int getCurrScore() const;

	void draw(sf::RenderWindow&) const;

	bool isGameEnded();
	bool isMissionSuccess();

private:
	sf::Clock m_movementClock, m_endGameClock , m_BombPlantedClock;

	//objects
	std::unique_ptr<Player> m_player;
	std::vector<unique_ptr<Enemy>> m_enemies;
	std::vector<unique_ptr<StaticObject>> m_staticObjects;
	unique_ptr<PlayerRescueHelicopter> m_rescueHelicopter;

	//data
	int m_gameScore;
	GameInfo& m_gameInfo;
	bool m_missionSuccess , m_bombPlantedState ;
	sf::View& m_view;

	void initObjects();
	void addFencesVertically(float x, float startY, int count);
	void addFencesHorizontally(float startX, float y, int count);
};
//-----------------------------------------------------------------------------

