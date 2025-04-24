#pragma once
#include "Button.h"

class ButtonExit : public Button
{
private:

public:
	void execute() const override;
	ButtonExit(sf::Vector2f pos);

};