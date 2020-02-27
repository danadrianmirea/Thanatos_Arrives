#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <list>
#include <vector>

#include "padaros.h"
#include "sfaira.h"

namespace gamespace
{
	struct enemySpawn
	{
		enemyType enemyToSpawn;
		int spawnIndex;
	};

	struct wave
	{
		std::vector<enemySpawn> enemyList;
	};

	class waveManager
	{
	public:
		waveManager();
		~waveManager();
		void SpawnNextWave(std::list<padaros*> availablePadaros, std::list<sfaira*> availableSfaira);
		void ResetWaveIterator();
		int GetCurrentWaveEnemies();
		bool levelCleared;
		std::vector<Vector2> spawnList;
		std::list<wave> waveList;
	private:
		std::list<wave>::iterator waveIterator;
	};
}
#endif