#pragma once
#include "StaticObject.h"
#include "IsBombPlantedOwner.h"
#include "ObserverBombPlanted.h"

class NuclearReactor : public StaticObject , public IsBombPlantedOwner 
{
public:
	NuclearReactor(sf::Vector2f pos, int& score);
	~NuclearReactor() = default;

	void handleCollison(Player*) override;

	//BombPlanted observer
	void registerObserver(ObserverBombPlanted* pObserver) override;
	void removeObserver(ObserverBombPlanted* pObserver) override;
	void notifyObservers() override;

private:
	bool m_isBombPlanted;
	std::vector<ObserverBombPlanted*> m_isBombPlantedObservers;
	int& m_gameScore;
};
