#include "ButtonStartGame.h"
#include "Controller.h"

//-----------------------------------------------------------------------------
void ButtonStartGame::execute() const
{
	Sounds::instance()->playSounds(soundsType::buttonClick);
	m_controller.changeToGamePage();
}

//-----------------------------------------------------------------------------
ButtonStartGame::ButtonStartGame(sf::Vector2f pos, Controller& controller)
	:Button(pos, Textures::instance()->get(textureType::buttonStartGame)),
	 m_controller(controller)
{
}

//-----------------------------------------------------------------------------