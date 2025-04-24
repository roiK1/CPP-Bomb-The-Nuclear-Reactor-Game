#pragma once
#include "Page.h"
#include "Game.h"
#include "ButtonHome.h"

class PageGame : public Page
{
private:
	std::unique_ptr<Game> m_game;
	GameInfo m_gameInfo;
	sf::RenderWindow& m_window;
	sf::View m_view;

public:
	~PageGame() = default;
	PageGame(Controller& controller , sf::RenderWindow& window);

	void handleKeyPress(const sf::Keyboard::Key& keyPressed) override;
	void handleKeyReleased() override;
	void handleMousePress(sf::Vector2i pos, sf::Mouse::Button buttonPressed);
	void draw(sf::RenderWindow&) const override;
	void updateView();
	void update() override;
	void resetGame(sf::RenderWindow&);
	void closePage() override;
	int getCurrScore() const;

	template<typename T>
	void updatePositionAccordingToView(T& pageObject , const sf::View& oldView);
};

//-----------------------------------------------------------------------------
template<typename T>
void PageGame::updatePositionAccordingToView(T& pageObject, const sf::View& oldView)
{
	sf::Vector2f viewMoveAmount = m_view.getCenter() - oldView.getCenter();
	pageObject.updatePos(viewMoveAmount);
}

//-----------------------------------------------------------------------------