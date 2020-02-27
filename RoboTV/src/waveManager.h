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
		void spawnNextWave(std::list<padaros*> availablePadaros, std::list<sfaira*> availableSfaira);
		bool levelCleared;
	private:
		std::vector<Vector2> spawnList;
		std::list<wave> waveList;
		std::list<wave>::iterator waveIterator;
	};
}
#endif