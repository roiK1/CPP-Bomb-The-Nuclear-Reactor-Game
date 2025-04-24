#include "GameInfo.h"
#include <stdexcept>
#include <string>

//-----------------------------------------------------------------------------
GameInfo::GameInfo()
    :   m_displayNuclearBombClock(false) , m_defaultPosNuclearBombTime(50, 20) ,
        m_defualtPosEndGameTime(50, 20) , m_defualtPosMissils(50, 140) , 
        m_defualtPosLives(50, 60), m_defualtPosScore(50, 100) ,
        m_defualtPosTNTs(50,180)
{
    if (!m_font.loadFromFile("font.ttf"))
    {
        throw std::runtime_error("Failed to load font!");
    }

    // Setup text objects with the font
    setupText(m_endGameTime, "Time Left: ", m_defualtPosEndGameTime);
    setupText(m_nuclearBombTime, "Nuclear Bomb In: " ,m_defaultPosNuclearBombTime);
    setupText(m_missils, "Missiles: ", m_defualtPosMissils);
    setupText(m_lives, "Lives: ", m_defualtPosLives);
    setupText(m_score, "Score: ", m_defualtPosScore);
    setupText(m_TNTs, "TNTs bombs: ", m_defualtPosTNTs);
}

//-----------------------------------------------------------------------------
void GameInfo::updateValues(int missiles, int lives, int score ,
                            float endGameTime, int TNTs , float nuclearBombTime)
{
    if (m_displayNuclearBombClock)
    {
        auto nuclearBombTimeMSS = to_MinutesAndSeconds(NUCLEAR_EXPLOTION_TIME - nuclearBombTime);
        m_nuclearBombTime.setString("Nuclear Bomb Time: " + nuclearBombTimeMSS);
    }
    auto endGameTimeMSS = to_MinutesAndSeconds(BASIC_GAME_END_TIME - endGameTime);
    m_endGameTime.setString("End Game Time: " + endGameTimeMSS);

    m_missils.setString("Missiles: " + std::to_string(missiles));
    setStringLife(lives);
    m_score.setString("Score: " + std::to_string(score));
    setStringTNTs(TNTs);
}

//-----------------------------------------------------------------------------
void GameInfo::setStringLife(int lives)
{
    m_lives.setString("Lives: " + std::to_string(lives));

    if (lives < (INIT_PLAYER_LIFES/3)) {
        m_lives.setFillColor(sf::Color::Red);
    }
    else if (lives <= (INIT_PLAYER_LIFES / 3)*2) {
        m_lives.setFillColor(sf::Color::Yellow);
    }
    else {
        m_lives.setFillColor(sf::Color::Green); 
    }
}

//-----------------------------------------------------------------------------
void GameInfo::setStringTNTs(int TNTs)
{
    m_TNTs.setString("TNTs bombs : " + std::to_string(TNTs));

    if (TNTs < MIN_TNT_BOMBS_FOR_EXPLOTION) {
        m_TNTs.setFillColor(sf::Color::White);
    }
    else if (TNTs >= MIN_TNT_BOMBS_FOR_EXPLOTION) {
        m_TNTs.setFillColor(sf::Color::Green);
    }
}

//-----------------------------------------------------------------------------
void GameInfo::draw(sf::RenderWindow& window) const
{
    if (m_displayNuclearBombClock)
    {
        window.draw(m_nuclearBombTime);
    }
    else
    {
        window.draw(m_endGameTime);
    }
    window.draw(m_missils);
    window.draw(m_lives);
    window.draw(m_score);
    window.draw(m_TNTs);
}

//-----------------------------------------------------------------------------
void GameInfo::updatePos(const sf::Vector2f& moveAmount)
{
    m_endGameTime.move(moveAmount);
    m_missils.move(moveAmount);
    m_lives.move(moveAmount);
    m_score.move(moveAmount);
    m_nuclearBombTime.move(moveAmount); 
    m_TNTs.move(moveAmount); 
}

//-----------------------------------------------------------------------------
void GameInfo::UpdateIsBombPlanted(bool isBombPlanted)
{
    m_displayNuclearBombClock = isBombPlanted;
    m_nuclearBombTime.setFillColor(sf::Color::Red);
    m_nuclearBombTime.setCharacterSize(30);
}

//-----------------------------------------------------------------------------
void GameInfo::setDefault()
{
    m_endGameTime.setPosition(m_defualtPosEndGameTime);
    m_missils.setPosition(m_defualtPosMissils);
    m_lives.setPosition(m_defualtPosLives);
    m_score.setPosition(m_defualtPosScore);
    m_TNTs.setPosition(m_defualtPosTNTs);
    m_nuclearBombTime.setPosition(m_defaultPosNuclearBombTime);
    m_displayNuclearBombClock = false;
}

//-----------------------------------------------------------------------------
void GameInfo::setupText(sf::Text& text, const std::string& str, sf::Vector2f pos)
{
    text.setFont(m_font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString(str);
    text.setOrigin(0.f, 0.f);  
    text.setPosition(pos.x, pos.y );
}

//-----------------------------------------------------------------------------
std::string GameInfo::to_MinutesAndSeconds(float seconds)
{
    int totalSeconds = static_cast<int>(seconds); 
    int minutes = totalSeconds / 60;               
    int remainingSeconds = totalSeconds % 60;      

    std::string formattedTime = std::to_string(minutes) + ":" +
        (remainingSeconds < 10 ? "0" : "") + std::to_string(remainingSeconds);

    return formattedTime;
}

//-----------------------------------------------------------------------------
