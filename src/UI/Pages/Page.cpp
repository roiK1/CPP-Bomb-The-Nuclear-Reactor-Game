#include "Page.h"

//-----------------------------------------------------------------------------
Page::Page(const sf::Texture& texture , Controller& controller)
	:m_controller(controller)
{
	m_background.setTexture(texture);
}

//-----------------------------------------------------------------------------
void Page::draw(sf::RenderWindow& window) const
{
	window.draw(m_background);
	m_menu.draw(window);
}

//-----------------------------------------------------------------------------
void Page::handleMousePress(sf::Vector2i pos , sf::Mouse::Button buttonPressed)
{
	m_menu.performAction(pos);
}
//-----------------------------------------------------------------------------