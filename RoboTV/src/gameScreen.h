#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"

#include "thanatos.h"
#include "cursor.h"
#include "drone.h"
#include "attack.h"
#include "padaros.h"
#include "sfaira.h"

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

	private:
		thanatos* player;
		sprite* background;
		cursor* gameCursor;
		padaros* testPadaros;
		sfaira* testSfaira;

		Camera2D gameCamera;

		std::list<enemy*> enemyLayer;
		std::list<rectangle*> wallLayer;

	};
}
#endif