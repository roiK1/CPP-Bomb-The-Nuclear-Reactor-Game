#include "Human.h"
#include <iostream>

Human::Human(sf::Vector2f pos, const std::vector<sf::Texture>& textures,
			 float speed, std::unique_ptr<Movement> movement, int lives) 
	:DynamicObject(pos , speed, textures, std::move(movement)) ,
	 m_lives(lives) , m_lastMovementAmount(STAY)
{
	m_object.setScale(0.5f, 0.5f);
}

//-----------------------------------------------------------------------------
void Human::disqualification(int amount)
{
	Sounds::instance()->playSounds(soundsType::gotHurt);
	m_lives -= amount;
	if (m_lives < 0)
	{
		m_lives = 0;
	}
}

//-----------------------------------------------------------------------------
void Human::addLive(int amount)
{
	m_lives += amount;
}

//-----------------------------------------------------------------------------
bool Human::getIsDead() const
{
	return m_lives == 0;
}

//-----------------------------------------------------------------------------
void Human::animDirection(const sf::Vector2f dir)
{
	if (dir == UP)
	{
		m_object.setRotation(-90); 
	}
	else if (dir == DOWN)
	{
		m_object.setRotation(90); 
	}
	else if (dir == RIGHT)
	{
		m_object.setRotation(0);  
	}
	else if (dir == LEFT)
	{
		m_object.setRotation(180);
	}
	else if (dir == UP_RIGHT)
	{
		m_object.setRotation(-45); 
	}
	else if (dir == UP_LEFT)
	{
		m_object.setRotation(-135); 
	}
	else if (dir == DOWN_RIGHT)
	{
		m_object.setRotation(45);  
	}
	else if (dir == DOWN_LEFT)
	{
		m_object.setRotation(135);
	}

    updateTexture();
}

//-----------------------------------------------------------------------------

