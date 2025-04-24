#include "Button.h"

//-----------------------------------------------------------------------------
Button::Button(sf::Vector2f pos,  const std::vector<sf::Texture>& textures)
				:Object(pos , textures) , m_defaultPos(pos)
{
	m_object.setScale(2.f, 2.f);
}

//-----------------------------------------------------------------------------

bool Button::isPressed(const sf::Vector2i& pos) const
{
	return m_object.getGlobalBounds().contains((sf::Vector2f)pos);
}

//-----------------------------------------------------------------------------
void Button::move(const sf::Vector2f& moveAmount)
{
	m_object.move(moveAmount);
}

//-----------------------------------------------------------------------------
void Button::setDefaultPosition()
{
	m_object.setPosition(m_defaultPos);
}

//-----------------------------------------------------------------------------
