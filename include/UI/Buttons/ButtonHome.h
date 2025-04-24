#pragma once
#include "Button.h"

class Controller;

class ButtonHome : public Button
{
private:
	Controller& m_controller;

public:
	void execute() const override;
	ButtonHome(sf::Vector2f pos, Controller&);

};