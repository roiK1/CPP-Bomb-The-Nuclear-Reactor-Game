#include "ButtonExit.h"

//-----------------------------------------------------------------------------
void ButtonExit::execute() const
{
	Sounds::instance()->playSounds(soundsType::buttonClick);
	exit(EXIT_SUCCESS);
}

//-----------------------------------------------------------------------------
ButtonExit::ButtonExit(sf::Vector2f pos)
	:Button(pos,Textures::instance()->get(textureType::buttonExit))
{
}

//-----------------------------------------------------------------------------