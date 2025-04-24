#include "NuclearReactor.h"
#include "Player.h"

//-----------------------------------------------------------------------------
NuclearReactor::NuclearReactor(sf::Vector2f pos , int &score)
	:StaticObject(pos , Textures::instance()->get(textureType::nuclearReactor)),
	m_isBombPlanted(false) , m_gameScore(score)
{
    notifyObservers();
}

//-----------------------------------------------------------------------------
void NuclearReactor::handleCollison(Player* player)
{
    notifyObservers();
    if (player->isGotEnoughTNTForExplotion())
    {   
        player->useTNTsBombs();
        nextTextureIndex();
        updateTexture();

        if (!m_isBombPlanted)
        {
            m_gameScore += SCORE_PLANTED_BOMB;
            Sounds::instance()->playMusic(musicType::countDown);
        }

        m_isBombPlanted = true;
    }
}

//-----------------------------------------------------------------------------
void NuclearReactor::registerObserver(ObserverBombPlanted* observer)
{
    m_isBombPlantedObservers.push_back(observer);
}

//-----------------------------------------------------------------------------
void NuclearReactor::removeObserver(ObserverBombPlanted* pObserver)
{
    auto itObserverToErase = remove(m_isBombPlantedObservers.begin(), m_isBombPlantedObservers.end(), pObserver);
    m_isBombPlantedObservers.erase(itObserverToErase, m_isBombPlantedObservers.end());
}

//-----------------------------------------------------------------------------
void NuclearReactor::notifyObservers()
{
    for (auto observer : m_isBombPlantedObservers)
    {
        observer->UpdateIsBombPlanted(m_isBombPlanted);
    }
}

//-----------------------------------------------------------------------------