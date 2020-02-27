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
#include "button.h"

namespace gamespace
{

	class gameScreen: public screen
	{
	public:
		gameScreen(int windowWidth, int windowHeight);
		~gameScreen();
		void Init();
		void Update();
		void Draw();
		void Destroy();

	private:
		const int maxPadaros = 9;
		const int maxSfaira = 9;
		const float timeBetweenWaves = 3.f;
		float waveTimer;
		int liveEnemies;
		bool endgame;
		bool playerWon;

		thanatos* player;
		sprite* background;
		cursor* gameCursor;
		padaros* testPadaros;
		sfaira* testSfaira;

		button* retryButton;
		button* exitButton;

		waveManager* waveManagerInstance;

		Camera2D gameCamera;

		std::list<enemy*> enemyLayer;
		std::list<padaros*> availablePadaros;
		std::list<sfaira*> availableSfaira;
		std::list<rectangle*> wallLayer;

		Music gameMusic;
	};
}
#endif