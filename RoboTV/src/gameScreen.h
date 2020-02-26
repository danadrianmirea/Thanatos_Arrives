#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"

#include "thanatos.h"
#include "cursor.h"
#include "drone.h"
#include "attack.h"
#include "padaros.h"

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

		Camera2D gameCamera;

		std::list<gameObject*> enemyLayer;
		std::list<rectangle*> wallLayer;

	};
}
#endif