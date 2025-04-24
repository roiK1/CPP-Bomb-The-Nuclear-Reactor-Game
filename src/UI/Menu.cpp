#include "Menu.h"

//-----------------------------------------------------------------------------
void Menu::add(std::unique_ptr<Button> button)
{
	m_buttons.push_back(std::move(button));
}
	
//-----------------------------------------------------------------------------
void Menu::draw(sf::RenderWindow& window) const
{
	for (const auto& button : m_buttons)
	{
		button->draw(window);
	}
}

//-----------------------------------------------------------------------------
void Menu::performAction(sf::Vector2i pos)
{
	for (const auto& button : m_buttons)
	{
		if (button->isPressed(pos))
		{
			button->execute();
		}
	}
}

//-----------------------------------------------------------------------------
void Menu::updatePos(const sf::Vector2f& moveAmount)
{
	for (const auto& button : m_buttons)
	{
		button->move(moveAmount);
	}
}

//-----------------------------------------------------------------------------
void Menu::setDefault()
{
	for (const auto& button : m_buttons)
	{
		button->setDefaultPosition();
	}
}

//-----------------------------------------------------------------------------