#include "Game.h"

//-----------------------------------------------------------------------------
Game::Game(GameInfo& gameInfo , sf::View& view)
	:m_gameInfo(gameInfo)  , m_gameScore(0) , m_missionSuccess(false) ,
	 m_bombPlantedState(false) , m_view(view)
{
	m_endGameClock.restart();
	initObjects();
}

//-----------------------------------------------------------------------------
void Game::handleKeyPress(const sf::Keyboard::Key& keyPressed)
{
	m_player->handleKeyPress(keyPressed);
}

//-----------------------------------------------------------------------------
void Game::handleKeyReleased()
{
	m_player->handleKeyReleased();
}

//-----------------------------------------------------------------------------
void Game::handleMousePress(sf::Mouse::Button keyPressed)
{
	m_player->handleMousePress(keyPressed);
}

//-----------------------------------------------------------------------------
void Game::updateView()
{
	m_player->updateView(m_view);
}

//-----------------------------------------------------------------------------
void Game::update()
{
	const sf::Time timePassed = m_movementClock.restart();
	m_player->update(timePassed);
	m_rescueHelicopter->update(timePassed);
	updateStaticObject();
	updateEnemies(timePassed);
	updateGameInfo();
}

//-----------------------------------------------------------------------------
void Game::UpdateIsBombPlanted(bool isBombPlanted)
{
	m_bombPlantedState = isBombPlanted;
	if (isBombPlanted)
	{
		m_BombPlantedClock.restart();
	}
}

//-----------------------------------------------------------------------------
void Game::updateEnemies(const sf::Time& timePassed)
{
	for (auto ItCurrEnemy = m_enemies.begin(); ItCurrEnemy != m_enemies.end(); )
	{
		if ((*ItCurrEnemy)->getIsDead())
		{
			ItCurrEnemy = m_enemies.erase(ItCurrEnemy);
		}
		else
		{
			for (auto ItCurrObject = m_staticObjects.begin(); ItCurrObject != m_staticObjects.end(); )
			{
				if ((*ItCurrEnemy)->checkCollison((*ItCurrObject).get()))
				{
					(*ItCurrEnemy)->handleCollison((*ItCurrObject).get());
				}
				(*ItCurrEnemy)->handleAmmoCollison((*ItCurrObject).get());
				++ItCurrObject;
			}

			(*ItCurrEnemy)->update(m_player->getPos(), timePassed, m_view);

			(*ItCurrEnemy)->handleAmmoCollison(m_player.get());
			m_player->handleAmmoCollison((*ItCurrEnemy).get());
			++ItCurrEnemy;
		}
	}
}

//-----------------------------------------------------------------------------
void Game::updateStaticObject()
{
	for (auto ItCurrObject = m_staticObjects.begin(); ItCurrObject != m_staticObjects.end(); )
	{
		if (!(*ItCurrObject)->getIsExists())
		{
			ItCurrObject = m_staticObjects.erase(ItCurrObject);
		}
		else
		{
			if (m_player->checkCollison((*ItCurrObject).get()))
			{
				m_player->handleCollison((*ItCurrObject).get());
			}
			m_player->handleAmmoCollison((*ItCurrObject).get());
			++ItCurrObject;
		}
	}
	if (m_rescueHelicopter->checkCollison(m_player.get()))
	{
		m_rescueHelicopter->handleCollison(m_player.get());
	}
}

//-----------------------------------------------------------------------------
void Game::updateGameInfo()
{
	m_gameInfo.updateValues(m_player->getNumOfMissiles(),
							m_player->getNumOfLives(), m_gameScore,
							m_endGameClock.getElapsedTime().asSeconds(),
							m_player->getNumOfTNTs(),
							m_BombPlantedClock.getElapsedTime().asSeconds());
}

//-----------------------------------------------------------------------------
int Game::getCurrScore() const
{
	return m_gameScore;
}

//-----------------------------------------------------------------------------
void Game::draw(sf::RenderWindow& window) const
{

	for (const auto& staticObject : m_staticObjects)
	{
		staticObject->draw(window);
	}

	m_player->draw(window);
	m_rescueHelicopter->draw(window);

	for (const auto& enemy : m_enemies)
	{
		enemy->draw(window);
	}

	m_gameInfo.draw(window);
}

