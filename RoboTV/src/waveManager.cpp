#include "waveManager.h"

namespace gamespace
{

	waveManager::waveManager()
	{
		levelCleared = false;

		spawnList.push_back({ 0.f,0.f });
		spawnList.push_back({150.f, 200.f});
		spawnList.push_back({ -150.f, -200.f });
		spawnList.push_back({ 150.f, -200.f });



		wave wave0;
		wave0.enemyList.push_back({ padarosType, 0 });
		wave0.enemyList.push_back({ padarosType, 1 });
		wave0.enemyList.push_back({ padarosType, 2 });
		wave0.enemyList.push_back({ sfairaType, 0 });

		waveList.push_front(wave0);
		waveIterator = waveList.begin();
	}


	waveManager::~waveManager()
	{

	}

	void waveManager::spawnNextWave(std::list<padaros*> availablePadaros, std::list<sfaira*> availableSfaira)
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

}