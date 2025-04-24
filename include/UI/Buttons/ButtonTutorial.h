#pragma once
#include "Button.h"

class Controller;

class ButtonTutorial : public Button
{
private:
	Controller& m_controller;

public:
	void execute() const override;
	ButtonTutorial(sf::Vector2f pos, Controller&);

};