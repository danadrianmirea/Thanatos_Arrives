#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"

#include "thanatos.h"
#include "cursor.h"
#include "drone.h"
#include "attack.h"
#include "padaros.h"
#include "sfaira.h"
#include "waveManager.h"

namespace gamespace
{

	class gameScreen: public screen
	{
	public:
		gameScreen();
		~gameScreen();
		void Init();
		void Update();
		void Draw();
		void Destroy();

	private:
		const int maxPadaros = 9;
		const int maxSfaira = 9;

		thanatos* player;
		sprite* background;
		cursor* gameCursor;
		padaros* testPadaros;
		sfaira* testSfaira;

		waveManager* waveManagerInstance;

		Camera2D gameCamera;

		std::list<enemy*> enemyLayer;
		std::list<padaros*> availablePadaros;
		std::list<sfaira*> availableSfaira;
		std::list<rectangle*> wallLayer;
	};
}
#endif