#pragma once
#include "Page.h"
#include "ButtonHome.h"
#include "ButtonStartNewGame.h"
#include "PageGame.h"

class PageGameEnd : public Page
{
private:
	sf::Font m_font;
	sf::Text m_scoreText;
	std::string m_gameEndStatus;
	PageGame* m_pageGame;
	void setScoreText();
	musicType m_currMusicType;

public:
	PageGameEnd(Controller& controller , PageGame* pageGame);
	~PageGameEnd() = default;
	
	void closePage() override;
	void update() override;
	void setEndGameStatus(std::string status);
	void draw(sf::RenderWindow& window) const override;
};	