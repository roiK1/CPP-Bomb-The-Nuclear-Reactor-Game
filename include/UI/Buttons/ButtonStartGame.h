#pragma once
#include "Button.h"

class Controller;

class ButtonStartGame : public Button
{
private:
	Controller& m_controller;

public:
	void execute() const override;
	ButtonStartGame(sf::Vector2f pos , Controller&);

};