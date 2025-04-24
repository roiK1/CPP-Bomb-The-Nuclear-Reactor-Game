#include "Controller.h"

//-----------------------------------------------------------------------------
Controller::Controller() :
	m_pageHome(*this),
	m_pageTutorial(*this),
	m_pageGame(*this , m_mainWindow),
	m_pageGameEnd(*this , &m_pageGame),
	m_currentPage(&m_pageHome)
{
	initWindow();
	m_defaultView = m_mainWindow.getDefaultView();
	std::srand(static_cast<unsigned>(std::time(nullptr)));
}

//-----------------------------------------------------------------------------
void Controller::changeToGamePage()
{
	m_currentPage->closePage();
	m_currentPage = &(m_pageGame);
}

//-----------------------------------------------------------------------------
void Controller::resetAndStartGame()
{
	m_currentPage->closePage();
	m_pageGame.resetGame(m_mainWindow);
	m_mainWindow.setView(m_defaultView);
	changeToGamePage();
}

//-----------------------------------------------------------------------------
void Controller::changeToTutorialPage()
{
	m_currentPage->closePage();
	m_currentPage = &(m_pageTutorial);
	m_mainWindow.setView(m_defaultView);
}

//-----------------------------------------------------------------------------
void Controller::changeToHomePage()
{
	m_currentPage->closePage();
	m_currentPage = &(m_pageHome);
	m_mainWindow.setView(m_defaultView);
}

//-----------------------------------------------------------------------------
void Controller::changeToGameEndPage(const std::string& status)
{
	m_currentPage->closePage();
	m_pageGameEnd.setEndGameStatus(status);
	m_currentPage = &(m_pageGameEnd);
	m_mainWindow.setView(m_defaultView);
}

//-----------------------------------------------------------------------------
const sf::View& Controller::getDefaultView() const
{
	return m_defaultView;
}

//-----------------------------------------------------------------------------
void Controller::initWindow()
{
	m_mainWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGH), "Mission: Bomb The Newclear Reactor",
						sf::Style::Default);
	m_mainWindow.setFramerateLimit(60);
}


//-----------------------------------------------------------------------------
void Controller::pollEvent()
{
	sf::Event current_event;
	while (m_mainWindow.pollEvent(current_event))
	{
		switch (current_event.type)
		{
		case sf::Event::Closed:
		{
			m_mainWindow.close();
			break;
		}
		case sf::Event::MouseButtonPressed:
			updateMousePosition();
			m_currentPage->handleMousePress(m_mousePosWindow , current_event.mouseButton.button);
			break;

		case sf::Event::KeyPressed:
			m_currentPage->handleKeyPress(current_event.key.code);
			break;

		case sf::Event::KeyReleased:
			m_currentPage->handleKeyReleased();
			break;
		}
	}

}

//-----------------------------------------------------------------------------
void Controller::run()
{

	while (m_mainWindow.isOpen())
	{
		m_mainWindow.clear();
		update();
		render();
		m_mainWindow.display();
	}
}

//-----------------------------------------------------------------------------
void Controller::update()
{
	pollEvent();
	m_currentPage->update();

}

//-----------------------------------------------------------------------------
void Controller::render()
{
	m_currentPage->draw(m_mainWindow);
}

//-----------------------------------------------------------------------------
void Controller::updateMousePosition()
{
	sf::Vector2i MousePosOnWindow = sf::Mouse::getPosition(m_mainWindow);
	m_mousePosWindow = sf::Vector2i(m_mainWindow.mapPixelToCoords(MousePosOnWindow));
}

//-----------------------------------------------------------------------------