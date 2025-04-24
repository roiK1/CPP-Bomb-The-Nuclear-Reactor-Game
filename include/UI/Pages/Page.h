#pragma once
#include "Menu.h"
#include "Textures.h"

class Controller;

class Page
{
protected:
	Menu m_menu;
	Controller& m_controller;
	sf::Sprite m_background;

public:
	Page(const sf::Texture& texture, Controller&);
	virtual ~Page() = default;
	virtual void update() {};
	virtual void handleKeyPress(const sf::Keyboard::Key& keyPressed) {};
	virtual void handleKeyReleased() {};
	virtual void draw(sf::RenderWindow&) const;
	virtual void handleMousePress(sf::Vector2i pos , sf::Mouse::Button buttonPressed);
	virtual void closePage() {};
};
