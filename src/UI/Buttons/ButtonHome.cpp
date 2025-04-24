#include "ButtonHome.h"
#include "Controller.h"
//-----------------------------------------------------------------------------
void ButtonHome::execute() const
{
	Sounds::instance()->playSounds(soundsType::buttonClick);
	m_controller.resetAndStartGame();
	m_controller.changeToHomePage();

}

//-----------------------------------------------------------------------------
ButtonHome::ButtonHome(sf::Vector2f pos, Controller& controller)
	:Button(pos, Textures::instance()->get(textureType::buttonHome)),
	m_controller(controller)
{
}

//-----------------------------------------------------------------------------