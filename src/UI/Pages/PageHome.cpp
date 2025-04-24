#include "PageHome.h"

//-----------------------------------------------------------------------------
PageHome::PageHome(Controller& controller)
	:Page(Textures::instance()->get(textureType::bgHome)[0], controller)
{
	auto startPos = sf::Vector2f(WINDOW_WIDTH / 2.8, WINDOW_HIGH / 3);
	auto tutorialPos = sf::Vector2f(WINDOW_WIDTH / 2.8 + BUTTON_SIZE.x + 100.f, WINDOW_HIGH / 3);
	auto exitPos = sf::Vector2f(WINDOW_WIDTH / 2.8 +(BUTTON_SIZE.x + 100.f) * 2, WINDOW_HIGH / 3);
	m_menu.add(std::make_unique<ButtonExit>(exitPos));
	m_menu.add(std::make_unique<ButtonStartGame>(startPos , m_controller));
	m_menu.add(std::make_unique<ButtonTutorial>(tutorialPos, m_controller));
}

//-----------------------------------------------------------------------------
void PageHome::update()
{
	if (!Sounds::instance()->isPlaying(musicType::home))
	{
		Sounds::instance()->playMusic(musicType::home);
	}
}

//-----------------------------------------------------------------------------
void PageHome::closePage()
{
	Sounds::instance()->pauseMusic(musicType::home);
}

//-----------------------------------------------------------------------------

