#include "Enemy.h"
#include "Player.h"
#include "StaticObject.h"

//-----------------------------------------------------------------------------
Enemy::Enemy(	const sf::Vector2f& pos, unique_ptr<Movement> movement,
				AmmoType ammoName , unique_ptr<ShootInterface> ammoShoot, 
				float speed , const std::vector<sf::Texture>& textures,
				int& totalScore , int scoreAmount)
	:Human(pos, textures, speed, std::move(movement), INIT_ENEMY_SOLIDER_LIFES),
	 ScoreGiverObject(totalScore , scoreAmount)
{
	m_ammoManager.addAmmoType(ammoName, std::move(ammoShoot));
	m_object.scale(1.1,1.1);
}

//-----------------------------------------------------------------------------
Enemy::~Enemy()
{
	addScore();
}

//-----------------------------------------------------------------------------
void Enemy::update(const sf::Vector2f& playerPos, const sf::Time& timePassed ,
				   const sf::View& view)
{
	if (isPlayerInRange(view))
	{
		move(playerPos, timePassed);
		shoot(playerPos);
	}
	m_ammoManager.update(playerPos, timePassed);
}

//-----------------------------------------------------------------------------
bool Enemy::isPlayerInRange(const sf::View& view) const
{
	sf::FloatRect viewBounds = view.getViewport(); 
	sf::Vector2f viewCenter = view.getCenter();
	sf::Vector2f viewSize = view.getSize();

	sf::FloatRect viewRect(
		viewCenter.x - viewSize.x / 2,
		viewCenter.y - viewSize.y / 2,
		viewSize.x,
		viewSize.y
	);

	return viewRect.contains(getPos());
}

//-----------------------------------------------------------------------------
void Enemy::move(const sf::Vector2f& playerPos , const sf::Time& timePassed)
{
	auto movement = m_lastMovementAmount =
			m_movement->move(playerPos, getPos(),m_speed, timePassed.asSeconds());

	if (isValidMove(m_object.getPosition() + movement))
	{
		m_object.move(movement);
		if (movement != STAY)
		{
			updateTextureTimer(timePassed);
		}
	}
	animDirection(m_movement->getFaceDirection(playerPos, getPos()));
}

//-----------------------------------------------------------------------------
void Enemy::draw(sf::RenderWindow& window) const
{
	Object::draw(window);
	m_ammoManager.draw(window);
}

//-----------------------------------------------------------------------------
void Enemy::handleAmmoCollison(Player* player)
{
	m_ammoManager.handleCollison(player);
	m_ammoManager.handleCollison(player->getShield());
}

//-----------------------------------------------------------------------------
void Enemy::handleAmmoCollison(StaticObject* staticObject)
{
	m_ammoManager.handleCollison(staticObject);
}

//-----------------------------------------------------------------------------
void Enemy::handleCollison(StaticObject* staticObject)
{
	m_object.move(-m_lastMovementAmount);
	m_ammoManager.handleCollison(staticObject);
}

//-----------------------------------------------------------------------------
void Enemy::shoot(const sf::Vector2f& playerPos)
{
	if (m_ammoManager.getShootCooldownClock() > 5.f)
	{
		auto m_faceDirection = m_movement->getFaceDirection(playerPos, getPos());
		auto objectSize =m_object.getTexture()->getSize();

		m_ammoManager.shoot(sf::Vector2f(m_object.getPosition().x + objectSize.x/2 * m_faceDirection.x ,
                                     m_object.getPosition().y + objectSize.y/2 * m_faceDirection.y));
		m_ammoManager.resetShootCoolDownClock();
	}
}

//-----------------------------------------------------------------------------