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
		screen();
		~screen();
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	protected:
		float elapsedScreenTime;
		std::list<gameObject*> gameObjectList;
	};
}
#endif // !SCREEN_H