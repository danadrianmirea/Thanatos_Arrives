#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"

#include "thanatos.h"
#include "cursor.h"
#include "drone.h"

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
		rectangle* testWall;
		cursor* gameCursor;
		drone* thanatosDrone;
		Camera2D gameCamera;

		std::list<gameObject*> enemyLayer;
		std::list<gameObject*> wallLayer;

	};
}
#endif