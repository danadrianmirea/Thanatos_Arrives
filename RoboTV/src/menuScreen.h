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
		float gameVersion = 0.5;
	protected:
		const float buttonOffset = 100.f;
		cursor* gameCursor;
		std::list<button*> buttonList;
		buttonOptions currentOption;
		Music menuMusic;
		std::list<gameObject*> creditsObjectList;
		button* backFromCreditsButton;
		sprite* logo;
		bool showCredits;
	};
}
#endif