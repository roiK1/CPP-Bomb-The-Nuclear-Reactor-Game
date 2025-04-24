#pragma once
 
class ObserverBombPlanted;

class IsBombPlantedOwner
{
public:

	virtual void registerObserver(ObserverBombPlanted* pObserver) = 0;

	virtual void removeObserver(ObserverBombPlanted* pObserver) = 0;

	virtual void notifyObservers() = 0;
};