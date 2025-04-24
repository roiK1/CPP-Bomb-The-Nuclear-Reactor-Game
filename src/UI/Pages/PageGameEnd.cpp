#include "PageGameEnd.h"

//-----------------------------------------------------------------------------
PageGameEnd::PageGameEnd(Controller& controller, PageGame* pageGame)
	:Page(Textures::instance()->get(textureType::bgGameEndedlose)[0], controller) ,
	 m_gameEndStatus("None") , m_pageGame(pageGame) , m_currMusicType(musicType::gameLose)
{
	sf::Vector2f buttonHomePos(WINDOW_WIDTH - 100.f, 100.f);
	sf::Vector2f buttonResetGamePos(WINDOW_WIDTH - 100.f, 250.f);

	m_menu.add(std::make_unique<ButtonHome>(buttonHomePos, m_controller));
	m_menu.add(std::make_unique<ButtonStartNewGame>(buttonResetGamePos, m_controller));
}

//-----------------------------------------------------------------------------
void PageGameEnd::closePage()
{
	Sounds::instance()->pauseMusic(m_currMusicType);
}

//-----------------------------------------------------------------------------
void PageGameEnd::update()
{
	
	m_gameEndStatus == "win" ? m_currMusicType = musicType::gameWin : m_currMusicType = musicType::gameLose;
	if (!Sounds::instance()->isPlaying(m_currMusicType))
	{
		Sounds::instance()->playMusic(m_currMusicType);
	}
}

//-----------------------------------------------------------------------------
void PageGameEnd::setEndGameStatus(std::string status)
{
	m_gameEndStatus = status;
	if (status == "win")
	{
		m_background.setTexture(Textures::instance()->get(textureType::bgGameEndedWin)[0]);
		setScoreText();
	}

	else if (status == "lose")
	{
		m_background.setTexture(Textures::instance()->get(textureType::bgGameEndedlose)[0]);
	}
}
//-----------------------------------------------------------------------------
void PageGameEnd::setScoreText()
{
	if (!m_font.loadFromFile("font.ttf"))
	{
		throw std::runtime_error("Failed to load font!");
	}
	m_scoreText.setFont(m_font);
	m_scoreText.setCharacterSize(72);
	m_scoreText.setFillColor(sf::Color::Green);
	m_scoreText.setString(std::to_string(m_pageGame->getCurrScore()));
	m_scoreText.setOrigin(0.f, 0.f);
	m_scoreText.setPosition(350.f, WINDOW_HIGH - 300.f);
}

//-----------------------------------------------------------------------------
void PageGameEnd::draw(sf::RenderWindow& window) const
{
	Page::draw(window);
	if (m_gameEndStatus == "win")
	{
		window.draw(m_scoreText);
	}

}
//-----------------------------------------------------------------------------