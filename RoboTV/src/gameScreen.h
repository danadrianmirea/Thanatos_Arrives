#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "rectangle.h"

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
		rectangle* testRec;
	};
}
#endif