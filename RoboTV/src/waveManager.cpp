#include "waveManager.h"

namespace gamespace
{

	waveManager::waveManager()
	{
		levelCleared = false;
	}


	waveManager::~waveManager()
	{

	}

	void waveManager::SpawnNextWave(std::list<padaros*> availablePadaros, std::list<sfaira*> availableSfaira)
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
				std::printf("spawned Padaros");
				break;
			case sfairaType:
				(*sfairaCounter)->Activate(spawnList[enemySpawnIndex]);
				sfairaCounter++;
				std::printf("spawned Sfeira");
				break;
			}
		}

		waveIterator++;
	}

	void waveManager::ResetWaveIterator() 
	{
		waveIterator = waveList.begin();
	}

}