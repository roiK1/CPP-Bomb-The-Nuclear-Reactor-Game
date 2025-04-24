#pragma once
#include "Button.h"

class Controller;

class ButtonStartNewGame : public Button
{
private:
	Controller& m_controller;

public:
	ButtonStartNewGame(sf::Vector2f pos, Controller&);
	void execute() const override;
};