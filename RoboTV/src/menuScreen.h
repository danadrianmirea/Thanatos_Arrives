#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <list>

#include "screen.h"
#include "sprite.h"

#include "cursor.h"

namespace gamespace
{
	class menuScreen : public screen
	{
	public:
		menuScreen();
		~menuScreen();
		void Init();
		void Update();
		void Draw();
		void Destroy();
	protected:
		cursor* gameCursor;
		std::list<sprite> buttonList;
	};
}
#endif