#include "PageTutorial.h"

PageTutorial::PageTutorial(Controller& controller)
	:Page(Textures::instance()->get(textureType::bgTutorial)[0], controller)
{
	sf::Vector2f buttonHomePos(100.f, 100.f);
	m_menu.add(std::make_unique<ButtonHome>(buttonHomePos, m_controller));
}

//-----------------------------------------------------------------------------
void PageTutorial::update()
{
	if (!Sounds::instance()->isPlaying(musicType::help))
	{
		Sounds::instance()->playMusic(musicType::help);
	}
}

//-----------------------------------------------------------------------------
void PageTutorial::closePage()
{
	Sounds::instance()->pauseMusic(musicType::help);
}

//-----------------------------------------------------------------------------
