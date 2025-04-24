#include "ButtonTutorial.h"
#include "Controller.h"
//-----------------------------------------------------------------------------
void ButtonTutorial::execute() const
{
	Sounds::instance()->playSounds(soundsType::buttonClick);
	m_controller.changeToTutorialPage();
}

//-----------------------------------------------------------------------------
ButtonTutorial::ButtonTutorial(sf::Vector2f pos, Controller& controller)
	:Button(pos, Textures::instance()->get(textureType::buttonTutorial)),
	m_controller(controller)
{
}

//-----------------------------------------------------------------------------