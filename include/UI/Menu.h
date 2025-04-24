#pragma once
#include <map>
#include <string>
#include "Button.h"

class Menu
{
public:
	Menu() = default;
	virtual ~Menu() =default;
	void add(std::unique_ptr<Button> button);
	void draw(sf::RenderWindow&) const;
	void performAction(sf::Vector2i pos);
	void updatePos(const sf::Vector2f& moveAmount);
	void setDefault();
private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};
