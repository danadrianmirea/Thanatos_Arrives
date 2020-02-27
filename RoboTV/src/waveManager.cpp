#include "waveManager.h"

namespace gamespace
{

	waveManager::waveManager()
	{
		levelCleared = false;

		spawnList.push_back({ 0.f,0.f });
		
		wave wave0;
		wave0.enemyList.push_back({ padarosType, 0 });
		waveList.push_front(wave0);
		waveIterator = waveList.begin();
	}


	waveManager::~waveManager()
	{

	}

	void waveManager::spawnNextWave(std::list<padaros*> availablePadaros, std::list<sfaira*> availableSfaira) 
	{
		if (waveIterator != waveList.begin())
		{
			std::list<padaros*>::iterator padarosCounter = availablePadaros.begin();
			std::list<sfaira*>::iterator sfairaCounter = availableSfaira.begin();

			for (int i = waveIterator->enemyList.size(); i < waveIterator->enemyList.size(); i++)
			{
				int enemySpawnIndex = waveIterator->enemyList[i].spawnIndex;
				switch (waveIterator->enemyList[i].enemyToSpawn)
				{
				case padarosType:
					(*padarosCounter)->Activate(spawnList[enemySpawnIndex]);
					padarosCounter++;
					break;
				case sfairaType:
					(*sfairaCounter)->Activate(spawnList[enemySpawnIndex]);
					sfairaCounter++;
					break;
				}
			}

			waveIterator++;
		}
		else
		{
			levelCleared = true;
		}
	}

}