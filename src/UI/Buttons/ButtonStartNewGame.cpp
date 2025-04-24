#include "ButtonStartNewGame.h"
#include "Controller.h"

//-----------------------------------------------------------------------------
ButtonStartNewGame::ButtonStartNewGame(sf::Vector2f pos, Controller& controller)
	:Button(pos, Textures::instance()->get(textureType::buttonStartNewGame)),
	m_controller(controller)
{
}

//-----------------------------------------------------------------------------
void ButtonStartNewGame::execute() const
{
	Sounds::instance()->playSounds(soundsType::buttonClick);
	m_controller.resetAndStartGame();
}

//-----------------------------------------------------------------------------

