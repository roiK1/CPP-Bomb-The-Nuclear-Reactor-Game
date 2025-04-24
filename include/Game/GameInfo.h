#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Consts.h"
#include "ObserverBombPlanted.h"

class GameInfo : public ObserverBombPlanted
{
public:
    GameInfo();
    ~GameInfo() = default;

    void updateValues(int missiles, int lives , int score,
                      float m_endGameTime, int TNTs ,float m_nuclearBombTime = 0);
    void setStringLife(int lives);
    void setStringTNTs(int lives);
    void draw(sf::RenderWindow& window) const;
    void updatePos(const sf::Vector2f& moveAmount);
    void UpdateIsBombPlanted(bool isBombPlanted) override;
    void setDefault();


private:
    void setupText(sf::Text& text, const std::string& str, sf::Vector2f pos);
    std::string to_MinutesAndSeconds(float seconds);

    sf::Text m_endGameTime,m_nuclearBombTime,
             m_missils, m_lives, m_score , m_TNTs;

    sf::Font m_font;

    bool m_displayNuclearBombClock;

    sf::Vector2f m_defualtPosEndGameTime , m_defaultPosNuclearBombTime,
             m_defualtPosMissils, m_defualtPosLives, m_defualtPosScore,
             m_defualtPosTNTs;
};
