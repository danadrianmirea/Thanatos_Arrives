#ifndef SCREEN_H
#define SCREEN_H

#include <list>

#include "raylib.h"

#include "gameObject.h"

namespace gamespace
{
	class screen
	{
	public:
		bool active;
		screen(int windowWidth, int windowHeight);
		~screen();
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;
		int exitNumber;
	protected:
		float elapsedScreenTime;
		int screenWidth;
		int screenHeight;
		std::list<gameObject*> gameObjectList;
		static bool mute;
		static void Mute(bool muteState);
		static bool IsMuted();
	};
}
#endif // !SCREEN_H