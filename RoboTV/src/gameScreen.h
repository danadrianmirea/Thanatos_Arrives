#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"

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
	};
}
#endif