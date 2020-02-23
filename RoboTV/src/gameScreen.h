#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "thanatos.h"
#include "cursor.h"

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

		std::list<gameObject*> enemyLayer;
		std::list<gameObject*> wallLayer;

	};
}
#endif