//-----------------------------------------------------------------------------
bool Game::isGameEnded()
{
	float bombTime = m_BombPlantedClock.getElapsedTime().asSeconds() ,
		  endGameTime = m_endGameClock.getElapsedTime().asSeconds();
	bool bombExploadedOnPlayer = bombTime >= NUCLEAR_EXPLOTION_TIME && m_bombPlantedState,
		gameTimeEnded = endGameTime >= BASIC_GAME_END_TIME;

	return (bombExploadedOnPlayer || gameTimeEnded ||
			m_missionSuccess || m_player->getIsDead());
}

//-----------------------------------------------------------------------------
bool Game::isMissionSuccess()
{
	return m_missionSuccess;
}

//-----------------------------------------------------------------------------
void Game::initObjects()
{
	m_player = std::make_unique<Player>();

	auto nuclearReactor = Factory::createNuclearReactor(NUCLEAR_REACTOR_POS, m_gameScore);
	nuclearReactor->registerObserver(this);
	nuclearReactor->registerObserver(&m_gameInfo);
	m_staticObjects.emplace_back(std::move(nuclearReactor));

	addFencesHorizontally(65.f, 500.f , 42);
	addFencesHorizontally(65.f, 1500.f, 42);
	addFencesHorizontally(65.f, GAME_BG_HIGH - 65.f, 42);
	addFencesVertically(40.f, 565.f, 70);
	addFencesVertically(GAME_BG_WIDTH - 40, 565.f, 70);

	for (auto pos : TNT_POSITIONS)
	{
		m_staticObjects.emplace_back(Factory::createTNTBomb(pos));
	}

	for (int i = 0; i < 10; i++)
	{
		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(GAME_BG_WIDTH / 2 + 250.f * (i - 1), 200.f)));
	}

	for (int i = 0; i < 5; i++)
	{
		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(100.f + i * 245.f, 1590.f)));
		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(
			GAME_BG_WIDTH - 100.f - i * 245.f, 1590.f)));

		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(100.f + i * 245.f, 3419.f)));
		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(
			GAME_BG_WIDTH - 100.f - i * 245.f, 3419.f)));

		auto gate = Factory::createGate(sf::Vector2f(100.f + 4.8 * 245.f, 3380.f));
		m_staticObjects.emplace_back(Factory::createKey(KEY_POS, static_cast<Gate*>(gate.get())));
		m_staticObjects.emplace_back(std::move(gate));


		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(100.f + i * 245.f, 450.f)));
		m_staticObjects.emplace_back(Factory::createWall(sf::Vector2f(
			GAME_BG_WIDTH - 100.f - i * 245.f, 450.f)));
		if (i == 4)
		{
			float x = 100.f + i * 245.f + 100.f;
			for (int j = 1; j < 5; j++)
			{
				m_staticObjects.emplace_back(Factory::createTree(sf::Vector2f(x, 450.f - 50.f * j)));
				m_staticObjects.emplace_back(Factory::createTree(sf::Vector2f(x + 200.f, 450.f - 50.f * j)));
			}
		}
	}

	for (auto pos : treesPos)
	{
		m_staticObjects.emplace_back(Factory::createTree(pos));
	}

	for (auto pos : stonePos)
	{
		m_staticObjects.emplace_back(Factory::createStone(pos));
	}
	for (auto pos : fencePos)
	{
		m_staticObjects.emplace_back(Factory::createFence(pos));
	}
	for (auto pos : presentsPos)
	{
		m_staticObjects.emplace_back(Factory::createPresent(pos, m_gameScore));
	}

	for (auto pos : solidersPos)
	{
		m_enemies.emplace_back(Factory::createSolider(pos, m_gameScore));
	}

	for (auto pos : tanksPos)
	{
		m_enemies.emplace_back(Factory::createTank(pos, m_gameScore));
	}

	m_rescueHelicopter = Factory::createHelicopter(HELICOPTER_POS, m_missionSuccess, m_bombPlantedState);
}

//-----------------------------------------------------------------------------
void Game::addFencesHorizontally(float startX, float y, int count) {
	for (int i = 0; i < count; ++i) {
		m_staticObjects.emplace_back(Factory::createFence(sf::Vector2f(startX + i * 65.f, y)));
	}
}

//-----------------------------------------------------------------------------
void Game::addFencesVertically(float x, float startY, int count) {
	for (int i = 0; i < count; ++i) {
		m_staticObjects.emplace_back(Factory::createFence(sf::Vector2f(x, startY + i * 65.f)));
	}
}

//-----------------------------------------------------------------------------

