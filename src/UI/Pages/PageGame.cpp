#include "PageGame.h"
#include "Controller.h"

//-----------------------------------------------------------------------------
PageGame::PageGame(Controller& controller , sf::RenderWindow& window)
	:Page(Textures::instance()->get(textureType::bgGame)[0], controller),
	 m_window(window) ,m_game(nullptr),m_gameInfo()
{	
	sf::Vector2f buttonHomePos(WINDOW_WIDTH - 100.f , 100.f);
	sf::Vector2f buttonResetGamePos(WINDOW_WIDTH - 100.f , 250.f);

	m_menu.add(std::make_unique<ButtonHome>(buttonHomePos, m_controller));
	m_menu.add(std::make_unique<ButtonStartNewGame>(buttonResetGamePos, m_controller));

	m_view.setViewport(sf::FloatRect(0, 0, 1, 1));
	m_view.setSize(WINDOW_WIDTH, WINDOW_HIGH);
	m_view.setCenter(WINDOW_WIDTH / 2, WINDOW_HIGH / 2);
}

//-----------------------------------------------------------------------------
void PageGame::handleKeyPress(const sf::Keyboard::Key& keyPressed)
{
	m_game->handleKeyPress(keyPressed);
}

//-----------------------------------------------------------------------------
void PageGame::handleKeyReleased()
{
	m_game->handleKeyReleased();
}

//-----------------------------------------------------------------------------
void PageGame::handleMousePress(sf::Vector2i pos, sf::Mouse::Button buttonPressed)
{
	Page::handleMousePress(pos, buttonPressed);
	m_game->handleMousePress(buttonPressed);
}

//-----------------------------------------------------------------------------
void PageGame::draw(sf::RenderWindow& window) const
{
	window.draw(m_background);
	m_game->draw(window);
	m_menu.draw(window);
}

//-----------------------------------------------------------------------------
void PageGame::updateView()
{
	sf::View oldView = m_view;
	m_game->updateView();
	m_window.setView(m_view);
	updatePositionAccordingToView(m_menu , oldView);
	updatePositionAccordingToView(m_gameInfo , oldView);
}

//-----------------------------------------------------------------------------
void PageGame::update()
{	
	if (!Sounds::instance()->isPlaying(musicType::startGame))
	{
		Sounds::instance()->playMusic(musicType::startGame);
	}

	if (!m_game)
	{
		m_game = std::make_unique<Game>(m_gameInfo, m_view);
	}

	m_game->update();
	updateView();

	if (m_game->isGameEnded())
	{
		m_game->isMissionSuccess() ?
			m_controller.changeToGameEndPage("win") : m_controller.changeToGameEndPage("lose");
	}
}

//-----------------------------------------------------------------------------
void PageGame::resetGame(sf::RenderWindow& window )
{
	m_game = std::move(std::make_unique<Game>(m_gameInfo, m_view));
	m_view = m_controller.getDefaultView();
	m_window.setView(m_controller.getDefaultView());
	m_menu.setDefault();
	m_gameInfo.setDefault();
}

//-----------------------------------------------------------------------------
void PageGame::closePage()
{
	Sounds::instance()->pauseMusic(musicType::startGame);
	Sounds::instance()->pauseMusic(musicType::countDown);
}

//-----------------------------------------------------------------------------
int PageGame::getCurrScore() const
{
	return m_game->getCurrScore();
}

//-----------------------------------------------------------------------------




