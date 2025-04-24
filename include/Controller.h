#pragma once

#include <sfml/Graphics.hpp>
#include "Menu.h"
#include "PageHome.h"
#include "PageGame.h"
#include "PageTutorial.h"
#include "PageGameEnd.h"
#include "Page.h"

class Controller
{
public:
	Controller();
	void changeToGamePage();
	void resetAndStartGame();
	void changeToTutorialPage();
	void changeToHomePage();
	void changeToGameEndPage(const std::string& status);
	const sf::View& getDefaultView() const;
	void run();

private:
	//window
	sf::RenderWindow m_mainWindow;
	PageHome m_pageHome;
	PageGame m_pageGame;
	PageTutorial m_pageTutorial;
	PageGameEnd m_pageGameEnd;
	Page* m_currentPage;

	sf::View m_defaultView;

	//mouse position
	sf::Vector2i m_mousePosWindow;

	void update();
	void render();

	void initWindow();

	void pollEvent();
	void updateMousePosition();
};