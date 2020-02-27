#include "waveManager.h"

namespace gamespace
{

	waveManager::waveManager()
	{
	}


	waveManager::~waveManager()
	{

	}

	void waveManager::SpawnNextWave(std::list<padaros*> availablePadaros, std::list<sfaira*> availableSfaira)
	{
		if (currentWave < waveList.size())
		{
			std::list<padaros*>::iterator padarosCounter = availablePadaros.begin();
			std::list<sfaira*>::iterator sfairaCounter = availableSfaira.begin();

			for (int i = 0; i < waveIterator->enemyList.size(); i++)
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
			currentWave++;
			waveIterator++;
		}
	}

	void waveManager::ResetWaveIterator()
	{
		waveIterator = waveList.begin();
		currentWave = 0;
	}
}