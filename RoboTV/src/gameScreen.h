#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "playerCharacter.h"

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
		animatedSprite* testSprite;
		playerCharacter* player;
		sprite* background;
		std::list<gameObject*> enemyLayer;
		std::list<gameObject*> wallLayer;

	};
}
#endif