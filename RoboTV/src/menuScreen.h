#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <list>

#include "screen.h"
#include "sprite.h"
#include "button.h"
#include "cursor.h"

namespace gamespace
{
	class menuScreen : public screen
	{
	public:
		menuScreen(int windowWidth, int windowHeight);
		~menuScreen();
		void Init();
		void Update();
		void Draw();
		void Destroy();
	protected:
		const float buttonOffset = 100.f;
		cursor* gameCursor;
		std::list<button*> buttonList;
		buttonOptions currentOption;
	};
}
#endif